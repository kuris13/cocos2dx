#pragma once
#include "cocos2d.h"
#include "SneakyButton.h"
#include "SneakyButtonSkinnedBase.h"
#include "SneakyJoystick.h"
#include "SneakyJoystickSkinnedBase.h"

USING_NS_CC;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class Example28 : public cocos2d::Scene
{
public:


	static cocos2d::Scene* createScene();
	virtual bool init();
	void update(float t);


	CREATE_FUNC(Example28);


private:
	//조이스틱
	SneakyJoystickSkinnedBase* joystickBase;
	SneakyJoystick* aJoystick;
	SneakyJoystick* leftJoystick;

	//버튼
	SneakyButtonSkinnedBase* buttonBase;
	SneakyButton* aButton;
	SneakyButton* attackButton;

	//조작용 스프라이트
	cocos2d::Sprite* pSprite;



};
