#pragma

#include "cocos2d.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class Example22 :public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	CREATE_FUNC(Example22);

	//=================================

	cocos2d::PhysicsWorld* m_world;
	void createMyPhysicsWorld();

	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

	void addNewSpriteAtPosition(cocos2d::Vec2 posiotion);



};


//cocos2d-x 물리엔진 일람
/*
	1. chipmunk (https://chipmunk-physics.net/)
		- 사용 언어 : C언어 / Objective C

	2. Box2D (https://box2d.org/)
		- 사용 언어 : C++




*/