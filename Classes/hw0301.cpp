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
	_listener->onTouchBegan = CC_CALLBACK_2(hw0301::onTouchBegan, this);
	_listener->onTouchMoved = CC_CALLBACK_2(hw0301::onTouchMoved, this);
	_listener->onTouchEnded = CC_CALLBACK_2(hw0301::onTouchEnded, this);
	_listener->onTouchCancelled = CC_CALLBACK_2(hw0301::onTouchCancelled, this);

	//��ġ �̺�Ʈ�� �켱 ������ ȭ�鿡 �׷��� ������� �Ѵ�.
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
		RemoveSelf::create(),	//�ڱ� �ڽ�(�׼��� ����� ��ü)�� ����� �׼� RemoveSelf
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

	// 14-2�� �̵� pushScene
	auto scene = Introduce::createScene();
	Director::getInstance()->replaceScene(createTransition(1, scene));


	

}

cocos2d::TransitionScene * hw0301::createTransition( float t, cocos2d::Scene * s)
{
	Director::getInstance()->setDepthTest(false);

	return TransitionPageTurn::create(t, s, false);

}
