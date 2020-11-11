#pragma once
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#define NAME_PECORINNE "priconne/btnVoices/btnVoice01_01.png"
#define NAME_KOKKORO "priconne/btnVoices/btnVoice01_02.png"
#define NAME_KYARL "priconne/btnVoices/btnVoice01_03.png"


#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif


class Introduce : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	CREATE_FUNC(Introduce);


private:
	float _soundVolume;

	int audioId1;
	int audioId2;
	bool naviOn = false;
	bool initScreen = true;

	//ĳ���� ������
	cocos2d::MenuItemImage* Icons[3];

	cocos2d::ui::Button* naviBtn;
	cocos2d::Sprite* navi;
	cocos2d::Sprite* list;
	cocos2d::Label* listName;
	//ĳ���� �Ϸ���Ʈ
	cocos2d::Sprite* illust[3];
	cocos2d::Sprite* illust2[3];

	//���
	cocos2d::Sprite* guildName;

	//���
	cocos2d::Sprite* bgSprite;

	//�޴�
	cocos2d::Menu* menu;


	//���ڸ��� ������
	void profilePecorinne(Ref* pSender);

	//ļ�� ������
	void profileKyarl(Ref* pSender);

	//���ڷ� ������
	void profileKokkoro(Ref* pSender);

	void profile0201(Ref* pSender);
	void profile0202(Ref* pSender);
	void profile0203(Ref* pSender);

	void profile0301(Ref* pSender);
	void profile0302(Ref* pSender);
	void profile0303(Ref* pSender);

	void naviClick(Ref* pSender);

	void scrollEvent(Ref* pSender, cocos2d::ui::ScrollView::EventType event);

	void menu1(Ref* pSender);

	void menu2(Ref* pSender);

	void menu3(Ref* pSender);

	//ĵ�� ��ư
	void btnCancel();
	void btnVoice(Ref* pSender);

};