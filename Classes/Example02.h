#pragma once
#include "cocos2d.h"

/*
	cocos2d-x 는 내부적으로 UTF-8인코딩을 사용하고 있다.
	단, 이것은 모바일 디바이스에서만 동작하는 단점이 존재한다.

	영문/숫자로만 입력할 수 밖에 없는 이 현상을 없애기 위해,
	아래와 같은 조건부 컴파일 문장을 추가해야 한다.

	windows한정
	맥에서는 안 써도 됨.
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