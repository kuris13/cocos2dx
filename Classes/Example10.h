#pragma once

#include "cocos2d.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class Example10 :public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();


	//현재 Scene으로 진입했을 때 자동으로 호출되는 함수
	void onEnter();
	//현재 Scene에서 나갈 때 자동으로 호출되는 함수 
	void onExit();

	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);


	CREATE_FUNC(Example10);

private:
	cocos2d::Sprite* pSprite;
	cocos2d::EventListenerKeyboard* _listener;


};