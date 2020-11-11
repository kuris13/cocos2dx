#include "Example0903.h"

USING_NS_CC;

cocos2d::Scene * Example0903::createScene()
{
	return Example0903::create();
}

bool Example0903::init()
{
	if(!Scene::init()) return false;

	auto aa = AutoPolygon::generatePolygon("priconne/mv_img_peco.png");


	pSprite[0] = Sprite::create(aa);
	pSprite[0]->setPosition(Vec2(640,360));
	this->addChild(pSprite[0]);

	pSprite[1] = Sprite::create("priconne/mv_img_kyaru.png");
	pSprite[1]->setPosition(Vec2(256,360));
	this->addChild(pSprite[1]);

	pSprite[2] = Sprite::create("priconne/mv_img_kokkoro.png");
	pSprite[2]->setPosition(Vec2(864,360));
	this->addChild(pSprite[2]);


	return true;
}

void Example0903::onEnter()
{
	Scene::onEnter();

	_listener = EventListenerTouchOneByOne::create();
	_listener->setSwallowTouches(true);

	//���ٽ� ( Lambda Expressions )
	/*
		1. ����
		 - ���� �Լ��� �Ｎ���� �����Ͽ� ���� ���� ���� �ζ��� �Լ�ó�� ���

		2. ����
		 [ĸó](�Ű�����){�����ڵ�};

		3. ĸó ���
		 [   ] : �ܺ� ���� ��� �ʰڴ�.
		 [ = ] : �Ķ����(�Ű�����)�� ������ ���� �����ؼ� ���ٽ� ���ο��� ���
	*/

	//���ٽ��� �̿��� ��ġ �̺�Ʈ �ݹ��Լ� �ۼ�
	_listener->onTouchBegan = [=](Touch* touch, Event* event)
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
			//��ġ�� Ÿ���� Z���� �ٲ۴�.
			changeZOrder(target);

			//��ġ�� Ÿ���� ������ �ٲ۴�.
			target->setOpacity(128);
			
			return true;
		}


		return false;
	};

	_listener->onTouchMoved = [](Touch* touch, Event* event)
	{
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		//getDelta() : ��ũ�� ��ġ���� ��ǥ�� �޾ƿ��� ��!
		//���� ��ǥ - ������ǥ �� ��!
		target->setPosition(target->getPosition() + touch->getDelta());


	};

	_listener->onTouchEnded = [=](Touch* touch, Event* event)
	{
		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		target->setOpacity(255);


	};

	//�ش� ���Ķ���Ʈ�� ��ġ���� ��, �ش� �̹����� ���õǰ� �ϱ� ���� ����
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener, pSprite[0]);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener->clone(), pSprite[1]);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener->clone(), pSprite[2]);
}

void Example0903::onExit()
{
	//��� �̺�Ʈ ������ ����
	_eventDispatcher->removeAllEventListeners();

	Scene::onExit();
}

void Example0903::changeZOrder(cocos2d::Sprite * sprite)
{
	//��� ��ü�� z���� �ʱ�ȭ
	for (int i = 0; i < 3; i++)
	{
		pSprite[i]->setZOrder(0);
	}

	//��ġ�� ��ü�� ���� ����
	sprite->setLocalZOrder(1);

}
