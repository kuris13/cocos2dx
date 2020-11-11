// UserDefault
/*
	������ �����͸� �����ϱ� ���� cocos2d-x���� �⺻ �����ϴ� Ŭ����
	������ �� ����(IOS)���� ���Ǵ� NSUserDefault�� �����ؼ� ������.
	
	UserDefault�� ���� ū Ư¡�� �����͸� �̸�-�� ���·� ����.
	�� ���� ����� ���� Key-value pair ��� �Ѵ�.

	

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
