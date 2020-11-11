#include "Example06.h"
USING_NS_CC;

cocos2d::Scene * Example06::createScene()
{
	return Example06::create();
}

bool Example06::init()
{
	if (!Scene::init())
	{
		return false;
	}



	return true;
}
