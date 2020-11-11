#pragma once

#include "cocos2d.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class Example08 :public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	CREATE_FUNC(Example08);
private:
	cocos2d::Sprite* pSprite;
	cocos2d::Sprite* pBullet;

	void createBullet();
	void collision(float dt);


};
