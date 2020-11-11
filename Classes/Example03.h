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

class Example03 : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	CREATE_FUNC(Example03);

private:
	void doClick1(Ref* pSender);
	void doClick2(Ref* pSender);
	void doClick3(Ref* pSender);
	void doClick4(Ref* pSender);	//Tag��


};