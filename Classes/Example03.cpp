//<< 메뉴에 대하여 >>
/*

	메뉴를 사용하기 위해서는 단순하게 Menu클래스를 입력해두면 된다.
	그러나, 실질적으로 기능을 구현하기 위해서는 MenuItem을 addChild해야 한다.

	<< MenuItem 의 종류 >>
	1. MenuItemLabel
	2. MenuItemAtlasFont
	3. MenuItemFont *
	4. MenuItemSprite
	5. MenuItemImage *
	6. MenuItemToggle


*/

//콜벡함수 (Callback Function)
/*
	예시 CC_CALLBACK_1(Example03::doClick1,this);

	첫 번째인수( 셀렉터 ) : 메뉴가 선택됐을 때 호출되어야할 함수
	두 번째 인수( 타겟 ) : 메뉴 아이템이 선택됬을 때 반응해야하는 객체
						 this를 입력하면 메뉴가 생성된 현재 장면(Scene)을 참조


*/

#include "Example03.h"

USING_NS_CC;

cocos2d::Scene * Example03::createScene()
{
	return Example03::create();
}

bool Example03::init()
{
	if (!Scene::init())
	{
		return false;
	}

	//1. MenuItemImage를 사용하여 메뉴를 구축한다.
	{
		//menuUtemImage::create( idle이미지, select이미지, callback함수 )
		auto pMenuItem1 = MenuItemImage::create(
			"Icons/001.png",
			"Icons/002.png",
			CC_CALLBACK_1(Example03::doClick1, this));

		auto pMenuItem2 = MenuItemImage::create(
			"Icons/003.png",
			"Icons/004.png",
			CC_CALLBACK_1(Example03::doClick2, this));

		auto pMenuItem3 = MenuItemImage::create(
			"Icons/005.png",
			"Icons/006.png",
			CC_CALLBACK_1(Example03::doClick3, this));

		//Menu 제작
		auto pMenu = Menu::create(pMenuItem1, pMenuItem2, pMenuItem3, nullptr);
		pMenu->alignItemsHorizontallyWithPadding(24.0f);


		this->addChild(pMenu);


	}

	//2. setAnchorPoint와 setPosition 활용
	{
		auto pMenuItem1 = MenuItemImage::create(
			"Icons/001.png",
			"Icons/002.png",
			CC_CALLBACK_1(Example03::doClick1, this));

		//위치 선정
		pMenuItem1->setPosition(Vec2(1280, 720));
		pMenuItem1->setAnchorPoint(Vec2(1, 1));

		auto pMenu = Menu::create(pMenuItem1, nullptr);
		pMenu->setPosition(Vec2::ZERO);
		this->addChild(pMenu);

	}

	//3. MenuItemFont와 setTag method 사용
	{
		//사용할 폰트와 사이즈를 지정
		MenuItemFont::setFontName("fonts/NanumBarunGothic.ttf");
		MenuItemFont::setFontSize(48);

		//menuItemFont
		auto pMenuItem1 = MenuItemFont::create
		("활성화", CC_CALLBACK_1(Example03::doClick4, this));

		auto pMenuItem2 = MenuItemFont::create
		("비활성화", CC_CALLBACK_1(Example03::doClick4, this));


		//Tag설정
		pMenuItem1->setTag(1);
		pMenuItem2->setTag(2);

		//위치 설정 
		pMenuItem1->setPosition(Vec2(864, 400));
		pMenuItem2->setPosition(Vec2(864, 360));

		//메뉴
		auto pMenu = Menu::create(pMenuItem1, pMenuItem2, nullptr);
		pMenu->setPosition(Vec2::ZERO);
		this->addChild(pMenu);

	}


	return true;
}

void Example03::doClick1(Ref * pSender)
{
	int a = 1;
	log("%d 첫 번째 메뉴 클릭", a);


}

void Example03::doClick2(Ref * pSender)
{
	log("두 번째 메뉴 클릭");
}

void Example03::doClick3(Ref * pSender)
{
	log("세 번째 메뉴 클릭");
}

void Example03::doClick4(Ref * pSender)
{
	auto tagItem = (MenuItem*)pSender;
	int i = tagItem->getTag();

	log("%d 번째 메뉴가 선택됨", i);

	//4. Tag를 활용해서 스프라이트를 추가 제거
	if (i == 1)
	{
		this->removeChildByTag(10);
		auto pStrite = Sprite::create("priconne/mv_img_kyaru.png");
		pStrite->setPosition(Vec2(256, 360));
		pStrite->setTag(10);
		this->addChild(pStrite);
	}
	else
	{
		auto sprite = this->getChildByTag(10);

		//태크 검색이 완료되어 정보가 복사된 객체는 그 즉시 제거된다.
		this->removeChild(sprite, true);
		this->removeChildByTag(10);
	}

}
