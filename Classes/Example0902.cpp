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

	//싱글 터치 모드로 이벤트리스너를 초기화 
	_listener = EventListenerTouchAllAtOnce::create();

	//터치 이벤트의 수신 방식
	/*
		다수의 객체가 한 곳에 여럿 겹처있는 경우,
		가장 마지막으로 추가된 객체가 제일 먼저 이벤트를 수신하는 것이 원칙.

		만약에 이 객체가 어떠한 이유로 이벤트를 수신하지 못하면,
		자연스럽게 이벤트 대상이 다음 객체로 넘어간다.

		이 때, setSwallowTouches를 false로 설정하면,
		객체의 추가 순서에 상관없이 모든 객체에 이벤트를 할당한다.
	*/
	
	//이벤트 리스터를 통해 실행한 콜백함수 연결
	_listener->onTouchesBegan = CC_CALLBACK_2(Example0902::onTouchesBegan, this);
	_listener->onTouchesMoved = CC_CALLBACK_2(Example0902::onTouchesMoved, this);
	_listener->onTouchesEnded = CC_CALLBACK_2(Example0902::onTouchesEnded, this);
	_listener->onTouchesCancelled = CC_CALLBACK_2(Example0902::onTouchesCancelled, this);

	//터치 이벤트의 우선 순위를 화면에 그려진 순서대로 한다.
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
	//1점 터치
	auto touches = touch[0];
	auto touchPoint = touches->getLocation();


	//멀티 터치
	for (std::vector<int>::size_type i = 0; i < touch.size(); i++)
	{
		auto touches = touch[i];
	}



}

void Example0902::onTouchesCancelled(const std::vector<cocos2d::Touch*> touch, cocos2d::Event * event)
{

}
