#pragma once
#include "cocos2d.h"


USING_NS_CC;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class Example29 : public cocos2d::Scene
{
public:


	static cocos2d::Scene* createScene();
	virtual bool init();


	CREATE_FUNC(Example29);

	cocos2d::EventListenerTouchOneByOne* listener;

	void onEnter();
	void Exit();
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);

private:
	


};

//cocos2d-x ���� Ÿ�ϸ� 
/*
	1. Orthogonal ( ���簢�� )
		- Ÿ�� ũ�Ⱑ �����ϴٴ� ����
		- RPG�� ����� �÷����� ���ӿ��� ���� �� �� �ִ�

	2. Isometric ( �������� )
		- ���簢�� �ʺ��� ��ü���� �������� ���� Ư¡
		- ��������̳� RPG���� �� �� �ִ�.

	3. Hexa ( ������ )
		- ������ �����ϰ� ������
		- �̵� ������ 6�����̱� ������ �ٸ� Ÿ�ϸʿ� ���� ����ȭ
		- ���� ���� �ùķ��̼ǿ��� ���� ���



*/