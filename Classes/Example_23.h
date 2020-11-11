#pragma once
#include "cocos2d.h"

class Example_23 : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	CREATE_FUNC(Example_23);

	//======================================

	cocos2d::PhysicsWorld* m_world;
	void createMyPhysicsWorld();

	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

	void addNewSpriteAtPosition(cocos2d::Vec2 position);

	//오브젝트끼리의 충돌이 발생했을 때 호출하는 함수
	bool onContactBegin(cocos2d::PhysicsContact &contact);
};