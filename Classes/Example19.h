// 
/*

*/

#pragma once

//TableView를 사용하기 위한 확장 라이브러리 
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

	//TableView를 사용하기 위한 추상 클래스 매서드
	void tableCellTouched(cocos2d::extension::TableView* table,
		cocos2d::extension::TableViewCell* cell);

	//TableView 안에 들어가는 셀의 사이즈 지정
	//특정 cell의 크기를 지정하는 것도 가능
	cocos2d::Size tableCellSizeForIndex(
		cocos2d::extension::TableView* table, ssize_t idx);

	//TableView에서 표현할 셀의 개수
	ssize_t numberOfCellsInTableView(
		cocos2d::extension::TableView* table);

	//cell의 상세정보
	cocos2d::extension::TableViewCell* tableCellAtIndex(
		cocos2d::extension::TableView* table, ssize_t idx);



};
