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

	//싱글 터치 모드로 이벤트리스너를 초기화 
	_listener = EventListenerTouchOneByOne::create();

	//터치 이벤트의 수신 방식
	/*
		다수의 객체가 한 곳에 여럿 겹처있는 경우,
		가장 마지막으로 추가된 객체가 제일 먼저 이벤트를 수신하는 것이 원칙.

		만약에 이 객체가 어떠한 이유로 이벤트를 수신하지 못하면,
		자연스럽게 이벤트 대상이 다음 객체로 넘어간다.

		이 때, setSwallowTouches를 false로 설정하면,
		객체의 추가 순서에 상관없이 모든 객체에 이벤트를 할당한다.
	*/
	_listener->setSwallowTouches(true);

	//이벤트 리스터를 통해 실행한 콜백함수 연결
	_listener->onTouchBegan = CC_CALLBACK_2(Example0901::onTouchBegan, this);
	_listener->onTouchMoved = CC_CALLBACK_2(Example0901::onTouchMoved, this);
	_listener->onTouchEnded = CC_CALLBACK_2(Example0901::onTouchEnded, this);
	_listener->onTouchCancelled = CC_CALLBACK_2(Example0901::onTouchCancelled, this);

	//터치 이벤트의 우선 순위를 화면에 그려진 순서대로 한다.
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener, this);

	//CC_CALLBACK에 대하여
	/*
		<< CC_CALLBACK_0 >>
		C++11부터 추가된 std::bind를 cocos2dx에 맞게 고쳐 만든 매크로
		기본적으로 어떤 인자도 안 넘어간다는 특성 때문에 _0이 붙었다.

		<< CC_CALLBACK_1, CC_CALLBACK_2 >>
		사용자가 어떤 인자를 넘기지 않아도 함수를 호출하는 객체가 기본 전달

		1: Menu클래스에서 MenuItem이 선택됐을 때 호출하는 용도
		2: 이벤트가 전달되는 형식을 취하고 있어서 터치 이벤트에서 사용

	*/


}

void Example0901::onExit()
{
	//해당 Scene에서 나갈 때 특정 이벤트 리스너를 제거
	_eventDispatcher->removeEventListener(_listener);

	Scene::onExit();
}

bool Example0901::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event)
{
	//터치한 곳의 좌표 받아오기
	//auto touchPoint = touch->getLocation();
//	log("PosX = %f, PosY = %f",touchPoint.x,touchPoint.y);


	return true;
}

void Example0901::onTouchMoved(cocos2d::Touch * touch, cocos2d::Event * event)
{
	//터치한 곳의 좌표 받아오기
	auto touchPoint = touch->getLocation();

	//충돌 검사
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
