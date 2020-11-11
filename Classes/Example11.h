#pragma once

#include "cocos2d.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class Example11 :public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();


	//현재 Scene으로 진입했을 때 자동으로 호출되는 함수
	void onEnter();
	//현재 Scene에서 나갈 때 자동으로 호출되는 함수 
	void onExit();

	void onMouseDown(cocos2d::Event* event);
	void onMouseMove(cocos2d::Event* event);
	void onMouseScroll(cocos2d::Event* event);
	void onMouseUp(cocos2d::Event* event);

	CREATE_FUNC(Example11);

private:
	cocos2d::Sprite* pSprite;
	cocos2d::EventListenerMouse* _listener;


};