#pragma once

#include "cocos2d.h"
#include "ui/CocosGUI.h"


#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class Example18 :public cocos2d::Scene
	
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	CREATE_FUNC(Example18);

	void scrollEvent(Ref* pSender, cocos2d::ui::ScrollView::EventType event);


private:
	cocos2d::Sprite* sprite[3];



};
