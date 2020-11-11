// TableView
/*
	1. ����
		- ScrollView�� Ȯ�� Ŭ����
		- ���̺� �� ���� Ŭ���� 2���� ��� �޾Ƽ� �߻� �޼��带 �������̵� �Ѵ�.
	
	 1) TableViewDataSource 
	  - ���̺� �䰡 ��ũ�ѵǸ� �ش� Ŭ�������� �� ������ �����͸� �ҷ��� ȭ�鿡 ǥ���ϴ� ��Ȱ

	 2) TableViewDelegate
	  - ��ġ �̺�Ʈ�� �߻����� ���, ���� �Ҵ�� �̺�Ʈ �Լ� ȣ�� 
	
	2. Ư¡
		-ȭ��� ���̴� �κи� �����͸� �ۼ��ϰ�,
		������ �ʴ� �κ��� �����͸� ���� �������� �ʴ´�.

		-ó�� ȭ�鿡 ��µ� �� �ʿ��� ��ŭ�� �����͸� ���� �ҷ����δ�.
		���� ����ڰ� ��ũ�Ѹ��� �� �� ���ο� �κ��� ������ �� �� �����͸� �߰���
		�о���δ�.
		
		- Android ����Ʈ �� IOS�� ���̺� ��� ����

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

	//��� ���̾�
	auto wlayer = LayerColor::create(Color4B::WHITE);
	this->addChild(wlayer);

	//���̺� ��
	auto tableView = TableView::create(this, Size(1024,128));

	//��ũ�� ����
	tableView->setDirection(ScrollView::Direction::HORIZONTAL);

	//��ġ
	tableView->setPosition(Vec2(128, 300));


	//�߰�
	this->addChild(tableView);

	//�̰� �ʼ�
	tableView->setDelegate(this);

	//�߻� �޼����� �����ص� ������ �ҷ��´�.
	tableView->reloadData();

	return true;
}




void Example19::tableCellTouched(cocos2d::extension::TableView * table, cocos2d::extension::TableViewCell * cell)
{
	//���� ��ġ���� ���� �̺�Ʈ ó��
	log("Cell touched");

}

cocos2d::Size Example19::tableCellSizeForIndex(cocos2d::extension::TableView * table, ssize_t idx)
{

	//Ư�� ���� ũ�⸦ ����
	if (idx == 3) return Size(256, 256);

	//���� ũ�⸦ �ϰ� ����
	return cocos2d::Size(128,128);
}

ssize_t Example19::numberOfCellsInTableView(cocos2d::extension::TableView * table)
{
	//TableView�� ���� ��� ���� ���� ���� ����


	return 10;
}

cocos2d::extension::TableViewCell * Example19::tableCellAtIndex(cocos2d::extension::TableView * table, ssize_t idx)
{
	auto string = String::createWithFormat("%ld", idx);

	//TableView �ȿ� �� Cell�� �����.
	TableViewCell* cell = table->dequeueCell();

	cell = new TableViewCell;
	cell->autorelease();

	//��������Ʈ �߰� ( ������ �̹����� ���� )
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
