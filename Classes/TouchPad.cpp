#include "TouchPad.h"

USING_NS_CC;

cocos2d::Scene * TouchPad::createScene()
{
	auto scene = Scene::create();
	auto layer = TouchPad::create();
	scene->addChild(layer);
	return scene;
}

bool TouchPad::init()
{
	if (!Layer::init())
	{
		return false;
	}

	//화면 사이즈
	auto visibleSize = Director::getInstance()->getVisibleSize();


	//조이스틱의 위치
	Point joyPosition = Point(visibleSize * 0.25f);

	
	//조이스틱의 기본 정보를 담을 SneakyJoystickSkinnedBase 객체
	joystickBase = new SneakyJoystickSkinnedBase();
	joystickBase->init();
	joystickBase->setPosition(joyPosition);
	joystickBase->setBackgroundSprite(Sprite::create("joy1.png"));
	joystickBase->setThumbSprite(Sprite::create("joy2.png"));

	//터치 이벤트를 처리할 SneakyJoystick 객체
	aJoystick = new SneakyJoystick();
	aJoystick->initWithRect(Rect(0, 0, 160.0f, 160.0f));
	aJoystick->autorelease();

	//조이스틱 세팅
	joystickBase->setJoystick(aJoystick);
	joystickBase->setPosition(joyPosition);

	//세팅한 조이스틱의 정보를 받아오기
	leftJoystick = joystickBase->getJoystick();
	leftJoystick->retain();
	this->addChild(joystickBase);


	//======================================================


	this->schedule(schedule_selector(TouchPad::update));

	pSprite = Sprite::create("HelloWorld.png");
	pSprite->setPosition(Point(640, 360));
	this->addChild(pSprite);



	return true;
}

void TouchPad::update(float dt)
{
	auto pos = leftJoystick->getStickPosition();

	if (pos.x < -0.75)
	{
		pSprite->setPositionX(pSprite->getPositionX() - 3);
	}
	else if (pos.x > 0.75)
	{
		pSprite->setPositionX(pSprite->getPositionX() + 3);
	}
}
