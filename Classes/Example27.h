#pragma once
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
USING_NS_CC_EXT;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class Example27 : public cocos2d::Scene
{
public:

	
	static cocos2d::Scene* createScene();
	virtual bool init();


	CREATE_FUNC(Example27);


private:
	// 1. Button
	void ButtonEvent(Ref* pSender, ui::Widget::TouchEventType type);
	
	// 2. ui::CheckBox
	void CheckBoxEvent(Ref* pSender, ui::CheckBox::EventType type);

	// 5. ui::PageView
	void PageViewEvent(Ref* pSender, ui::PageView::EventType type);

	// 7. ui::Slider
	void sliderEvent(Ref* pSender, ui::Slider::EventType type);

};