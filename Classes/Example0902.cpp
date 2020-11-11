#include "Example0902.h"

USING_NS_CC;

cocos2d::Scene * Example0902::createScene()
{
	return Example0902::create();
}

bool Example0902::init()
{
	if(!Scene::init())

	return true;
}

void Example0902::onEnter()
{
	Scene::onEnter();

	//�̱� ��ġ ���� �̺�Ʈ�����ʸ� �ʱ�ȭ 
	_listener = EventListenerTouchAllAtOnce::create();

	//��ġ �̺�Ʈ�� ���� ���
	/*
		�ټ��� ��ü�� �� ���� ���� ��ó�ִ� ���,
		���� ���������� �߰��� ��ü�� ���� ���� �̺�Ʈ�� �����ϴ� ���� ��Ģ.

		���࿡ �� ��ü�� ��� ������ �̺�Ʈ�� �������� ���ϸ�,
		�ڿ������� �̺�Ʈ ����� ���� ��ü�� �Ѿ��.

		�� ��, setSwallowTouches�� false�� �����ϸ�,
		��ü�� �߰� ������ ������� ��� ��ü�� �̺�Ʈ�� �Ҵ��Ѵ�.
	*/
	
	//�̺�Ʈ �����͸� ���� ������ �ݹ��Լ� ����
	_listener->onTouchesBegan = CC_CALLBACK_2(Example0902::onTouchesBegan, this);
	_listener->onTouchesMoved = CC_CALLBACK_2(Example0902::onTouchesMoved, this);
	_listener->onTouchesEnded = CC_CALLBACK_2(Example0902::onTouchesEnded, this);
	_listener->onTouchesCancelled = CC_CALLBACK_2(Example0902::onTouchesCancelled, this);

	//��ġ �̺�Ʈ�� �켱 ������ ȭ�鿡 �׷��� ������� �Ѵ�.
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener, this);

}

void Example0902::onExit()
{
	_eventDispatcher->removeEventListener(_listener);

	Scene::onExit();


}

bool Example0902::onTouchesBegan(const std::vector<cocos2d::Touch*> touch, cocos2d::Event * event)
{
	return false;
}

void Example0902::onTouchesMoved(const std::vector<cocos2d::Touch*> touch, cocos2d::Event * event)
{

}

void Example0902::onTouchesEnded(const std::vector<cocos2d::Touch*> touch, cocos2d::Event * event)
{
	//1�� ��ġ
	auto touches = touch[0];
	auto touchPoint = touches->getLocation();


	//��Ƽ ��ġ
	for (std::vector<int>::size_type i = 0; i < touch.size(); i++)
	{
		auto touches = touch[i];
	}



}

void Example0902::onTouchesCancelled(const std::vector<cocos2d::Touch*> touch, cocos2d::Event * event)
{

}
