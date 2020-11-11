#pragma once

#include "cocos2d.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class Example11 :public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();


	//���� Scene���� �������� �� �ڵ����� ȣ��Ǵ� �Լ�
	void onEnter();
	//���� Scene���� ���� �� �ڵ����� ȣ��Ǵ� �Լ� 
	void onExit();

	void onMouseDown(cocos2d::Event* event);
	void onMouseMove(cocos2d::Event* event);
	void onMouseScroll(cocos2d::Event* event);
	void onMouseUp(cocos2d::Event* event);

	CREATE_FUNC(Example11);

private:
	cocos2d::Sprite* pSprite;
	cocos2d::EventListenerMouse* _listener;


};