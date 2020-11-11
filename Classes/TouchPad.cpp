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

	//ȭ�� ������
	auto visibleSize = Director::getInstance()->getVisibleSize();


	//���̽�ƽ�� ��ġ
	Point joyPosition = Point(visibleSize * 0.25f);

	
	//���̽�ƽ�� �⺻ ������ ���� SneakyJoystickSkinnedBase ��ü
	joystickBase = new SneakyJoystickSkinnedBase();
	joystickBase->init();
	joystickBase->setPosition(joyPosition);
	joystickBase->setBackgroundSprite(Sprite::create("joy1.png"));
	joystickBase->setThumbSprite(Sprite::create("joy2.png"));

	//��ġ �̺�Ʈ�� ó���� SneakyJoystick ��ü
	aJoystick = new SneakyJoystick();
	aJoystick->initWithRect(Rect(0, 0, 160.0f, 160.0f));
	aJoystick->autorelease();

	//���̽�ƽ ����
	joystickBase->setJoystick(aJoystick);
	joystickBase->setPosition(joyPosition);

	//������ ���̽�ƽ�� ������ �޾ƿ���
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
