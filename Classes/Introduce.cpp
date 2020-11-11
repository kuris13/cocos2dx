#include "Introduce.h"
#include "AudioEngine.h"
USING_NS_CC;
using namespace ui;
using namespace experimental;
cocos2d::Scene * Introduce::createScene()
{
	return Introduce::create();
}

bool Introduce::init()
{
	if (!Scene::init())
	{
		return false;
	}

	_soundVolume = 1.0f;

	AudioEngine::preload("priconne/bbb.mp3");

	audioId1 = AudioEngine::play2d("priconne/bbb.mp3", true, _soundVolume);


	//배경
	{
		//배경화면
		auto bgSprite = Sprite::create("priconne/backgrounds/@cha1.jpg");
		bgSprite->setContentSize(Size(1280, 720));
		bgSprite->setPosition(Vec2(640, 360));
		bgSprite->setTag(0);
		this->addChild(bgSprite);

		//배경화면 위에 덮어씌울 LayerColor
		auto wLayer = LayerColor::create(Color4B::WHITE);
		wLayer->setContentSize(Size(1280, 720));
		wLayer->setPosition(Vec2::ZERO);
		wLayer->setOpacity(128);
		wLayer->setTag(0);
		this->addChild(wLayer);

		//미식전 로고
		auto guildName = Sprite::create("priconne/h3chara.png");
		guildName->setPosition(Vec2(640, 660));
		guildName->setLocalZOrder(8);
		guildName->setTag(0);
		this->addChild(guildName);

		auto readChara = Sprite::create("priconne/chara-read.png");
		readChara->setPosition(Vec2(600, 360));
		readChara->setLocalZOrder(8);
		readChara->setTag(0);
		this->addChild(readChara);

		//저작권 표시
		auto copyright = Sprite::create("priconne/copyright.png");
		copyright->setColor(Color3B::BLACK);
		copyright->setPosition(Vec2(640, 24));
		copyright->setLocalZOrder(10);
		copyright->setTag(0);
		this->addChild(copyright);

		auto char1802 = Sprite::create("priconne/portraits/chara_18_02.png");
		char1802->setPosition(Vec2(1000, 150));
		char1802->setLocalZOrder(9);
		char1802->setTag(0);
		char1802->setScale(1.3f);
		this->addChild(char1802);
	}



	
	list = Sprite::create("priconne/guildList.png");
	list->setPosition(Vec2(200, 360));
	list->setScale(0.76f);
	//navi = Sprite::create("priconne/sideNavi.png");
	
	naviBtn = ui::Button::create("priconne/sideNavi.png");
	naviBtn->setPosition(Vec2(list->getPosition().x + 215, list->getPosition().y));
	naviBtn->addClickEventListener(CC_CALLBACK_1(Introduce::naviClick,this));
	
	TTFConfig ttfConfig("fonts/koverwatch.ttf", 40);
	
	listName = Label::createWithTTF(ttfConfig, "길드 목록");
	listName->setPosition(list->getPosition().x,list->getPosition().y+270);
	listName->setColor(Color3B::WHITE);
	
	
	auto sLayer = Layer::create();
	//sLayer->setColor(Color3B::RED);
	sLayer->setContentSize(Size(528, 600));
	sLayer->setPosition(list->getPosition());
	

	//사용할 폰트와 사이즈를 지정
	MenuItemFont::setFontName("fonts/koverwatch.ttf");
	MenuItemFont::setFontSize(24);
	
	//menuItemFont
	auto m1 = MenuItemFont::create
	("미식전", CC_CALLBACK_1(Introduce::menu1, this));
	m1->setPosition(Vec2(0,200));
	auto m2 = MenuItemFont::create
	("매르쿠리우스 재단", CC_CALLBACK_1(Introduce::menu2, this));
	m2->setPosition(Vec2(0, 100));
	auto m3 = MenuItemFont::create
	("바이스플뤼겔 랜드솔 지부", CC_CALLBACK_1(Introduce::menu3, this));
	m3->setPosition(Vec2(0, 0));

	auto pMenu = Menu::create(m1,m2,m3,nullptr);

	pMenu->setPosition(Vec2::ZERO);
	
	sLayer->addChild(pMenu);


	//스크롤 뷰 생성
	auto scrollView = ScrollView::create();

	//화면에 출력되는 크기 설정
	scrollView->setContentSize(Size(528*0.76, 500));

	// 스크롤 뷰 내부 레이어의 크기 설정
	scrollView->setInnerContainerSize(sLayer->getContentSize());

	// 스크롤 뷰 방향을 지정 
	scrollView->setDirection(ScrollView::Direction::VERTICAL);

	// 스크롤 뷰 탄성 효과 활성 여부 
	scrollView->setBounceEnabled(true);

	// 스크롤 바 자동 숨김 
	scrollView->setScrollBarAutoHideEnabled(true);

	// 스크롤 뷰의 시작 지점 정하기
	scrollView->jumpToPercentHorizontal(50.0f);

	//
	scrollView->addEventListener(CC_CALLBACK_2(Introduce::scrollEvent, this));


	// 컨텐츠 추가
	scrollView->addChild(sLayer);

	







	auto sideLayer = Layer::create();
	sideLayer->addChild(list);
	sideLayer->addChild(naviBtn);
	sideLayer->addChild(listName);
	//sideLayer->addChild(sLayer);
	sideLayer->addChild(scrollView);
	sideLayer->setPosition(Vec2(-528 * 0.76, 0));
	this->addChild(sideLayer, 2, 200);

	return true;
}

void Introduce::profilePecorinne(Ref * pSender)
{
	//캐릭터 선택 레이어 숨기기

	
	auto p = this->getChildByTag(100);
	p->setVisible(false);
	
	


	//프로필 배경화면
	auto profile_bg = Sprite::create("priconne/profiles/bg.png");
	profile_bg->setScale(0.75);
	profile_bg->setPosition(Vec2(640, 330));
	this->addChild(profile_bg);

	//페코린느 프로필 이미지
	auto pSprite1 = Sprite::create("priconne/profiles/cha01_01.png");
	pSprite1->setScale(0.752);
	pSprite1->setPosition(Vec2(320, 388));
	this->addChild(pSprite1);

	//페코린느 프로필 정보
	auto pSprite2 = Sprite::create("priconne/profiles/cha01_02.png");
	pSprite2->setScale(0.8);
	pSprite2->setPosition(Vec2(840, 330));
	this->addChild(pSprite2);

	//뒤로 가기 버튼
	auto btn = MenuItemImage::create("priconne/close_btn.png", "priconne/close_btn2.png", CC_CALLBACK_0(Introduce::btnCancel, this));
	btn->setPosition(Vec2(1072, 600));
	auto btnVoice = MenuItemImage::create("priconne/voice_btn2.png","priconne/voice_btn3.png",CC_CALLBACK_1(Introduce::btnVoice, this));
	btnVoice->setPosition(Vec2(950, 150));
	btnVoice->setTag(10);

	auto menu = Menu::create(btn,btnVoice, nullptr);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);



	//태그설정
	profile_bg->setTag(1);
	pSprite1->setTag(2);
	pSprite2->setTag(3);
	menu->setTag(4);


	//Show & FadeIn 연출 조합
	auto fadeout = FadeOut::create(0.0);
	auto show = Show::create();
	auto fadein = FadeIn::create(0.25);
	auto seq = Sequence::create(fadeout, show, fadein, nullptr);


	//각 스프라이트에 적용
	profile_bg->runAction(seq);
	pSprite1->runAction(seq->clone());
	pSprite2->runAction(seq->clone());
	menu->runAction(seq->clone());
}

void Introduce::profileKyarl(Ref * pSender)
{
	//캐릭터 선택 레이어 숨기기
	auto p = this->getChildByTag(100);
	p->setVisible(false);


	//프로필 배경화면
	auto profile_bg = Sprite::create("priconne/profiles/bg.png");
	profile_bg->setScale(0.75);
	profile_bg->setPosition(Vec2(640, 330));
	this->addChild(profile_bg);

	//캬루 프로필 이미지
	auto pSprite1 = Sprite::create("priconne/profiles/cha02_01.png");
	pSprite1->setScale(0.752);
	pSprite1->setPosition(Vec2(390, 354));
	this->addChild(pSprite1);

	//캬루 프로필 정보
	auto pSprite2 = Sprite::create("priconne/profiles/cha02_02.png");
	pSprite2->setScale(0.8);
	pSprite2->setPosition(Vec2(860, 330));
	this->addChild(pSprite2);

	//뒤로 가기 버튼
	auto btn = MenuItemImage::create("priconne/close_btn.png", "priconne/close_btn2.png", CC_CALLBACK_0(Introduce::btnCancel, this));
	btn->setPosition(Vec2(1072, 600));
	auto btnVoice = MenuItemImage::create("priconne/voice_btn2.png", "priconne/voice_btn3.png", CC_CALLBACK_1(Introduce::btnVoice, this));
	btnVoice->setPosition(Vec2(950, 150));
	btnVoice->setTag(11);

	auto menu = Menu::create(btn, btnVoice, nullptr);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);


	//태그설정
	profile_bg->setTag(1);
	pSprite1->setTag(2);
	pSprite2->setTag(3);
	menu->setTag(4);


	//Show & FadeIn 연출 조합
	auto fadeout = FadeOut::create(0.0);
	auto show = Show::create();
	auto fadein = FadeIn::create(0.25);
	auto seq = Sequence::create(fadeout, show, fadein, nullptr);


	//각 스프라이트에 적용
	profile_bg->runAction(seq);
	pSprite1->runAction(seq->clone());
	pSprite2->runAction(seq->clone());
	menu->runAction(seq->clone());
}

void Introduce::profileKokkoro(Ref * pSender)
{
	//캐릭터 선택 레이어 숨기기
	auto p = this->getChildByTag(100);
	p->setVisible(false);


	//프로필 배경화면
	auto profile_bg = Sprite::create("priconne/profiles/bg.png");
	profile_bg->setScale(0.75);
	profile_bg->setPosition(Vec2(640, 330));
	this->addChild(profile_bg);

	//콧코로 프로필 이미지
	auto pSprite1 = Sprite::create("priconne/profiles/cha03_01.png");
	pSprite1->setScale(0.752);
	pSprite1->setPosition(Vec2(450, 428));
	this->addChild(pSprite1);

	//콧코로 프로필 정보
	auto pSprite2 = Sprite::create("priconne/profiles/cha03_02.png");
	pSprite2->setScale(0.8);
	pSprite2->setPosition(Vec2(840, 330));
	this->addChild(pSprite2);

	//뒤로 가기 버튼
	auto btn = MenuItemImage::create("priconne/close_btn.png", "priconne/close_btn2.png", CC_CALLBACK_0(Introduce::btnCancel, this));
	btn->setPosition(Vec2(1072, 600));
	auto btnVoice = MenuItemImage::create("priconne/voice_btn2.png", "priconne/voice_btn3.png", CC_CALLBACK_1(Introduce::btnVoice, this));
	btnVoice->setPosition(Vec2(950, 150));
	btnVoice->setTag(12);

	auto menu = Menu::create(btn, btnVoice, nullptr);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);


	//태그설정
	profile_bg->setTag(1);
	pSprite1->setTag(2);
	pSprite2->setTag(3);
	menu->setTag(4);


	//Show & FadeIn 연출 조합
	auto fadeout = FadeOut::create(0.0);
	auto show = Show::create();
	auto fadein = FadeIn::create(0.25);
	auto seq = Sequence::create(fadeout, show, fadein, nullptr);


	//각 스프라이트에 적용
	profile_bg->runAction(seq);
	pSprite1->runAction(seq->clone());
	pSprite2->runAction(seq->clone());
	menu->runAction(seq->clone());
}

void Introduce::profile0201(Ref * pSender)
{
	//캐릭터 선택 레이어 숨기기
	auto p = this->getChildByTag(100);
	p->setVisible(false);


	//프로필 배경화면
	auto profile_bg = Sprite::create("priconne/profiles/bg.png");
	profile_bg->setScale(0.75);
	profile_bg->setPosition(Vec2(640, 330));
	this->addChild(profile_bg);

	//콧코로 프로필 이미지
	auto pSprite1 = Sprite::create("priconne/profiles/cha40_01.png");
	pSprite1->setScale(0.752);
	pSprite1->setPosition(Vec2(450, 428));
	this->addChild(pSprite1);

	//콧코로 프로필 정보
	auto pSprite2 = Sprite::create("priconne/profiles/cha40_02.png");
	pSprite2->setScale(0.8);
	pSprite2->setPosition(Vec2(840, 330));
	this->addChild(pSprite2);

	//뒤로 가기 버튼
	auto btn = MenuItemImage::create("priconne/close_btn.png", "priconne/close_btn2.png", CC_CALLBACK_0(Introduce::btnCancel, this));
	btn->setPosition(Vec2(1072, 600));
	auto btnVoice = MenuItemImage::create("priconne/voice_btn2.png", "priconne/voice_btn3.png", CC_CALLBACK_1(Introduce::btnVoice, this));
	btnVoice->setPosition(Vec2(950, 150));
	btnVoice->setTag(20);

	auto menu = Menu::create(btn, btnVoice, nullptr);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);


	//태그설정
	profile_bg->setTag(1);
	pSprite1->setTag(2);
	pSprite2->setTag(3);
	menu->setTag(4);


	//Show & FadeIn 연출 조합
	auto fadeout = FadeOut::create(0.0);
	auto show = Show::create();
	auto fadein = FadeIn::create(0.25);
	auto seq = Sequence::create(fadeout, show, fadein, nullptr);


	//각 스프라이트에 적용
	profile_bg->runAction(seq);
	pSprite1->runAction(seq->clone());
	pSprite2->runAction(seq->clone());
	menu->runAction(seq->clone());

}

void Introduce::profile0202(Ref * pSender)
{
	//캐릭터 선택 레이어 숨기기
	auto p = this->getChildByTag(100);
	p->setVisible(false);


	//프로필 배경화면
	auto profile_bg = Sprite::create("priconne/profiles/bg.png");
	profile_bg->setScale(0.75);
	profile_bg->setPosition(Vec2(640, 330));
	this->addChild(profile_bg);

	//콧코로 프로필 이미지
	auto pSprite1 = Sprite::create("priconne/profiles/cha41_01.png");
	pSprite1->setScale(0.752);
	pSprite1->setPosition(Vec2(450, 428));
	this->addChild(pSprite1);

	//콧코로 프로필 정보
	auto pSprite2 = Sprite::create("priconne/profiles/cha41_02.png");
	pSprite2->setScale(0.8);
	pSprite2->setPosition(Vec2(840, 330));
	this->addChild(pSprite2);

	//뒤로 가기 버튼
	auto btn = MenuItemImage::create("priconne/close_btn.png", "priconne/close_btn2.png", CC_CALLBACK_0(Introduce::btnCancel, this));
	btn->setPosition(Vec2(1072, 600));
	auto btnVoice = MenuItemImage::create("priconne/voice_btn2.png", "priconne/voice_btn3.png", CC_CALLBACK_1(Introduce::btnVoice, this));
	btnVoice->setPosition(Vec2(950, 150));
	btnVoice->setTag(21);

	auto menu = Menu::create(btn, btnVoice, nullptr);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);


	//태그설정
	profile_bg->setTag(1);
	pSprite1->setTag(2);
	pSprite2->setTag(3);
	menu->setTag(4);


	//Show & FadeIn 연출 조합
	auto fadeout = FadeOut::create(0.0);
	auto show = Show::create();
	auto fadein = FadeIn::create(0.25);
	auto seq = Sequence::create(fadeout, show, fadein, nullptr);


	//각 스프라이트에 적용
	profile_bg->runAction(seq);
	pSprite1->runAction(seq->clone());
	pSprite2->runAction(seq->clone());
	menu->runAction(seq->clone());
}

void Introduce::profile0203(Ref * pSender)
{
	//캐릭터 선택 레이어 숨기기
	auto p = this->getChildByTag(100);
	p->setVisible(false);


	//프로필 배경화면
	auto profile_bg = Sprite::create("priconne/profiles/bg.png");
	profile_bg->setScale(0.75);
	profile_bg->setPosition(Vec2(640, 330));
	this->addChild(profile_bg);

	//콧코로 프로필 이미지
	auto pSprite1 = Sprite::create("priconne/profiles/cha42_01.png");
	pSprite1->setScale(0.752);
	pSprite1->setPosition(Vec2(450, 428));
	this->addChild(pSprite1);

	//콧코로 프로필 정보
	auto pSprite2 = Sprite::create("priconne/profiles/cha42_02.png");
	pSprite2->setScale(0.8);
	pSprite2->setPosition(Vec2(840, 330));
	this->addChild(pSprite2);

	//뒤로 가기 버튼
	auto btn = MenuItemImage::create("priconne/close_btn.png", "priconne/close_btn2.png", CC_CALLBACK_0(Introduce::btnCancel, this));
	btn->setPosition(Vec2(1072, 600));
	auto btnVoice = MenuItemImage::create("priconne/voice_btn2.png", "priconne/voice_btn3.png", CC_CALLBACK_1(Introduce::btnVoice, this));
	btnVoice->setPosition(Vec2(950, 150));
	btnVoice->setTag(22);

	auto menu = Menu::create(btn, btnVoice, nullptr);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);


	//태그설정
	profile_bg->setTag(1);
	pSprite1->setTag(2);
	pSprite2->setTag(3);
	menu->setTag(4);


	//Show & FadeIn 연출 조합
	auto fadeout = FadeOut::create(0.0);
	auto show = Show::create();
	auto fadein = FadeIn::create(0.25);
	auto seq = Sequence::create(fadeout, show, fadein, nullptr);


	//각 스프라이트에 적용
	profile_bg->runAction(seq);
	pSprite1->runAction(seq->clone());
	pSprite2->runAction(seq->clone());
	menu->runAction(seq->clone());
}

void Introduce::profile0301(Ref * pSender)
{
	//캐릭터 선택 레이어 숨기기
	auto p = this->getChildByTag(100);
	p->setVisible(false);


	//프로필 배경화면
	auto profile_bg = Sprite::create("priconne/profiles/bg.png");
	profile_bg->setScale(0.75);
	profile_bg->setPosition(Vec2(640, 330));
	this->addChild(profile_bg);

	//콧코로 프로필 이미지
	auto pSprite1 = Sprite::create("priconne/profiles/cha52_01.png");
	pSprite1->setScale(0.752);
	pSprite1->setPosition(Vec2(450, 428));
	this->addChild(pSprite1);

	//콧코로 프로필 정보
	auto pSprite2 = Sprite::create("priconne/profiles/cha52_02.png");
	pSprite2->setScale(0.8);
	pSprite2->setPosition(Vec2(840, 330));
	this->addChild(pSprite2);

	//뒤로 가기 버튼
	auto btn = MenuItemImage::create("priconne/close_btn.png", "priconne/close_btn2.png", CC_CALLBACK_0(Introduce::btnCancel, this));
	btn->setPosition(Vec2(1072, 600));
	auto btnVoice = MenuItemImage::create("priconne/voice_btn2.png", "priconne/voice_btn3.png", CC_CALLBACK_1(Introduce::btnVoice, this));
	btnVoice->setPosition(Vec2(950, 150));
	btnVoice->setTag(30);

	auto menu = Menu::create(btn, btnVoice, nullptr);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);


	//태그설정
	profile_bg->setTag(1);
	pSprite1->setTag(2);
	pSprite2->setTag(3);
	menu->setTag(4);


	//Show & FadeIn 연출 조합
	auto fadeout = FadeOut::create(0.0);
	auto show = Show::create();
	auto fadein = FadeIn::create(0.25);
	auto seq = Sequence::create(fadeout, show, fadein, nullptr);


	//각 스프라이트에 적용
	profile_bg->runAction(seq);
	pSprite1->runAction(seq->clone());
	pSprite2->runAction(seq->clone());
	menu->runAction(seq->clone());
}

void Introduce::profile0302(Ref * pSender)
{
	//캐릭터 선택 레이어 숨기기
	auto p = this->getChildByTag(100);
	p->setVisible(false);


	//프로필 배경화면
	auto profile_bg = Sprite::create("priconne/profiles/bg.png");
	profile_bg->setScale(0.75);
	profile_bg->setPosition(Vec2(640, 330));
	this->addChild(profile_bg);

	//콧코로 프로필 이미지
	auto pSprite1 = Sprite::create("priconne/profiles/cha53_01.png");
	pSprite1->setScale(0.752);
	pSprite1->setPosition(Vec2(450, 428));
	this->addChild(pSprite1);

	//콧코로 프로필 정보
	auto pSprite2 = Sprite::create("priconne/profiles/cha53_02.png");
	pSprite2->setScale(0.8);
	pSprite2->setPosition(Vec2(840, 330));
	this->addChild(pSprite2);

	//뒤로 가기 버튼
	auto btn = MenuItemImage::create("priconne/close_btn.png", "priconne/close_btn2.png", CC_CALLBACK_0(Introduce::btnCancel, this));
	btn->setPosition(Vec2(1072, 600));
	auto btnVoice = MenuItemImage::create("priconne/voice_btn2.png", "priconne/voice_btn3.png", CC_CALLBACK_1(Introduce::btnVoice, this));
	btnVoice->setPosition(Vec2(950, 150));
	btnVoice->setTag(31);

	auto menu = Menu::create(btn, btnVoice, nullptr);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);


	//태그설정
	profile_bg->setTag(1);
	pSprite1->setTag(2);
	pSprite2->setTag(3);
	menu->setTag(4);


	//Show & FadeIn 연출 조합
	auto fadeout = FadeOut::create(0.0);
	auto show = Show::create();
	auto fadein = FadeIn::create(0.25);
	auto seq = Sequence::create(fadeout, show, fadein, nullptr);


	//각 스프라이트에 적용
	profile_bg->runAction(seq);
	pSprite1->runAction(seq->clone());
	pSprite2->runAction(seq->clone());
	menu->runAction(seq->clone());

}

void Introduce::profile0303(Ref * pSender)
{
	//캐릭터 선택 레이어 숨기기
	auto p = this->getChildByTag(100);
	p->setVisible(false);


	//프로필 배경화면
	auto profile_bg = Sprite::create("priconne/profiles/bg.png");
	profile_bg->setScale(0.75);
	profile_bg->setPosition(Vec2(640, 330));
	this->addChild(profile_bg);

	//콧코로 프로필 이미지
	auto pSprite1 = Sprite::create("priconne/profiles/cha54_01.png");
	pSprite1->setScale(0.752);
	pSprite1->setPosition(Vec2(450, 428));
	this->addChild(pSprite1);

	//콧코로 프로필 정보
	auto pSprite2 = Sprite::create("priconne/profiles/cha54_02.png");
	pSprite2->setScale(0.8);
	pSprite2->setPosition(Vec2(840, 330));
	this->addChild(pSprite2);

	//뒤로 가기 버튼
	auto btn = MenuItemImage::create("priconne/close_btn.png", "priconne/close_btn2.png", CC_CALLBACK_0(Introduce::btnCancel, this));
	btn->setPosition(Vec2(1072, 600));
	auto btnVoice = MenuItemImage::create("priconne/voice_btn2.png", "priconne/voice_btn3.png", CC_CALLBACK_1(Introduce::btnVoice, this));
	btnVoice->setPosition(Vec2(950, 150));
	btnVoice->setTag(32);

	auto menu = Menu::create(btn, btnVoice, nullptr);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);


	//태그설정
	profile_bg->setTag(1);
	pSprite1->setTag(2);
	pSprite2->setTag(3);
	menu->setTag(4);


	//Show & FadeIn 연출 조합
	auto fadeout = FadeOut::create(0.0);
	auto show = Show::create();
	auto fadein = FadeIn::create(0.25);
	auto seq = Sequence::create(fadeout, show, fadein, nullptr);


	//각 스프라이트에 적용
	profile_bg->runAction(seq);
	pSprite1->runAction(seq->clone());
	pSprite2->runAction(seq->clone());
	menu->runAction(seq->clone());
}

void Introduce::naviClick(Ref * pSender)
{
	if (!naviOn) {
		auto a = MoveTo::create(1.0f, Vec2(0, 0));

		auto aa = getChildByTag(200);
		aa->runAction(a);
		naviOn = !naviOn;


	}
	else {
		
		auto a = MoveTo::create(1.0f, Vec2(-528 * 0.76, 0));

		auto aa = getChildByTag(200);
		aa->runAction(a);
		naviOn = !naviOn;
	}
	
}

void Introduce::scrollEvent(Ref * pSender, cocos2d::ui::ScrollView::EventType event)
{
	switch (event)
	{
	case cocos2d::ui::ScrollView::EventType::SCROLL_TO_TOP:
		break;
	case cocos2d::ui::ScrollView::EventType::SCROLL_TO_BOTTOM:
		break;
	case cocos2d::ui::ScrollView::EventType::SCROLL_TO_LEFT:
		break;
	case cocos2d::ui::ScrollView::EventType::SCROLL_TO_RIGHT:
		break;
	case cocos2d::ui::ScrollView::EventType::SCROLLING:
		break;
	case cocos2d::ui::ScrollView::EventType::BOUNCE_TOP:
		break;
	case cocos2d::ui::ScrollView::EventType::BOUNCE_BOTTOM:
		break;
	case cocos2d::ui::ScrollView::EventType::BOUNCE_LEFT:
		break;
	case cocos2d::ui::ScrollView::EventType::BOUNCE_RIGHT:
		break;
	case cocos2d::ui::ScrollView::EventType::CONTAINER_MOVED:
		break;
	case cocos2d::ui::ScrollView::EventType::SCROLLING_BEGAN:
		break;
	case cocos2d::ui::ScrollView::EventType::SCROLLING_ENDED:
		break;
	case cocos2d::ui::ScrollView::EventType::AUTOSCROLL_ENDED:
		break;
	default:
		break;
	}
}



void Introduce::menu1(Ref * pSender)
{
	if (initScreen)
	{
		for (int i = 0; i < 6; i++)
		{
			removeChildByTag(0);
		}
		initScreen = false;
	}

	naviClick(pSender);

	for (int i = 0; i < 5; i++)
	{
		removeChildByTag(100+i);

	}
	
	//배경
	{
		//배경화면
		auto bgSprite = Sprite::create("priconne/backgrounds/@cha1.jpg");
		bgSprite->setContentSize(Size(1280, 720));
		bgSprite->setPosition(Vec2(640, 360));
		bgSprite->setTag(101);
		this->addChild(bgSprite);

		//배경화면 위에 덮어씌울 LayerColor
		auto wLayer = LayerColor::create(Color4B::WHITE);
		wLayer->setContentSize(Size(1280, 720));
		wLayer->setPosition(Vec2::ZERO);
		wLayer->setOpacity(128);
		wLayer->setTag(102);
	
		this->addChild(wLayer);

		//미식전 로고
		guildName = Sprite::create("priconne/guildNames/guildName1.png");
		guildName->setPosition(Vec2(640, 660));
		guildName->setZOrder(1);
		guildName->setOpacity(0);

		//저작권 표시
		auto copyright = Sprite::create("priconne/copyright.png");
		copyright->setColor(Color3B::BLACK);
		copyright->setPosition(Vec2(640, 24));
		copyright->setLocalZOrder(10);
		copyright->setTag(103);
		this->addChild(copyright);

	}



	//캐릭터 일러스트 (미식전) 
	{
		//페코린느
		illust[0] = Sprite::create("priconne/portraits/chara_01_01.png");
		illust[0]->setPosition(Vec2(650, 340));
		illust[0]->setScale(0.8);

		//캬루
		illust[1] = Sprite::create("priconne/portraits/chara_01_02.png");
		illust[1]->setPosition(Vec2(440, 330));
		illust[1]->setScale(0.8);
		illust[1]->setLocalZOrder(-1);

		//콧코로
		illust[2] = Sprite::create("priconne/portraits/chara_01_03.png");
		illust[2]->setPosition(Vec2(884, 335));
		illust[2]->setScale(0.85);
		illust[2]->setLocalZOrder(-1);
	}



	//메뉴 생성
	{
		//캐릭터 아이콘(MenuItemImage)로 메뉴 만들기
		Icons[0] = MenuItemImage::create(NAME_PECORINNE, NAME_PECORINNE, CC_CALLBACK_1(Introduce::profilePecorinne, this));
		Icons[1] = MenuItemImage::create(NAME_KOKKORO, NAME_KOKKORO, CC_CALLBACK_1(Introduce::profileKyarl, this));
		Icons[2] = MenuItemImage::create(NAME_KYARL, NAME_KYARL, CC_CALLBACK_1(Introduce::profileKokkoro, this));



		Icons[0]->setPosition(illust[0]->getPosition().x - 12, illust[0]->getPosition().y - 96);
		Icons[1]->setPosition(illust[1]->getPosition().x - 128, illust[1]->getPosition().y - 48);
		Icons[2]->setPosition(illust[2]->getPosition().x + 36, illust[2]->getPosition().y - 12);

		//메뉴 생성
		menu = Menu::create(Icons[0], Icons[1], Icons[2], nullptr);
		menu->setPosition(Vec2::ZERO);
	}



	//레이어로 묶기
	auto layer = Layer::create();
	layer->addChild(guildName);
	layer->addChild(illust[0]);
	layer->addChild(illust[1]);
	layer->addChild(illust[2]);
	layer->addChild(menu);
	this->addChild(layer, 1, 100);


	//================================================================


	//액션
	auto a = FadeOut::create(0.0);
	auto b = FadeIn::create(0.25);
	auto c = MoveBy::create(0.25, Vec2(30, 0));
	auto d = DelayTime::create(0.75);

	//일러스트
	auto imageSeq = Sequence::create(a, b, nullptr);
	illust[0]->runAction(imageSeq);
	illust[1]->runAction(imageSeq->clone());
	illust[2]->runAction(imageSeq->clone());

	//버튼
	auto moveSpa = Spawn::createWithTwoActions(c, b->clone());
	auto menuSeq = Sequence::create(a, b->clone(), moveSpa, nullptr);
	menu->runAction(menuSeq);

	//길드
	auto guildSeq = Sequence::create(a, d, b->clone(), nullptr);
	guildName->runAction(guildSeq);

}

void Introduce::menu2(Ref * pSender)
{
	if (initScreen)
	{
		for (int i = 0; i < 6; i++)
		{
			removeChildByTag(0);
		}
		initScreen = false;
	}

	naviClick(pSender);

	for (int i = 0; i < 5; i++)
	{
		removeChildByTag(100 + i);

	}
	//배경
	{
		//배경화면
		auto bgSprite = Sprite::create("priconne/backgrounds/@cha12.jpg");
		bgSprite->setContentSize(Size(1280, 720));
		bgSprite->setPosition(Vec2(640, 360));
		bgSprite->setTag(101);
		this->addChild(bgSprite);

		//배경화면 위에 덮어씌울 LayerColor
		auto wLayer = LayerColor::create(Color4B::WHITE);
		wLayer->setContentSize(Size(1280, 720));
		wLayer->setPosition(Vec2::ZERO);
		wLayer->setOpacity(128);
		wLayer->setTag(102);

		this->addChild(wLayer);

		//미식전 로고
		guildName = Sprite::create("priconne/guildNames/guildName12.png");
		guildName->setPosition(Vec2(640, 660));
		guildName->setZOrder(1);
		guildName->setOpacity(0);

		//저작권 표시
		auto copyright = Sprite::create("priconne/copyright.png");
		copyright->setColor(Color3B::BLACK);
		copyright->setPosition(Vec2(640, 24));
		copyright->setLocalZOrder(10);
		copyright->setTag(103);
		this->addChild(copyright);

	}



	//캐릭터 일러스트 (미식전) 
	{
		illust[0] = Sprite::create("priconne/portraits/chara_12_01.png");
		illust[0]->setPosition(Vec2(650, 340));
		illust[0]->setScale(0.8);

		illust[1] = Sprite::create("priconne/portraits/chara_12_02.png");
		illust[1]->setPosition(Vec2(440, 330));
		illust[1]->setScale(0.8);
		illust[1]->setLocalZOrder(-1);

		illust[2] = Sprite::create("priconne/portraits/chara_12_03.png");
		illust[2]->setPosition(Vec2(884, 335));
		illust[2]->setScale(0.85);
		illust[2]->setLocalZOrder(-1);

	}



	//메뉴 생성
	{
		//캐릭터 아이콘(MenuItemImage)로 메뉴 만들기
		Icons[0] = MenuItemImage::create("priconne/btnVoices/btnVoice12_01.png", "priconne/btnVoices/btnVoice12_01.png", CC_CALLBACK_1(Introduce::profile0201, this));
		Icons[1] = MenuItemImage::create("priconne/btnVoices/btnVoice12_02.png", "priconne/btnVoices/btnVoice12_02.png", CC_CALLBACK_1(Introduce::profile0202, this));
		Icons[2] = MenuItemImage::create("priconne/btnVoices/btnVoice12_03.png", "priconne/btnVoices/btnVoice12_03.png", CC_CALLBACK_1(Introduce::profile0203, this));



		Icons[0]->setPosition(illust[0]->getPosition().x - 12, illust[0]->getPosition().y - 96);
		Icons[1]->setPosition(illust[1]->getPosition().x - 128, illust[1]->getPosition().y - 48);
		Icons[2]->setPosition(illust[2]->getPosition().x + 36, illust[2]->getPosition().y - 12);

		//메뉴 생성
		menu = Menu::create(Icons[0], Icons[1], Icons[2], nullptr);
		menu->setPosition(Vec2::ZERO);
	}



	//레이어로 묶기
	auto layer = Layer::create();
	layer->addChild(guildName);
	layer->addChild(illust[0]);
	layer->addChild(illust[1]);
	layer->addChild(illust[2]);
	layer->addChild(menu);
	this->addChild(layer, 1, 100);


	//================================================================


	//액션
	auto a = FadeOut::create(0.0);
	auto b = FadeIn::create(0.25);
	auto c = MoveBy::create(0.25, Vec2(30, 0));
	auto d = DelayTime::create(0.75);

	//일러스트
	auto imageSeq = Sequence::create(a, b, nullptr);
	illust[0]->runAction(imageSeq);
	illust[1]->runAction(imageSeq->clone());
	illust[2]->runAction(imageSeq->clone());

	//버튼
	auto moveSpa = Spawn::createWithTwoActions(c, b->clone());
	auto menuSeq = Sequence::create(a, b->clone(), moveSpa, nullptr);
	menu->runAction(menuSeq);

	//길드
	auto guildSeq = Sequence::create(a, d, b->clone(), nullptr);
	guildName->runAction(guildSeq);

}

void Introduce::menu3(Ref * pSender)
{

	if (initScreen)
	{
		for (int i = 0; i < 6; i++)
		{
			removeChildByTag(0);
		}
		initScreen = false;
	}

	naviClick(pSender);

	for (int i = 0; i < 5; i++)
	{
		removeChildByTag(100 + i);

	}
	//배경
	{
		//배경화면
		auto bgSprite = Sprite::create("priconne/backgrounds/@cha15.jpg");
		bgSprite->setContentSize(Size(1280, 720));
		bgSprite->setPosition(Vec2(640, 360));
		bgSprite->setTag(101);
		this->addChild(bgSprite);

		//배경화면 위에 덮어씌울 LayerColor
		auto wLayer = LayerColor::create(Color4B::WHITE);
		wLayer->setContentSize(Size(1280, 720));
		wLayer->setPosition(Vec2::ZERO);
		wLayer->setOpacity(128);
		wLayer->setTag(102);

		this->addChild(wLayer);

		//미식전 로고
		guildName = Sprite::create("priconne/guildNames/guildName15.png");
		guildName->setPosition(Vec2(640, 660));
		guildName->setZOrder(1);
		guildName->setOpacity(0);

		//저작권 표시
		auto copyright = Sprite::create("priconne/copyright.png");
		copyright->setColor(Color3B::BLACK);
		copyright->setPosition(Vec2(640, 24));
		copyright->setLocalZOrder(10);
		copyright->setTag(103);
		this->addChild(copyright);

	}



	//캐릭터 일러스트 (미식전) 
	{
		illust[0] = Sprite::create("priconne/portraits/chara_15_01.png");
		illust[0]->setPosition(Vec2(650, 340));
		illust[0]->setScale(0.8);

		illust[1] = Sprite::create("priconne/portraits/chara_15_02.png");
		illust[1]->setPosition(Vec2(440, 330));
		illust[1]->setScale(0.8);
		illust[1]->setLocalZOrder(-1);

		illust[2] = Sprite::create("priconne/portraits/chara_15_03.png");
		illust[2]->setPosition(Vec2(884, 335));
		illust[2]->setScale(0.85);
		illust[2]->setLocalZOrder(-1);

	}



	//메뉴 생성
	{
		//캐릭터 아이콘(MenuItemImage)로 메뉴 만들기
		Icons[0] = MenuItemImage::create("priconne/btnVoices/btnVoice15_01.png", "priconne/btnVoices/btnVoice15_01.png", CC_CALLBACK_1(Introduce::profile0301, this));
		Icons[1] = MenuItemImage::create("priconne/btnVoices/btnVoice15_02.png", "priconne/btnVoices/btnVoice15_02.png", CC_CALLBACK_1(Introduce::profile0302, this));
		Icons[2] = MenuItemImage::create("priconne/btnVoices/btnVoice15_03.png", "priconne/btnVoices/btnVoice15_03.png", CC_CALLBACK_1(Introduce::profile0303, this));



		Icons[0]->setPosition(illust[0]->getPosition().x - 12, illust[0]->getPosition().y - 96);
		Icons[1]->setPosition(illust[1]->getPosition().x - 128, illust[1]->getPosition().y - 48);
		Icons[2]->setPosition(illust[2]->getPosition().x + 36, illust[2]->getPosition().y - 12);

		//메뉴 생성
		menu = Menu::create(Icons[0], Icons[1], Icons[2], nullptr);
		menu->setPosition(Vec2::ZERO);
	}



	//레이어로 묶기
	auto layer = Layer::create();
	layer->addChild(guildName);
	layer->addChild(illust[0]);
	layer->addChild(illust[1]);
	layer->addChild(illust[2]);
	layer->addChild(menu);
	this->addChild(layer, 1, 100);


	//================================================================


	//액션
	auto a = FadeOut::create(0.0);
	auto b = FadeIn::create(0.25);
	auto c = MoveBy::create(0.25, Vec2(30, 0));
	auto d = DelayTime::create(0.75);

	//일러스트
	auto imageSeq = Sequence::create(a, b, nullptr);
	illust[0]->runAction(imageSeq);
	illust[1]->runAction(imageSeq->clone());
	illust[2]->runAction(imageSeq->clone());

	//버튼
	auto moveSpa = Spawn::createWithTwoActions(c, b->clone());
	auto menuSeq = Sequence::create(a, b->clone(), moveSpa, nullptr);
	menu->runAction(menuSeq);

	//길드
	auto guildSeq = Sequence::create(a, d, b->clone(), nullptr);
	guildName->runAction(guildSeq);

}

void Introduce::btnCancel()
{
	//캐릭터 선택 레이어 표시
	auto p = this->getChildByTag(100);
	p->setVisible(true);

	//프로필 삭제
	this->removeChildByTag(1);
	this->removeChildByTag(2);
	this->removeChildByTag(3);
	this->removeChildByTag(4);
}

void Introduce::btnVoice(Ref * pSender)
{
	auto tagItem = (MenuItem*)pSender;
	int i = tagItem->getTag();

	if (i == 10)
	{
		if (AudioEngine::getState(audioId2) == AudioEngine::AudioState::PLAYING)
		{
			AudioEngine::stop(audioId2);
		}

		audioId2 = AudioEngine::play2d("priconne/profileVoice/01_pecorinne.mp3", false, 1.0f, nullptr);
	}
	else if (i == 11)
	{
		if (AudioEngine::getState(audioId2) == AudioEngine::AudioState::PLAYING)
		{
			AudioEngine::stop(audioId2);
		}
		audioId2 = AudioEngine::play2d("priconne/profileVoice/03_kyarl.mp3", false, 1.0f, nullptr);
	}
	else if (i == 12)
	{
		if (AudioEngine::getState(audioId2) == AudioEngine::AudioState::PLAYING)
		{
			AudioEngine::stop(audioId2);
		}
		audioId2 = AudioEngine::play2d("priconne/profileVoice/02_kokkoro.mp3", false, 1.0f, nullptr);
	}
	else if (i == 20)
	{
		if (AudioEngine::getState(audioId2) == AudioEngine::AudioState::PLAYING)
		{
			AudioEngine::stop(audioId2);
		}

		audioId2 = AudioEngine::play2d("priconne/profileVoice/04.mp3", false, 1.0f, nullptr);
	}
	else if (i == 21)
	{
		if (AudioEngine::getState(audioId2) == AudioEngine::AudioState::PLAYING)
		{
			AudioEngine::stop(audioId2);
		}
		audioId2 = AudioEngine::play2d("priconne/profileVoice/05.mp3", false, 1.0f, nullptr);
	}
	else if (i == 22)
	{
		if (AudioEngine::getState(audioId2) == AudioEngine::AudioState::PLAYING)
		{
			AudioEngine::stop(audioId2);
		}
		audioId2 = AudioEngine::play2d("priconne/profileVoice/06.mp3", false, 1.0f, nullptr);
	}
	else if (i == 30)
	{
		if (AudioEngine::getState(audioId2) == AudioEngine::AudioState::PLAYING)
		{
			AudioEngine::stop(audioId2);
		}

		audioId2 = AudioEngine::play2d("priconne/profileVoice/07.mp3", false, 1.0f, nullptr);
	}
	else if (i == 31)
	{
		if (AudioEngine::getState(audioId2) == AudioEngine::AudioState::PLAYING)
		{
			AudioEngine::stop(audioId2);
		}
		audioId2 = AudioEngine::play2d("priconne/profileVoice/08.mp3", false, 1.0f, nullptr);
	}
	else if (i == 32)
	{
		if (AudioEngine::getState(audioId2) == AudioEngine::AudioState::PLAYING)
		{
			AudioEngine::stop(audioId2);
		}
		audioId2 = AudioEngine::play2d("priconne/profileVoice/09.mp3", false, 1.0f, nullptr);
	}
}
