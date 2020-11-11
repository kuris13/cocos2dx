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

	//���̽�ƽ�� �⺻ ������ ��Ƶ� SneakyJoystickSkinnedBase ��ü
	joystickBase = new SneakyJoystickSkinnedBase();
	joystickBase->init();
	joystickBase->setPosition(joyPos);
	joystickBase->setBackgroundSprite(Sprite::create("ui/joy1.png"));
	joystickBase->setThumbSprite(Sprite::create("ui/joy2.png"));
	joystickBase->autorelease();

	// ������ ó���� SneakyJoystick ��ü
	aJoystick = new SneakyJoystick();
	aJoystick->initWithRect(Rect(0, 0, 160, 160));
	aJoystick->autorelease();

	// ���̽�ƽ ����
	joystickBase->setJoystick(aJoystick);
	joystickBase->setPosition(joyPos);

	this->addChild(joystickBase);


	//============================================================

	Rect btnDimension = Rect(0, 0, 64, 64);
	Vec2 btnPos = Vec2(visibleSize.width * 0.8f, visibleSize.height * 0.2f);

	//============================================================

	//���̽�
	buttonBase = new SneakyButtonSkinnedBase();
	buttonBase->init();
	buttonBase->setPosition(btnPos);
	buttonBase->setScale(3.0f, 1.5f);

	//�Ӽ�
	buttonBase->setDefaultSprite(Sprite::create("ui/button.png"));
	buttonBase->setActivatedSprite(Sprite::create("ui/button.png"));
	buttonBase->setDisabledSprite(Sprite::create("ui/button.png"));
	buttonBase->setPressSprite(Sprite::create("ui/buttonHighlighted.png"));
	
	// ��ư
	aButton = new SneakyButton();
	aButton->initWithRect(btnDimension);
	aButton->autorelease();
	//������ �� ��� ���� ( Ȧ�尡�� )
	aButton->setIsHoldable(true);
	
	// ��ư ����
	buttonBase->setButton(aButton);
	buttonBase->setPosition(btnPos);
	
	this->addChild(buttonBase);

	//==============================
	
	// �̺�Ʈ ó���� ���ؼ� �߰� �Ҵ�
	leftJoystick = joystickBase->getJoystick();
	leftJoystick->retain();

	attackButton = buttonBase->getButton();
	attackButton->retain();

	//==============================
	//��������Ʈ
	pSprite = Sprite::create("HelloWorld.png");
	pSprite->setPosition(Vec2(visibleSize) * 0.5f);
	this->addChild(pSprite);

	//������
	this->schedule(schedule_selector(Example28::update));



	//==============================




	return true;
}

void Example28::update(float t)
{
	auto joyPos = leftJoystick->getStickPosition();

	//���� ���� +- 120 ����
	if (joyPos.x < 60)
	{
		pSprite->setPositionX(pSprite->getPositionX() - 3);
	}
	else if (joyPos.x > -60)
	{
		pSprite->setPositionX(pSprite->getPositionX() + 3);
	}

	
	//��ư �̺�Ʈ ( ���� Ÿ���� bool )
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
