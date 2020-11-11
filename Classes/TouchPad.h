#pragma once

#include "cocos2d.h"
#include "SneakyButton.h"
#include "SneakyButtonSkinnedBase.h"
#include "SneakyJoystick.h"
#include "SneakyJoystickSkinnedBase.h"

class TouchPad : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	void update(float dt);

	CREATE_FUNC(TouchPad);


private:

	SneakyJoystickSkinnedBase *joystickBase;
	SneakyJoystick* aJoystick;
	SneakyJoystick* leftJoystick;

	cocos2d::Sprite* pSprite;
};
