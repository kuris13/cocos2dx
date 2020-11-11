#pragma once

#include "cocos2d.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class Example12 :public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	void SpriteProgressToRadoal();
	void SpriteProgressHorizontal();
	void SpriteProgressVertical();
	void SpriteProgresstoRadialMidipointChanged();
	void SpriteProgressBarVarious();
	void SpriteProgressTintAndFade();


	CREATE_FUNC(Example12);

private:
	cocos2d::Sprite* pSprite1;
	cocos2d::Sprite* pSprite2;
	cocos2d::Sprite* pSprite3;


	cocos2d::EventListenerMouse* _listener;


};
