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

class hw01 : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	CREATE_FUNC(hw01);

private:
	bool pfOn = false;

	void btnChara01(Ref* pSender);


	void btnCloseBtn(Ref* pSender);
	void btnVoiceBtn(Ref* pSender);
	
};
