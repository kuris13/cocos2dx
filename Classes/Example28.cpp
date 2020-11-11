#include "Example28.h"

cocos2d::Scene * Example28::createScene()
{
	return Example28::create();
}

bool Example28::init()
{
	if(!Scene::init()) return false;

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 joyPos = Vec2(visibleSize)*0.25f;

	//============================================================

	//조이스틱의 기본 정보를 담아둘 SneakyJoystickSkinnedBase 객체
	joystickBase = new SneakyJoystickSkinnedBase();
	joystickBase->init();
	joystickBase->setPosition(joyPos);
	joystickBase->setBackgroundSprite(Sprite::create("ui/joy1.png"));
	joystickBase->setThumbSprite(Sprite::create("ui/joy2.png"));
	joystickBase->autorelease();

	// 조작을 처리할 SneakyJoystick 객체
	aJoystick = new SneakyJoystick();
	aJoystick->initWithRect(Rect(0, 0, 160, 160));
	aJoystick->autorelease();

	// 조이스틱 세팅
	joystickBase->setJoystick(aJoystick);
	joystickBase->setPosition(joyPos);

	this->addChild(joystickBase);


	//============================================================

	Rect btnDimension = Rect(0, 0, 64, 64);
	Vec2 btnPos = Vec2(visibleSize.width * 0.8f, visibleSize.height * 0.2f);

	//============================================================

	//베이스
	buttonBase = new SneakyButtonSkinnedBase();
	buttonBase->init();
	buttonBase->setPosition(btnPos);
	buttonBase->setScale(3.0f, 1.5f);

	//속성
	buttonBase->setDefaultSprite(Sprite::create("ui/button.png"));
	buttonBase->setActivatedSprite(Sprite::create("ui/button.png"));
	buttonBase->setDisabledSprite(Sprite::create("ui/button.png"));
	buttonBase->setPressSprite(Sprite::create("ui/buttonHighlighted.png"));
	
	// 버튼
	aButton = new SneakyButton();
	aButton->initWithRect(btnDimension);
	aButton->autorelease();
	//눌렀을 때 계속 반응 ( 홀드가능 )
	aButton->setIsHoldable(true);
	
	// 버튼 세팅
	buttonBase->setButton(aButton);
	buttonBase->setPosition(btnPos);
	
	this->addChild(buttonBase);

	//==============================
	
	// 이벤트 처리를 위해서 추가 할당
	leftJoystick = joystickBase->getJoystick();
	leftJoystick->retain();

	attackButton = buttonBase->getButton();
	attackButton->retain();

	//==============================
	//스프라이트
	pSprite = Sprite::create("HelloWorld.png");
	pSprite->setPosition(Vec2(visibleSize) * 0.5f);
	this->addChild(pSprite);

	//스케줄
	this->schedule(schedule_selector(Example28::update));



	//==============================




	return true;
}

void Example28::update(float t)
{
	auto joyPos = leftJoystick->getStickPosition();

	//범위 값은 +- 120 정도
	if (joyPos.x < 60)
	{
		pSprite->setPositionX(pSprite->getPositionX() - 3);
	}
	else if (joyPos.x > -60)
	{
		pSprite->setPositionX(pSprite->getPositionX() + 3);
	}

	
	//버튼 이벤트 ( 리턴 타입은 bool )
	auto btn = attackButton->getValue();

	if (btn)
	{
		pSprite->setVisible(false);
	}
	else
	{
		pSprite->setVisible(true);
	}



}
