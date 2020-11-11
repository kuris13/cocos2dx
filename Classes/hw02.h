#pragma once
#include "cocos2d.h"

/*
	cocos2d-x �� ���������� UTF-8���ڵ��� ����ϰ� �ִ�.
	��, �̰��� ����� ����̽������� �����ϴ� ������ �����Ѵ�.

	����/���ڷθ� �Է��� �� �ۿ� ���� �� ������ ���ֱ� ����,
	�Ʒ��� ���� ���Ǻ� ������ ������ �߰��ؾ� �Ѵ�.

	windows����
	�ƿ����� �� �ᵵ ��.
*/

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class hw02 : public cocos2d::Scene
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
