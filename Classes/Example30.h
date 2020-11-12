#pragma once
#include "cocos2d.h"


USING_NS_CC;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class Example30 : public cocos2d::Scene
{
public:


	static cocos2d::Scene* createScene();
	virtual bool init();


	CREATE_FUNC(Example30);

	void onEnter();
	void Exit();
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);


	//==================================

	
	
	cocos2d::PhysicsWorld* m_world;
	void createMyPhysicsWorld();

	void changeModeCallFunc(Ref* pSender);
	bool anyRay(cocos2d::PhysicsWorld &world, const cocos2d::PhysicsWorld aa);
	

private:



};