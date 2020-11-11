#pragma once

#include "cocos2d.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class Example06 :public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	CREATE_FUNC(Example06);
private:

	int _num;
	cocos2d::Sprite* pSprite;

	void anyTime(float dt);
	void Tick(float dt);
	void myTickOnce(float dt);

	void doStart(Ref* pSender);
	void doPause(Ref* pSender);
	void doResume(Ref* pSender);
	void doChange(Ref* pSender);
	void doStop(Ref* pSender);

	void tick1(float dt);
	void tick2(float dt);
	bool _change;

};