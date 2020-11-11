#include "hw02.h"

USING_NS_CC;


cocos2d::Scene * hw02::createScene()
{
	return hw02::create();
}

bool hw02::init()
{
	if(!Scene::init()) return false;


	auto bg = Sprite::create("priconne/page_bg.jpg");
	bg->setPosition(640, 360);
	this->addChild(bg);

	box = Sprite::create("priconne/guildList.png");
	box->setPosition(1050, 140);
	box->setScale(0.8f, 0.25f);
	box->setTag(1);
	this-> addChild(box);

	moveBox = Sprite::create("priconne/Icons/kyaru_summer_Icon.png");
	moveBox->setPosition(640, 560);
	this->addChild(moveBox);


	TTFConfig ttfConfig("fonts/Scissor Cuts.ttf", 40);

	ttfConfig.outlineSize = 3;
	ttfConfig.bold = true;
	auto txt1 = Label::createWithTTF(
		ttfConfig, "<- put the profile Image in the box");
	txt1->setPosition(moveBox->getPosition().x+350, moveBox->getPosition().y);
	txt1->setColor(Color3B::WHITE);
	txt1->enableBold();
	txt1->enableOutline(Color4B::RED);
	this->addChild(txt1);


	//================================================================================

	kyarl = Sprite::create("priconne/Sprites_kyarl/001.png");
	kyarl->setPosition(Vec2(400, 300));
	this->addChild(kyarl);

	//�ִϸ��̼� ����� ���� Animation ��ü
	//�̹��� ��ȯ�� �ʿ��� SpriteFrame�� ���� ������ �׷�ȭ�Ǿ� ����
	auto animation = Animation::create();

	//�ʴ� ������ ��� �ӵ�
	animation->setDelayPerUnit(0.05f);

	//�ִϸ��̼ǿ� ����� ������(�̹���) �߰�
	{
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/001.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/002.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/003.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/004.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/005.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/006.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/007.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/008.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/009.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/010.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/011.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/012.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/013.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/014.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/015.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/016.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/017.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/018.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/019.png");

	}


	//=================================================================================

	ttfConfig.outlineSize = 3;
	ttfConfig.bold = true;
	auto txt2 = Label::createWithTTF(
		ttfConfig, "It runs When profile Image placed in the box");
	txt2->setPosition(kyarl->getPosition().x,kyarl->getPosition().y-150);
	txt2->setColor(Color3B::WHITE);
	txt2->enableBold();
	txt2->enableOutline(Color4B::RED);
	this->addChild(txt2);



	//SpriteFrame������ �߰��� Animation��ü�� �����Ű�� �׼�
	
	





	return true;
}

void hw02::onEnter()
{
	Scene::onEnter();

	_listener = EventListenerTouchOneByOne::create();
	_listener->setSwallowTouches(true);

	_listener->onTouchBegan = CC_CALLBACK_2(hw02::onTouchBegan, this);
	_listener->onTouchMoved = CC_CALLBACK_2(hw02::onTouchMoved, this);
	_listener->onTouchEnded = CC_CALLBACK_2(hw02::onTouchEnded, this);


	
	//�ش� ���Ķ���Ʈ�� ��ġ���� ��, �ش� �̹����� ���õǰ� �ϱ� ���� ����
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener, moveBox);

}

void hw02::onExit()
{
	//��� �̺�Ʈ ������ ����
	_eventDispatcher->removeAllEventListeners();

	Scene::onExit();
}

bool hw02::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event)
{
	//getCurrentTarget() : ��ġ �̺�Ʈ�� ������ ��� Ÿ���� ������ �޾ƿ´�.
		//���� �ڷ����� �����͸� ���� ������, Ȥ�� ��ġ�ϱ� ���� �̸� �±׸� �ο��ؼ� � ��带
		//�޾ƿ� �������� ���� ��Ŀ���� ������ �Ѵ�.
	auto target = static_cast<Sprite*>(event->getCurrentTarget());

	//convertToNodeSpace() : ���ڰ��� Ư�� ��� ������ ��ǥ������ �������ش�.
	//world Space���� local Space�� �ٲٴ� ��!
	Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());

	//Ÿ���� ũ�⸦ �޾ƿ� ������ Rect�� ����
	Size s = target->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);

	//���� ��ġ�� ���� Rect�� ��ĥ ���
	if (rect.containsPoint(locationInNode))
	{
		//��ġ�� Ÿ���� ������ �ٲ۴�.
		target->setOpacity(128);

		return true;
	}


	return false;
}

void hw02::onTouchMoved(cocos2d::Touch * touch, cocos2d::Event * event)
{
	auto target = static_cast<Sprite*>(event->getCurrentTarget());
	//getDelta() : ��ũ�� ��ġ���� ��ǥ�� �޾ƿ��� ��!
	//���� ��ǥ - ������ǥ �� ��!
	target->setPosition(target->getPosition() + touch->getDelta());
}

void hw02::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * event)
{
	auto target = static_cast<Sprite*>(event->getCurrentTarget());

	//��ġ�� ���� ��ǥ �޾ƿ���
	auto touchPoint = touch->getLocation();
	

	bool colision = box->getBoundingBox().containsPoint(touchPoint);
	if (colision)
	{
		target->setPosition(box->getPosition());

		target->setOpacity(255);
		setAnim();

		return;
	}

	kyarl->stopAllActions();
	target->setOpacity(255);
}

void hw02::setAnim()
{
	auto animation = Animation::create();

	//�ʴ� ������ ��� �ӵ�
	animation->setDelayPerUnit(0.05f);

	//�ִϸ��̼ǿ� ����� ������(�̹���) �߰�
	{
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/001.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/002.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/003.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/004.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/005.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/006.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/007.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/008.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/009.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/010.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/011.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/012.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/013.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/014.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/015.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/016.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/017.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/018.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/019.png");

	}

	auto animate = Animate::create(animation);

	//�ִϸ��̼� ���� �ݺ�
	auto rep = RepeatForever::create(animate);
	
	kyarl->stopAllActions();
	kyarl->runAction(rep);

}
