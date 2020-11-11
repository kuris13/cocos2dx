#pragma once

#include "cocos2d.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class Example0901 :public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();


	//���� Scene���� �������� �� �ڵ����� ȣ��Ǵ� �Լ�
	void onEnter();
	//���� Scene���� ���� �� �ڵ����� ȣ��Ǵ� �Լ� 
	void onExit();

	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event);

	CREATE_FUNC(Example0901);

private:
	cocos2d::Sprite* pSprite;
	cocos2d::EventListenerTouchOneByOne* _listener;


};