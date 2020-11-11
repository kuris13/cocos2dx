#pragma once

#include "cocos2d.h"

class Example01 :public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	CREATE_FUNC(Example01);

	void printLog(int n);
	
};