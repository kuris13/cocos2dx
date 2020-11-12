#pragma once
#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "GLES-Render.h"

#define PTM_RATIO 32

USING_NS_CC;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class Test1 : public cocos2d::Scene
{
public:


	static cocos2d::Scene* createScene();
	virtual bool init();


	cocos2d::EventListenerTouchOneByOne* listener;

	CREATE_FUNC(Test1);

	~Test1(void);

	//==================================
	bool createBox2dWorld(bool debug);
	virtual void draw(Renderer* renderer, const kmMat4& transform, unit32_t flags) override;


	void tick(float dt);

	void addNewSpriteAtPosition(Vec2 location);

	void onEnter();
	void Exit();
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);


	Size winSize;
	Texture2D* texture;
	b2World* _world;

	GLESDebugDraw* m_debugDraw;
	
	void onDraw(const Mat4& tansform, uint32_t flags);
	CustomCommand _customCommand;


	cocos2d::PhysicsWorld* m_world;
	

private:



};