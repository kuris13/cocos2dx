#pragma once
#include "cocos2d.h"

/*
	cocos2d-x 는 내부적으로 UTF-8인코딩을 사용하고 있다.
	단, 이것은 모바일 디바이스에서만 동작하는 단점이 존재한다.

	영문/숫자로만 입력할 수 밖에 없는 이 현상을 없애기 위해,
	아래와 같은 조건부 컴파일 문장을 추가해야 한다.

	windows한정
	맥에서는 안 써도 됨.
*/

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class hw02 : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	//현재 Scene으로 진입했을 때 자동으로 호출되는 함수
	void onEnter();
	//현재 Scene에서 나갈 때 자동으로 호출되는 함수 
	void onExit();


	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

	void setAnim();

	CREATE_FUNC(hw02);

private:
	bool pfOn = false;


	cocos2d::Sprite* moveBox;
	cocos2d::Sprite* box;
	cocos2d::Sprite* kyarl;
	cocos2d::Animation* animation;
	cocos2d::EventListenerTouchOneByOne* _listener;
};
