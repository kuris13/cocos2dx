#include "Example11.h"

USING_NS_CC;

cocos2d::Scene * Example11::createScene()
{
	return Example11::create();
}

bool Example11::init()
{
	if(!Scene::init()) return false;

	return true;
}

void Example11::onEnter()
{
	Scene::onEnter();

	_listener = EventListenerMouse::create();

	_listener->onMouseDown = CC_CALLBACK_1(Example11::onMouseDown, this);
	_listener->onMouseMove = CC_CALLBACK_1(Example11::onMouseMove, this);
	_listener->onMouseScroll = CC_CALLBACK_1(Example11::onMouseScroll, this);
	_listener->onMouseUp = CC_CALLBACK_1(Example11::onMouseUp, this);



	_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener, this);

}

void Example11::onExit()
{
	_eventDispatcher->removeEventListener(_listener);

	Scene::onExit();
}

void Example11::onMouseDown(cocos2d::Event * event)
{
	//마우스 버튼 입력 확인 예제
	auto mousePoint = static_cast<EventMouse*>(event);

	auto a = mousePoint->getMouseButton();
	log("Mouse Button : %d", a);

}

void Example11::onMouseMove(cocos2d::Event * event)
{
}

void Example11::onMouseScroll(cocos2d::Event * event)
{
}

void Example11::onMouseUp(cocos2d::Event * event)
{
}
