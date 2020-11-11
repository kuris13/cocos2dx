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

	//스프라이트
	for (int i = 0; i < 3; i++)
	{
		sprite[i] = Sprite::create("priconne/Icons/peko_6_Icon.png");
	}


	sprite[0]->setPosition(Vec2(64, 64));
	sprite[1]->setPosition(Vec2(192, 64));
	sprite[2]->setPosition(Vec2(320, 64));


	//레이어
	auto layer = LayerColor::create(Color4B::RED);
	layer->setContentSize(Size(2048, 128));

	for (int i = 0; i < 3; i++)
	{
		layer->addChild(sprite[i]);
	}


	//===========================================
	//===========================================

	// 스크롤 뷰
	// 다수의 컨텐츠를 하나로 묶고, 이 그룹을 상하좌우 스크롤이 가능하게 만들어주는 클래스
	
	//스크롤 뷰 생성
	auto scrollView = ScrollView::create();
	
	//화면에 출력되는 크기 설정
	scrollView->setContentSize(Size(1024, 128));

	// 스크롤 뷰 내부 레이어의 크기 설정
	scrollView->setInnerContainerSize(layer->getContentSize());

	// 스크롤 뷰 방향을 지정 
	scrollView->setDirection(ScrollView::Direction::HORIZONTAL);

	// 스크롤 뷰 탄성 효과 활성 여부 
	scrollView->setBounceEnabled(true);

	// 스크롤 뷰 자동 숨김 
	scrollView->setScrollBarAutoHideEnabled(true);

	// 스크롤 뷰의 시작 지점 정하기
	scrollView->jumpToPercentHorizontal(50.0f);

	//
	scrollView->addEventListener(CC_CALLBACK_2(Example18::scrollEvent, this));


	// 컨텐츠 추가
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
