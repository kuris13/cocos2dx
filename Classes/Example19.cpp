// TableView
/*
	1. 개요
		- ScrollView의 확장 클래스
		- 테이블 뷰 관련 클래스 2개를 상속 받아서 추상 메서드를 오버라이딩 한다.
	
	 1) TableViewDataSource 
	  - 테이블 뷰가 스크롤되면 해당 클래스에서 셀 단위로 데이터를 불러와 화면에 표시하는 역활

	 2) TableViewDelegate
	  - 터치 이벤트가 발생했을 경우, 셀에 할당된 이벤트 함수 호출 
	
	2. 특징
		-화면상에 보이는 부분만 데이터를 작성하고,
		보이지 않는 부분은 데이터를 따로 만들어두지 않는다.

		-처음 화면에 출력될 때 필요한 만큼만 데이터를 먼저 불러들인다.
		이후 사용자가 스크롤링을 할 때 새로운 부분이 나오면 그 때 데이터를 추가로
		읽어들인다.
		
		- Android 리스트 뷰 IOS의 테이블 뷰와 유사

*/

#include "Example19.h"

USING_NS_CC;
USING_NS_CC_EXT;


cocos2d::Scene * Example19::createScene()
{
	return Example19::create();
}

bool Example19::init()
{
	if(!Scene::init()) return false;

	//배경 레이어
	auto wlayer = LayerColor::create(Color4B::WHITE);
	this->addChild(wlayer);

	//테이블 뷰
	auto tableView = TableView::create(this, Size(1024,128));

	//스크롤 방향
	tableView->setDirection(ScrollView::Direction::HORIZONTAL);

	//위치
	tableView->setPosition(Vec2(128, 300));


	//추가
	this->addChild(tableView);

	//이거 필수
	tableView->setDelegate(this);

	//추상 메서드의 설정해둔 정보를 불러온다.
	tableView->reloadData();

	return true;
}




void Example19::tableCellTouched(cocos2d::extension::TableView * table, cocos2d::extension::TableViewCell * cell)
{
	//셀이 터치됐을 때의 이벤트 처리
	log("Cell touched");

}

cocos2d::Size Example19::tableCellSizeForIndex(cocos2d::extension::TableView * table, ssize_t idx)
{

	//특정 셀의 크기를 지정
	if (idx == 3) return Size(256, 256);

	//셀의 크기를 일괄 지정
	return cocos2d::Size(128,128);
}

ssize_t Example19::numberOfCellsInTableView(cocos2d::extension::TableView * table)
{
	//TableView에 셀을 몇개나 집어 넣을 건지 설정


	return 10;
}

cocos2d::extension::TableViewCell * Example19::tableCellAtIndex(cocos2d::extension::TableView * table, ssize_t idx)
{
	auto string = String::createWithFormat("%ld", idx);

	//TableView 안에 들어갈 Cell을 만든다.
	TableViewCell* cell = table->dequeueCell();

	cell = new TableViewCell;
	cell->autorelease();

	//스프라이트 추가 ( 복수의 이미지를 적용 )
	for (int i = 0; i < 11; i++)
	{
		if (idx == i)
		{
			auto string = String::createWithFormat("Icons/0%02d.png",idx+1);

			auto sprite = Sprite::create(string->getCString());
			sprite->setAnchorPoint(Vec2::ZERO);
			sprite->setPosition(Vec2::ZERO);
			cell->addChild(sprite);
		}


	}

	return cell;
}
