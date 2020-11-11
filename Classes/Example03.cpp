//<< �޴��� ���Ͽ� >>
/*

	�޴��� ����ϱ� ���ؼ��� �ܼ��ϰ� MenuŬ������ �Է��صθ� �ȴ�.
	�׷���, ���������� ����� �����ϱ� ���ؼ��� MenuItem�� addChild�ؾ� �Ѵ�.

	<< MenuItem �� ���� >>
	1. MenuItemLabel
	2. MenuItemAtlasFont
	3. MenuItemFont *
	4. MenuItemSprite
	5. MenuItemImage *
	6. MenuItemToggle


*/

//�ݺ��Լ� (Callback Function)
/*
	���� CC_CALLBACK_1(Example03::doClick1,this);

	ù ��°�μ�( ������ ) : �޴��� ���õ��� �� ȣ��Ǿ���� �Լ�
	�� ��° �μ�( Ÿ�� ) : �޴� �������� ���É��� �� �����ؾ��ϴ� ��ü
						 this�� �Է��ϸ� �޴��� ������ ���� ���(Scene)�� ����


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

	//1. MenuItemImage�� ����Ͽ� �޴��� �����Ѵ�.
	{
		//menuUtemImage::create( idle�̹���, select�̹���, callback�Լ� )
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

		//Menu ����
		auto pMenu = Menu::create(pMenuItem1, pMenuItem2, pMenuItem3, nullptr);
		pMenu->alignItemsHorizontallyWithPadding(24.0f);


		this->addChild(pMenu);


	}

	//2. setAnchorPoint�� setPosition Ȱ��
	{
		auto pMenuItem1 = MenuItemImage::create(
			"Icons/001.png",
			"Icons/002.png",
			CC_CALLBACK_1(Example03::doClick1, this));

		//��ġ ����
		pMenuItem1->setPosition(Vec2(1280, 720));
		pMenuItem1->setAnchorPoint(Vec2(1, 1));

		auto pMenu = Menu::create(pMenuItem1, nullptr);
		pMenu->setPosition(Vec2::ZERO);
		this->addChild(pMenu);

	}

	//3. MenuItemFont�� setTag method ���
	{
		//����� ��Ʈ�� ����� ����
		MenuItemFont::setFontName("fonts/NanumBarunGothic.ttf");
		MenuItemFont::setFontSize(48);

		//menuItemFont
		auto pMenuItem1 = MenuItemFont::create
		("Ȱ��ȭ", CC_CALLBACK_1(Example03::doClick4, this));

		auto pMenuItem2 = MenuItemFont::create
		("��Ȱ��ȭ", CC_CALLBACK_1(Example03::doClick4, this));


		//Tag����
		pMenuItem1->setTag(1);
		pMenuItem2->setTag(2);

		//��ġ ���� 
		pMenuItem1->setPosition(Vec2(864, 400));
		pMenuItem2->setPosition(Vec2(864, 360));

		//�޴�
		auto pMenu = Menu::create(pMenuItem1, pMenuItem2, nullptr);
		pMenu->setPosition(Vec2::ZERO);
		this->addChild(pMenu);

	}


	return true;
}

void Example03::doClick1(Ref * pSender)
{
	int a = 1;
	log("%d ù ��° �޴� Ŭ��", a);


}

void Example03::doClick2(Ref * pSender)
{
	log("�� ��° �޴� Ŭ��");
}

void Example03::doClick3(Ref * pSender)
{
	log("�� ��° �޴� Ŭ��");
}

void Example03::doClick4(Ref * pSender)
{
	auto tagItem = (MenuItem*)pSender;
	int i = tagItem->getTag();

	log("%d ��° �޴��� ���õ�", i);

	//4. Tag�� Ȱ���ؼ� ��������Ʈ�� �߰� ����
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

		//��ũ �˻��� �Ϸ�Ǿ� ������ ����� ��ü�� �� ��� ���ŵȴ�.
		this->removeChild(sprite, true);
		this->removeChildByTag(10);
	}

}
