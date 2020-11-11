#pragma once
#include "cocos2d.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class Example25 : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	CREATE_FUNC(Example25);

	cocos2d::PhysicsWorld* m_world;

	void createMyPhysicsWorld();

	void addNewSpriteAtPosition(cocos2d::Vec2 posiotion);

	bool anyRay(cocos2d::PhysicsWorld &world, const cocos2d::PhysicsRayCastInfo& info, void* data);
	void myTick(float dt);
	void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event);

	cocos2d::Sprite* makeBall(cocos2d::Vec2 point);
	cocos2d::DrawNode* _node;


};