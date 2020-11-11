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
	//���̽�ƽ
	SneakyJoystickSkinnedBase* joystickBase;
	SneakyJoystick* aJoystick;
	SneakyJoystick* leftJoystick;

	//��ư
	SneakyButtonSkinnedBase* buttonBase;
	SneakyButton* aButton;
	SneakyButton* attackButton;

	//���ۿ� ��������Ʈ
	cocos2d::Sprite* pSprite;



};
