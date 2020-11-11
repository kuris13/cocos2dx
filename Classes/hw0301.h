#pragma once

#include "cocos2d.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class hw0301 :public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();


	void onEnter();
	//현재 Scene에서 나갈 때 자동으로 호출되는 함수 
	void onExit();

	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event);


	cocos2d::EventListenerTouchOneByOne* _listener;
	CREATE_FUNC(hw0301);


private:

	float _soundVolume;

	int audioId1;

	void doReplaceScene();

	cocos2d::TransitionScene* createTransition( float t, cocos2d::Scene* s);

	cocos2d::Label* lbl;
};
