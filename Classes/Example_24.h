#pragma once
#include "cocos2d.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class Example_24 : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	CREATE_FUNC(Example_24);

private:

	cocos2d::Label* label;
	cocos2d::Sprite* letter;

	int i = 0;
	void typewriterFunction(float t);
};