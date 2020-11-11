// 
/*

*/

#pragma once

//TableView�� ����ϱ� ���� Ȯ�� ���̺귯�� 
#include "cocos2d.h"
#include "cocos2d/extensions/cocos-ext.h"



#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class Example19 :public cocos2d::Scene,
	public cocos2d::extension::TableViewDataSource,
	public cocos2d::extension::TableViewDelegate
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	CREATE_FUNC(Example19);

	

private:
	cocos2d::Sprite* sprite;

	//TableView�� ����ϱ� ���� �߻� Ŭ���� �ż���
	void tableCellTouched(cocos2d::extension::TableView* table,
		cocos2d::extension::TableViewCell* cell);

	//TableView �ȿ� ���� ���� ������ ����
	//Ư�� cell�� ũ�⸦ �����ϴ� �͵� ����
	cocos2d::Size tableCellSizeForIndex(
		cocos2d::extension::TableView* table, ssize_t idx);

	//TableView���� ǥ���� ���� ����
	ssize_t numberOfCellsInTableView(
		cocos2d::extension::TableView* table);

	//cell�� ������
	cocos2d::extension::TableViewCell* tableCellAtIndex(
		cocos2d::extension::TableView* table, ssize_t idx);



};
