#include "Example06.h"
USING_NS_CC;

cocos2d::Scene * Example06::createScene()
{
	return Example06::create();
}

bool Example06::init()
{
	if (!Scene::init())
	{
		return false;
	}

	//도움 변수 _num 초기화
	_num = 0;

	//bool 초기화
	_change = false;
	//==========================================================

	//schedule (상시) 등록
	//Float형 매개변수 단 하나만 존재하는 함수를 매개변수로 받음
	//dt는 DeltaTime
	//매 프레임마다 발동
	//this->schedule(schedule_selector(Example06::anyTime));

	//schedule (일정시간 간격) 등록
	//this->schedule(schedule_selector(Example06::Tick), 1.0f);

	//schedule ( 일회 시전 후 종료 ) 등록
	//this->scheduleOnce(schedule_selector(Example06::myTickOnce), 3.0f);

	//==========================================================


	//MenuItemFont
	auto item01 = MenuItemFont::create("Start", CC_CALLBACK_1(Example06::doStart, this));

	auto item02 = MenuItemFont::create("Pasue", CC_CALLBACK_1(Example06::doPause, this));

	auto item03 = MenuItemFont::create("Resume", CC_CALLBACK_1(Example06::doResume, this));

	auto item04 = MenuItemFont::create("Change", CC_CALLBACK_1(Example06::doChange, this));

	auto item05 = MenuItemFont::create("Stop", CC_CALLBACK_1(Example06::doStop, this));

	auto pMenu = Menu::create(item01, item02, item03, item04, item05, nullptr);

	//자동 수직 정렬
	pMenu->alignItemsVertically();
	this->addChild(pMenu);

	return true;
}

void Example06::anyTime(float dt)
{
	log("상시발동하는 Schedule입니다.");
}

void Example06::Tick(float dt)
{
	log("일정 시간마다 방동하는 schedule입니다.");
}

void Example06::myTickOnce(float dt)
{
	log("3초에 한 번 발동하는 schedule입니다.");
}

void Example06::doStart(Ref * pSender)
{
	//schedule 등록
	this->schedule(schedule_selector(Example06::tick1), 1.0f);
	this->schedule(schedule_selector(Example06::tick2), 3.0f);
}

void Example06::doPause(Ref * pSender)
{
	//schedule 일시정지
	Director::getInstance()->getScheduler()->pauseTarget(this);
}

void Example06::doResume(Ref * pSender)
{
	Director::getInstance()->getScheduler()->resumeTarget(this);
}

void Example06::doChange(Ref * pSender)
{
	//특정 스케줄의 시간 변경
	if (_change)
	{
		_change = false;
		
		//_change가 true라면 tick2의 실행간격을 1초로 변경
		this->unschedule(schedule_selector(Example06::tick2));
		this->schedule(schedule_selector(Example06::tick2), 1.0f);
	}
	else
	{
		_change = true;

		//_change가 false라면 tick2의 실행간격을 3초로 변경
		this->unschedule(schedule_selector(Example06::tick2));
		this->schedule(schedule_selector(Example06::tick2), 3.0f);

	}
}

void Example06::doStop(Ref * pSender)
{



}

void Example06::tick1(float dt)
{
	log("Schedule 1");
}

void Example06::tick2(float dt)
{
	log("Schedule 2");
}
