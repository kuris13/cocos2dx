#pragma once

#include "cocos2d.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class Example0903 :public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();


	//���� Scene���� �������� �� �ڵ����� ȣ��Ǵ� �Լ�
	void onEnter();
	//���� Scene���� ���� �� �ڵ����� ȣ��Ǵ� �Լ� 
	void onExit();

	void changeZOrder(cocos2d::Sprite* sprite);


	CREATE_FUNC(Example0903);

private:
	cocos2d::Sprite* pSprite[3];
	cocos2d::EventListenerTouchOneByOne* _listener;


};