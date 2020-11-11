#pragma once

#include "cocos2d.h"
#include "ui/UIEditBox/UIEditBox.h"


USING_NS_CC;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class Example17 :public cocos2d::Scene,
				public cocos2d::ui::EditBoxDelegate
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	//input ���� ��
	virtual void editBoxEditingDidBegin(cocos2d::ui::EditBox* editbox) override;
	//input ������ ��
	virtual void editBoxEditingDidEnd(cocos2d::ui::EditBox* editbox) override;
	//input �ϴ� �� 
	virtual void editBoxTextChanged(cocos2d::ui::EditBox* editbox, const::std::string &text) override;
	//return �Է�
	virtual void editBoxReturn(cocos2d::ui::EditBox* editbox) override;


	cocos2d::ui::EditBox* _editName;
	cocos2d::ui::EditBox* _editPassword;
	cocos2d::ui::EditBox* _editEmail;


	CREATE_FUNC(Example17);


private:



};
