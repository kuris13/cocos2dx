// UserDefault
/*
	간단한 데이터를 저장하기 위해 cocos2d-x에서 기본 제공하는 클래스
	아이폰 앱 개발(IOS)에서 사용되는 NSUserDefault를 참고해서 제작함.
	
	UserDefault의 가장 큰 특징은 데이터를 이름-값 형태로 저장.
	이 저장 방식을 보통 Key-value pair 라고 한다.

	

*/

#pragma once

#include "cocos2d.h"
#define USERDEFAULT UserDefault::getInstance()

USING_NS_CC;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class Example16 :public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	CREATE_FUNC(Example16);

	void setValue(Ref* pSender);



private:



};
