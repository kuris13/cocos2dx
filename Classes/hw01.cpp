#include "hw01.h"


#define aa "priconne/portraits/chara_01_02"
#include "audio/include/AudioEngine.h"
using namespace cocos2d::experimental;
USING_NS_CC;

cocos2d::Scene * hw01::createScene()
{
	return hw01::create();
}

bool hw01::init()
{
	if (!Scene::init())
	{
		return false;
	}

	//std::string aa = "priconne/portraits/chara_01_02";

	AudioEngine::preload("priconne/profileVoice/01_pecorinne.mp3");
	AudioEngine::preload("priconne/profileVoice/02_kokkoro.mp3");
	AudioEngine::preload("priconne/profileVoice/03_kyarl.mp3");

	auto bg = Sprite::create("priconne/backgrounds/@cha1.jpg");
	bg->setPosition(Vec2(640, 360));
	bg->setContentSize(Size(1280, 720));

	auto wBox = LayerColor::create(Color4B::WHITE);
	wBox->setOpacity(128);

	auto title = Sprite::create("priconne/h3-chara.png");
	title->setPosition(Vec2(640, 660));
	title->setTag(100);

	auto copyRight = Sprite::create("priconne/copyright.png");
	copyRight->setColor(Color3B::BLACK);
	copyRight->setPosition(Vec2(640, 24));

	auto chara01 = Sprite::create("priconne/portraits/chara_01_01.png");
	chara01->setPosition(Vec2(650, 340));
	chara01->setScale(0.8f);
	chara01->setTag(101);

	auto chara02 = Sprite::create((std::string)aa+".png");
	chara02->setPosition(Vec2(440, 330));
	chara02->setScale(0.8f);
	chara02->setTag(102);

	auto chara03 = Sprite::create("priconne/portraits/chara_01_03.png");
	chara03->setPosition(Vec2(884, 335));
	chara03->setScale(0.8f);
	chara03->setTag(103);
	

	auto mIChara01 = MenuItemImage::create(
		"priconne/btnVoices/btnVoice01_01.png",
		"priconne/btnVoices/btnVoice01_01.png",
		CC_CALLBACK_1(hw01::btnChara01, this));
	
	mIChara01->setPosition(chara01->getPosition().x-12, chara01->getPosition().y-96);
	mIChara01->setTag(1);

	auto mIChara02 = MenuItemImage::create(
		"priconne/btnVoices/btnVoice01_02.png",
		"priconne/btnVoices/btnVoice01_02.png",
		CC_CALLBACK_1(hw01::btnChara01, this));

	mIChara02->setPosition(chara02->getPosition().x -128, chara01->getPosition().y - 48);
	mIChara02->setTag(2);

	auto mIChara03 = MenuItemImage::create(
		"priconne/btnVoices/btnVoice01_03.png",
		"priconne/btnVoices/btnVoice01_03.png",
		CC_CALLBACK_1(hw01::btnChara01, this));

	mIChara03->setPosition(chara03->getPosition().x + 36, chara01->getPosition().y - 12);
	mIChara03->setTag(3);

	auto mChara = Menu::create(mIChara01, mIChara02, mIChara03, nullptr);
	mChara->setPosition(Vec2::ZERO);
	mChara->setTag(104);

	//레이어로 그룹화
	//auto layer = Layer::create();
	//layer->addChild(객체들)
	//this->addChild(layer, 1, 100);

	this->addChild(bg);
	this->addChild(wBox);
	this->addChild(title);
	this->addChild(copyRight);

	this->addChild(chara02);
	this->addChild(chara03);
	this->addChild(chara01);
	this->addChild(mChara);

	

	return true;
}

void hw01::btnChara01(Ref * pSender)
{
	for (int i = 0; i < 5; i++)
	{
		auto s1 = this->getChildByTag(100+i);
		s1->setVisible(false);
	}

	//pfOn -> 프로필 아무거나 isVisible을 사용하여서 대체 가능
	if (!pfOn)
	{
		pfOn = true;
		auto tagItem = (MenuItem*)pSender;
		int i = tagItem->getTag();

		auto fadeIn = FadeIn::create(1.0f);
		auto fadeOut = FadeOut::create(0);

		auto Action = Sequence::create(fadeOut, fadeIn, nullptr);

		auto pfBg = Sprite::create("priconne/profiles/bg.png");
		pfBg->setPosition(Vec2(640, 360));
		pfBg->setTag(0);
		pfBg->runAction(Action);

		this->addChild(pfBg);

		if (i == 1)
		{

			auto pfChara0101 = Sprite::create("priconne/profiles/cha01_01.png");
			pfChara0101->setPosition(Vec2(320, 388));
			pfChara0101->setScale(0.752f);
			pfChara0101->setTag(0);
			pfChara0101->runAction(Action->clone());

			auto pfChara0102 = Sprite::create("priconne/profiles/cha01_02.png");
			pfChara0102->setPosition(Vec2(840, 330));
			pfChara0102->setTag(0);
			pfChara0102->setScale(0.8f);
			pfChara0102->runAction(Action->clone());

			this->addChild(pfChara0101);
			this->addChild(pfChara0102);

		}
		else if (i == 2)
		{
			auto pfChara0101 = Sprite::create("priconne/profiles/cha02_01.png");
			pfChara0101->setPosition(Vec2(500, 615));
			pfChara0101->setTag(0);
			pfChara0101->runAction(Action->clone());

			auto pfChara0102 = Sprite::create("priconne/profiles/cha02_02.png");
			pfChara0102->setPosition(Vec2(1260, 540));
			pfChara0102->setTag(0);
			pfChara0102->runAction(Action->clone());

			this->addChild(pfChara0101);
			this->addChild(pfChara0102);
		}
		else if (i == 3)
		{
			auto pfChara0101 = Sprite::create("priconne/profiles/cha03_01.png");
			pfChara0101->setPosition(Vec2(500, 615));
			pfChara0101->setTag(0);
			pfChara0101->runAction(Action->clone());

			auto pfChara0102 = Sprite::create("priconne/profiles/cha03_02.png");
			pfChara0102->setPosition(Vec2(1260, 540));
			pfChara0102->setTag(0);
			pfChara0102->runAction(Action->clone());

			this->addChild(pfChara0101);
			this->addChild(pfChara0102);
		}

		auto mIPfClose = MenuItemImage::create(
			"priconne/close_btn.png",
			"priconne/close_btn2.png",
			CC_CALLBACK_1(hw01::btnCloseBtn, this));
		mIPfClose->setPosition(Vec2(1072, 600));

		auto mIPfVoice = MenuItemImage::create(
			"priconne/voice_btn2.png",
			"priconne/voice_btn3.png",
			CC_CALLBACK_1(hw01::btnVoiceBtn, this));
		mIPfVoice->setPosition(Vec2(1400, 250));
		mIPfVoice->setTag(i);

		auto mPf = Menu::create(mIPfClose, mIPfVoice, nullptr);
		mPf->setPosition(Vec2::ZERO);
		mPf->setTag(0);
		mPf->runAction(Action->clone());
		this->addChild(mPf);
	}
	
}

void hw01::btnCloseBtn(Ref * pSender)
{
	for (int i = 0; i < 4; i++)
	{
		this->removeChildByTag(0);
	}
	pfOn = false;

	for (int i = 0; i < 5; i++)
	{
		auto s1 = this->getChildByTag(100+i);
		s1->setVisible(true);
	}
	
}

void hw01::btnVoiceBtn(Ref * pSender)
{
	auto tagItem = (MenuItem*)pSender;
	int i = tagItem->getTag();

	if (i == 1)
	{
		auto voice1 = AudioEngine::play2d("priconne/profileVoice/01_pecorinne.mp3", false, 1.0f, nullptr);
	}
	else if (i == 2)
	{
		auto voice2 = AudioEngine::play2d("priconne/profileVoice/03_kayrl.mp3", false, 1.0f, nullptr);
	}
	else if (i == 3)
	{
		auto voice3 = AudioEngine::play2d("priconne/profileVoice/02_kokkoro.mp3", false, 1.0f, nullptr);
	}
	
}
