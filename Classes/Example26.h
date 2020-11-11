#pragma once
#include "cocos2d.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class Example26 : public cocos2d::Scene
{
public:

	Example26();

	static cocos2d::Scene* createScene();
	virtual bool init();

	int _numAllSprites, _LoadedNowSprites;

	cocos2d::Label* _loadingLabel;
	cocos2d::Label* _percentLabel;

	void addSprite();
	void SceneTransition();
	void loadingCallFunc();


	CREATE_FUNC(Example26);

};