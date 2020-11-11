#include "Example18.h"

USING_NS_CC;
using namespace ui;

cocos2d::Scene * Example18::createScene()
{
	return Example18::create();
}

bool Example18::init()
{
	if(!Scene::init()) return false;

	auto wlayer = LayerColor::create(Color4B::WHITE);
	this->addChild(wlayer);

	//��������Ʈ
	for (int i = 0; i < 3; i++)
	{
		sprite[i] = Sprite::create("priconne/Icons/peko_6_Icon.png");
	}


	sprite[0]->setPosition(Vec2(64, 64));
	sprite[1]->setPosition(Vec2(192, 64));
	sprite[2]->setPosition(Vec2(320, 64));


	//���̾�
	auto layer = LayerColor::create(Color4B::RED);
	layer->setContentSize(Size(2048, 128));

	for (int i = 0; i < 3; i++)
	{
		layer->addChild(sprite[i]);
	}


	//===========================================
	//===========================================

	// ��ũ�� ��
	// �ټ��� �������� �ϳ��� ����, �� �׷��� �����¿� ��ũ���� �����ϰ� ������ִ� Ŭ����
	
	//��ũ�� �� ����
	auto scrollView = ScrollView::create();
	
	//ȭ�鿡 ��µǴ� ũ�� ����
	scrollView->setContentSize(Size(1024, 128));

	// ��ũ�� �� ���� ���̾��� ũ�� ����
	scrollView->setInnerContainerSize(layer->getContentSize());

	// ��ũ�� �� ������ ���� 
	scrollView->setDirection(ScrollView::Direction::HORIZONTAL);

	// ��ũ�� �� ź�� ȿ�� Ȱ�� ���� 
	scrollView->setBounceEnabled(true);

	// ��ũ�� �� �ڵ� ���� 
	scrollView->setScrollBarAutoHideEnabled(true);

	// ��ũ�� ���� ���� ���� ���ϱ�
	scrollView->jumpToPercentHorizontal(50.0f);

	//
	scrollView->addEventListener(CC_CALLBACK_2(Example18::scrollEvent, this));


	// ������ �߰�
	scrollView->addChild(layer);

	scrollView->setPosition(Vec2(128, 360));
	this->addChild(scrollView);

	return true;
}

void Example18::scrollEvent(Ref * pSender, cocos2d::ui::ScrollView::EventType event)
{
	switch (event)
	{
	case cocos2d::ui::ScrollView::EventType::SCROLL_TO_TOP:
		break;
	case cocos2d::ui::ScrollView::EventType::SCROLL_TO_BOTTOM:
		break;
	case cocos2d::ui::ScrollView::EventType::SCROLL_TO_LEFT:
		break;
	case cocos2d::ui::ScrollView::EventType::SCROLL_TO_RIGHT:
		break;
	case cocos2d::ui::ScrollView::EventType::SCROLLING:
		break;
	case cocos2d::ui::ScrollView::EventType::BOUNCE_TOP:
		break;
	case cocos2d::ui::ScrollView::EventType::BOUNCE_BOTTOM:
		break;
	case cocos2d::ui::ScrollView::EventType::BOUNCE_LEFT:
		break;
	case cocos2d::ui::ScrollView::EventType::BOUNCE_RIGHT:
		break;
	case cocos2d::ui::ScrollView::EventType::CONTAINER_MOVED:
		break;
	case cocos2d::ui::ScrollView::EventType::SCROLLING_BEGAN:
		break;
	case cocos2d::ui::ScrollView::EventType::SCROLLING_ENDED:
		break;
	case cocos2d::ui::ScrollView::EventType::AUTOSCROLL_ENDED:
		break;
	default:
		break;
	}
}
