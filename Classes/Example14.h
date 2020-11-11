#pragma once

#include "cocos2d.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class Example14 :public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();


	CREATE_FUNC(Example14);

	
private:
	void doPushScene(Ref* pSender);
	void doReplaceScene(Ref* pSender);

	cocos2d::TransitionScene* createTransition(int nIndex, float t, cocos2d::Scene* s);


};
