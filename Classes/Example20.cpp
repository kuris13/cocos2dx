
//��� ��ũ��
/*
	1. ����� ���� Ȥ�� ���������� ��ũ���ϴ� ���
	 - �ܼ��ϰ� ū �̹����� �������ֱ⸸ �ϸ� �ȴ�.
	 - �̷��� �ص� ���� ����� ����̽��� ȭ�鸸 ��� �ֽ��ϱ� ������
	  ��ġ ȭ���� ������ ��ũ�ѵǴ� ��ó�� ���δ�.

	2. �������� ������ �����ϴ� �̹��� ������
	 - win32 : 2048 x 2048 ����
	 - Android : 4096 x 4096 ����
	 - IPhone 3 ���� : 1024 x 1024 ����
	 - IPhone 3 ���� : 2048 x 2048 ����

	�̹��� ����� �ùķ����Ϳ����� �ƹ��� ����� ������,
	Ư�� ����̽����� ���������� ������ �Ŷ�� ������ ���Ѵ�.

	�̷� ������ �����ϰ� ��� ����̽����� �۵��ϵ��� ���α׷����Ѵٸ�,
	������ �Ǵ� ũ��� ���� ���� ����� �ȴ�.
	�׷��� �ֱٿ��� �����ϸ� 2048 x 2048�� �����Ѵ�.

*/


#include "Example20.h"

USING_NS_CC;

cocos2d::Scene * Example20::createScene()
{
	return Example20::create();
}

bool Example20::init()
{
	if(!Scene::init()) return false;


	//���̾� 1: ���
	layer1 = Layer::create();
	this->addChild(layer1);

	//���̾� 2: UI
	layer2 = Layer::create();
	this->addChild(layer2);

	//ȭ��ǥ�� ���, �׸��� ĳ���� ��ü �����
	this->createArrowButtons();
	this->createBackground();
	this->createCharacter();



	return true;
}

void Example20::createBackground()
{
	//��� ��������Ʈ ����
	auto background1 = Sprite::create("priconne/background1.png");
	background1->setAnchorPoint(Vec2::ZERO);
	background1->setPosition(Vec2(0, -480));

	auto background2 = Sprite::create("priconne/background2.png");
	background2->setAnchorPoint(Vec2::ZERO);
	background2->setPosition(Vec2(960, -480));

	//��� ���� ���̾ addChild
	layer1->addChild(background1);
	layer1->addChild(background2);
	
	/*
	//��� ���� 
	background1->getTexture()->setAliasTexParameters();

	//��Ƽ �����¡ ����
	background1->getTexture()->setAntiAliasTexParameters();
	*/

}

void Example20::createCharacter()
{
	//plist�� SpriteFrameCache�� �߰�
	auto cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile
	("priconne/Sprites_pecorinne/Sprites_pecorinne.plist");


	//cocos2d::Vector
	Vector<SpriteFrame*> animFrames;

	//Vector�� SpriteFrame ����
	for (int i = 0; i < 18; i++)
	{
		//StringUtils::format() -> ������ �������� string�� ������ش�.
		std::string _frames = StringUtils::format("0%02d.png", i + 1);

		//������ ���ڿ��� �̿��Ͽ� SpriteFrame�� �޾ƿ���
		SpriteFrame* frame = cache->getSpriteFrameByName(_frames);

		//���Ϳ� ����
		animFrames.pushBack(frame);
	}

	//plist�� ����Ͽ� ���� SpriteFrame ������ Ȱ���� Sprite ��ü ����
	animSprite = Sprite::createWithSpriteFrameName("001.png");
	animSprite->setPosition(Vec2(640,360));
	layer1->addChild(animSprite,1);

	//Animation ����
	auto vecAnim = Animation::createWithSpriteFrames(animFrames, 0.05f);
	auto vecAnimate = Animate::create(vecAnim);
	auto VecRep = RepeatForever::create(vecAnimate);

	animSprite->runAction(VecRep);


}

void Example20::createArrowButtons()
{
	//���� ȭ��ǥ idle
	leftChevron = Sprite::create("ui/b1.png");
	leftChevron->setPosition(Vec2(440, 100));
	layer2->addChild(leftChevron,2);
	

	//���� ȭ��ǥ selected
	leftChevronPressed = Sprite::create("ui/b2.png");
	leftChevronPressed->setPosition(Vec2(440, 100));
	layer2->addChild(leftChevronPressed, 1);

	//������ ȭ��ǥ
	rightChevron = Sprite::create("ui/f1.png");
	rightChevron->setPosition(Vec2(840, 100));
	layer2->addChild(rightChevron, 2);

	//������ ȭ��ǥ
	rightChevronPressed = Sprite::create("ui/f2.png");
	rightChevronPressed->setPosition(Vec2(840, 100));
	layer2->addChild(rightChevronPressed, 1);

}

void Example20::onEnter()
{

	Scene::onEnter();

	//�̱� ��ġ ���� �̺�Ʈ�����ʸ� �ʱ�ȭ 
	_listener = EventListenerTouchOneByOne::create();

	_listener->setSwallowTouches(true);

	//�̺�Ʈ �����͸� ���� ������ �ݹ��Լ� ����
	_listener->onTouchBegan = CC_CALLBACK_2(Example20::onTouchBegan, this);
	_listener->onTouchMoved = CC_CALLBACK_2(Example20::onTouchMoved, this);
	_listener->onTouchEnded = CC_CALLBACK_2(Example20::onTouchEnded, this);

	//��ġ �̺�Ʈ�� �켱 ������ ȭ�鿡 �׷��� ������� �Ѵ�.
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener, this);
}

void Example20::onExit()
{


	_eventDispatcher->removeEventListener(_listener);
	Scene::onExit();
}

bool Example20::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event)
{
	isLeftPressed = false;
	isRightPressed = false;

	//��ġ�� ȭ��ǥ ��������Ʈ �ȿ��� ����ƴ��� �˻�
	if (this->isTouchInside(leftChevron, touch))
	{
		//������ true�� �������� idle �̹����� �� ���̰� �����.
		leftChevron->setVisible(false);
		isLeftPressed = true;

		animSprite->setFlippedX(true);
	}
	else if (this->isTouchInside(rightChevron, touch))
	{
		rightChevron->setVisible(false);
		isRightPressed = true;

		animSprite->setFlippedX(false);
	}

	//ȭ��ǥ�� ������ �� ȭ���� �����̰� �����.
	if (isLeftPressed || isRightPressed)
	{
		this->startMovingBackground();
	}

	return true;

}

void Example20::onTouchMoved(cocos2d::Touch * touch, cocos2d::Event * event)
{
	//��ư�� ���� ���·� ��ǥ�� ����� ���� �ʱ�ȭ
	if (isLeftPressed && !this->isTouchInside(leftChevron, touch))
	{
		leftChevron->setVisible(true);
		this->stopMovingBackground();
	}
	else if (isRightPressed && !this->isTouchInside(rightChevron, touch))
	{
		rightChevron->setVisible(true);
		this->stopMovingBackground();
	}




}

void Example20::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * event)
{
	//����ȭ�� �̵��� ���߱�
	if (isLeftPressed || isRightPressed)
	{
		this->stopMovingBackground();
	}

	if (isLeftPressed)
	{
		leftChevron->setVisible(true);
	}
	else if (isRightPressed)
	{
		rightChevron->setVisible(true);
	}


}

bool Example20::isTouchInside(cocos2d::Sprite * sprite, cocos2d::Touch * touch)
{
	auto touchPoint = touch->getLocation();
	bool bTouch = sprite->getBoundingBox().containsPoint(touchPoint);


	return bTouch;
}

void Example20::startMovingBackground()
{
	if (isLeftPressed && isRightPressed)
	{
		//���� ��ư 2���� ���ÿ� ������ ���
		return;
	}
	
	//�������� �̿��Ͽ� �� �����Ӹ��� ���ȭ�� ��ġ�� �����ϰ� ������ش�.
	this->schedule(schedule_selector(Example20::moveBackground));


}

void Example20::stopMovingBackground()
{
	//unscaedule�� �̿��Ͽ� ���ȭ�� ��ġ �̵��� �����Ѵ�.
	this->unschedule(schedule_selector(Example20::moveBackground));
}

void Example20::moveBackground(float t)
{
	//�� �����Ӹ��� ĳ���Ͱ� �̵��� �Ÿ� ����
	int move = 0;
	
	//������ ���⿡ ���� ĳ������ �̵����� ����
	if (isLeftPressed)
	{
		move = -5;
		animSprite->setFlippedX(true);	//ū �ǹ� x
	}
	else
	{
		move = 5;
		animSprite->setFlippedX(false);
	}

	//�¿� �̵� ���� ������ Vec2 ��ü
	auto resetPosition = Vec2(animSprite->getPositionX() + move, animSprite->getPositionY());

	//��� �̹����� ĳ���� ��������Ʈ�� ����� �ʵ��� ����ó��
	if (resetPosition.x < 0)
	{
		resetPosition.x = 0;
	}
	else if (resetPosition.x > 960 * 2)
	{
		resetPosition.x = 960 * 2;
	}

	//���� ������ ��ǥ�� ��������Ʈ�� ����
	animSprite->setPosition(resetPosition);

	//��������Ʈ�� ��ǥ�� ���� ��� ��������Ʈ �̵�
	auto follow = Follow::create(animSprite, Rect(0, 0, 960 * 2, 720));
	layer1->runAction(follow);

}


// Follow �׼�
/*
	Follow::create(followNodem cocos2d::Rect(x1,y1,x2,y2));

	followNode : ī�޶� ����ٴ� ��ü�� �����Ѵ�.
	cocos2d::Rect : ī�޶��� �̵� ����, ī�޶� �̵��� �� �ִ� ���� �������� �ڵ����� ��ü�� ȭ���� �߽ɿ� �д�.
*/