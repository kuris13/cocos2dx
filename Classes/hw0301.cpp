#include "hw0301.h"
#include "Introduce.h"
#include "AudioEngine.h"

USING_NS_CC;
using namespace experimental;
cocos2d::Scene * hw0301::createScene()
{
	return hw0301::create();
}

bool hw0301::init()
{
	if(!Scene::init()) return false;

	_soundVolume = 1.0f;

	AudioEngine::preload("priconne/aaa.mp3");

	audioId1 = AudioEngine::play2d("priconne/aaa.mp3", true, _soundVolume);

	auto sprite = Sprite::create("priconne/title.jpg");
	sprite->setScale(1.4f);
	sprite->setPosition(Vec2(640, 360));
	this->addChild(sprite);

	auto sprite2 = Sprite::create("priconne/Logo.png");
	sprite2->setPosition(Vec2(640, 200));
	this->addChild(sprite2);

	TTFConfig ttfConfig("fonts/koverwatch.ttf", 35);

	lbl = Label::createWithTTF(ttfConfig, "Touch To Start");
	lbl->setPosition(Vec2(640,100));
	lbl->setColor(Color3B::WHITE);
	
	addChild(lbl);

	auto a1 = FadeOut::create(1.0f);
	auto a2 = FadeIn::create(1.0f);
	auto myAction = Sequence::createWithTwoActions(a1,a2);

	auto rep = RepeatForever::create(myAction);

	lbl->runAction(rep);



	return true;
}

void hw0301::onEnter()
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
	_listener->onTouchBegan = CC_CALLBACK_2(hw0301::onTouchBegan, this);
	_listener->onTouchMoved = CC_CALLBACK_2(hw0301::onTouchMoved, this);
	_listener->onTouchEnded = CC_CALLBACK_2(hw0301::onTouchEnded, this);
	_listener->onTouchCancelled = CC_CALLBACK_2(hw0301::onTouchCancelled, this);

	//터치 이벤트의 우선 순위를 화면에 그려진 순서대로 한다.
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener, this);

}

void hw0301::onExit()
{
	_eventDispatcher->removeEventListener(_listener);

	Scene::onExit();

}

bool hw0301::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event)
{
	auto action = Sequence::create(
		Blink::create(1.0f, 5),
		CallFunc::create(CC_CALLBACK_0(hw0301::doReplaceScene, this)),
		RemoveSelf::create(),	//자기 자신(액션이 적용된 객체)을 지우는 액션 RemoveSelf
		nullptr
	);


	lbl->runAction(action);

	//doReplaceScene();

	return true;
}

void hw0301::onTouchMoved(cocos2d::Touch * touch, cocos2d::Event * event)
{
}

void hw0301::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * event)
{
}

void hw0301::onTouchCancelled(cocos2d::Touch * touch, cocos2d::Event * event)
{
}

void hw0301::doReplaceScene()
{
	AudioEngine::stopAll();
	AudioEngine::uncacheAll();

	// 14-2로 이동 pushScene
	auto scene = Introduce::createScene();
	Director::getInstance()->replaceScene(createTransition(1, scene));


	

}

cocos2d::TransitionScene * hw0301::createTransition( float t, cocos2d::Scene * s)
{
	Director::getInstance()->setDepthTest(false);

	return TransitionPageTurn::create(t, s, false);

}
