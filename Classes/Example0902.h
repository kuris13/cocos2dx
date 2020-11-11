#pragma once

#include "cocos2d.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class Example0902 :public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	void onEnter();
	void onExit();

	bool onTouchesBegan(const std::vector<cocos2d::Touch*> touch, cocos2d::Event* event);
	void onTouchesMoved(const std::vector<cocos2d::Touch*> touch, cocos2d::Event* event);
	void onTouchesEnded(const std::vector<cocos2d::Touch*> touch, cocos2d::Event* event);
	void onTouchesCancelled(const std::vector<cocos2d::Touch*> touch, cocos2d::Event* event);

	CREATE_FUNC(Example0902);

private:
	cocos2d::Sprite* pSprite;
	cocos2d::EventListenerTouchAllAtOnce* _listener;


};