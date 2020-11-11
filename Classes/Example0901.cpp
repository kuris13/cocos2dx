#include "Example0901.h"

USING_NS_CC;

cocos2d::Scene * Example0901::createScene()
{
	return Example0901::create();
}

bool Example0901::init()
{
	if (!Scene::init()) return false;
	
	auto aa = AutoPolygon::generatePolygon("priconne/mv_img_kyaru.png");

	pSprite = Sprite::create(aa);
	pSprite->setPosition(Vec2(640,360));
	this->addChild(pSprite);


	return true;
}

void Example0901::onEnter()
{
	Scene::onEnter();

	//�̱� ��ġ ���� �̺�Ʈ�����ʸ� �ʱ�ȭ 
	_listener = EventListenerTouchOneByOne::create();

	//��ġ �̺�Ʈ�� ���� ���
	/*
		�ټ��� ��ü�� �� ���� ���� ��ó�ִ� ���,
		���� ���������� �߰��� ��ü�� ���� ���� �̺�Ʈ�� �����ϴ� ���� ��Ģ.

		���࿡ �� ��ü�� ��� ������ �̺�Ʈ�� �������� ���ϸ�,
		�ڿ������� �̺�Ʈ ����� ���� ��ü�� �Ѿ��.

		�� ��, setSwallowTouches�� false�� �����ϸ�,
		��ü�� �߰� ������ ������� ��� ��ü�� �̺�Ʈ�� �Ҵ��Ѵ�.
	*/
	_listener->setSwallowTouches(true);

	//�̺�Ʈ �����͸� ���� ������ �ݹ��Լ� ����
	_listener->onTouchBegan = CC_CALLBACK_2(Example0901::onTouchBegan, this);
	_listener->onTouchMoved = CC_CALLBACK_2(Example0901::onTouchMoved, this);
	_listener->onTouchEnded = CC_CALLBACK_2(Example0901::onTouchEnded, this);
	_listener->onTouchCancelled = CC_CALLBACK_2(Example0901::onTouchCancelled, this);

	//��ġ �̺�Ʈ�� �켱 ������ ȭ�鿡 �׷��� ������� �Ѵ�.
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener, this);

	//CC_CALLBACK�� ���Ͽ�
	/*
		<< CC_CALLBACK_0 >>
		C++11���� �߰��� std::bind�� cocos2dx�� �°� ���� ���� ��ũ��
		�⺻������ � ���ڵ� �� �Ѿ�ٴ� Ư�� ������ _0�� �پ���.

		<< CC_CALLBACK_1, CC_CALLBACK_2 >>
		����ڰ� � ���ڸ� �ѱ��� �ʾƵ� �Լ��� ȣ���ϴ� ��ü�� �⺻ ����

		1: MenuŬ�������� MenuItem�� ���õ��� �� ȣ���ϴ� �뵵
		2: �̺�Ʈ�� ���޵Ǵ� ������ ���ϰ� �־ ��ġ �̺�Ʈ���� ���

	*/


}

void Example0901::onExit()
{
	//�ش� Scene���� ���� �� Ư�� �̺�Ʈ �����ʸ� ����
	_eventDispatcher->removeEventListener(_listener);

	Scene::onExit();
}

bool Example0901::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event)
{
	//��ġ�� ���� ��ǥ �޾ƿ���
	//auto touchPoint = touch->getLocation();
//	log("PosX = %f, PosY = %f",touchPoint.x,touchPoint.y);


	return true;
}

void Example0901::onTouchMoved(cocos2d::Touch * touch, cocos2d::Event * event)
{
	//��ġ�� ���� ��ǥ �޾ƿ���
	auto touchPoint = touch->getLocation();

	//�浹 �˻�
	bool bTouch = pSprite->getBoundingBox().containsPoint(touchPoint);

	if (bTouch)
	{
		log("PosX = %f, PosY = %f", touchPoint.x, touchPoint.y);
	}


}

void Example0901::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * event)
{

}

void Example0901::onTouchCancelled(cocos2d::Touch * touch, cocos2d::Event * event)
{

}
