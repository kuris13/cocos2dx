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

class Example02 : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	CREATE_FUNC(Example02);

private:

};