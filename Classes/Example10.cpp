#include "Example10.h"

USING_NS_CC;

cocos2d::Scene * Example10::createScene()
{
	return Example10::create();
}

bool Example10::init()
{
	if (!Scene::init()) return false;


	auto aa = AutoPolygon::generatePolygon("priconne/mv_img_peco.png");

	pSprite = Sprite::create(aa);
	pSprite->setPosition(Vec2(640, 360));
	this->addChild(pSprite);

		


	return true;
}

void Example10::onEnter()
{
	Scene::onEnter();
	//키보드 이벤트 리스너
	_listener = EventListenerKeyboard::create();
	_listener->onKeyPressed = CC_CALLBACK_2(Example10::onKeyPressed, this);
	_listener->onKeyReleased = CC_CALLBACK_2(Example10::onKeyReleased, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener, this);

}

void Example10::onExit()
{
	Scene::onExit();
}

void Example10::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event)
{
	switch (keyCode)
	{
	case cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		pSprite->setPositionX(pSprite->getPosition().x - 10);
		break;
	case cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		pSprite->setPositionX(pSprite->getPosition().x + 10);
		break;
	default:
		break;
	}

}

void Example10::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event)
{
}
