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

	//���� ���� _num �ʱ�ȭ
	_num = 0;

	//bool �ʱ�ȭ
	_change = false;
	//==========================================================

	//schedule (���) ���
	//Float�� �Ű����� �� �ϳ��� �����ϴ� �Լ��� �Ű������� ����
	//dt�� DeltaTime
	//�� �����Ӹ��� �ߵ�
	//this->schedule(schedule_selector(Example06::anyTime));

	//schedule (�����ð� ����) ���
	//this->schedule(schedule_selector(Example06::Tick), 1.0f);

	//schedule ( ��ȸ ���� �� ���� ) ���
	//this->scheduleOnce(schedule_selector(Example06::myTickOnce), 3.0f);

	//==========================================================


	//MenuItemFont
	auto item01 = MenuItemFont::create("Start", CC_CALLBACK_1(Example06::doStart, this));

	auto item02 = MenuItemFont::create("Pasue", CC_CALLBACK_1(Example06::doPause, this));

	auto item03 = MenuItemFont::create("Resume", CC_CALLBACK_1(Example06::doResume, this));

	auto item04 = MenuItemFont::create("Change", CC_CALLBACK_1(Example06::doChange, this));

	auto item05 = MenuItemFont::create("Stop", CC_CALLBACK_1(Example06::doStop, this));

	auto pMenu = Menu::create(item01, item02, item03, item04, item05, nullptr);

	//�ڵ� ���� ����
	pMenu->alignItemsVertically();
	this->addChild(pMenu);

	return true;
}

void Example06::anyTime(float dt)
{
	log("��ùߵ��ϴ� Schedule�Դϴ�.");
}

void Example06::Tick(float dt)
{
	log("���� �ð����� �浿�ϴ� schedule�Դϴ�.");
}

void Example06::myTickOnce(float dt)
{
	log("3�ʿ� �� �� �ߵ��ϴ� schedule�Դϴ�.");
}

void Example06::doStart(Ref * pSender)
{
	//schedule ���
	this->schedule(schedule_selector(Example06::tick1), 1.0f);
	this->schedule(schedule_selector(Example06::tick2), 3.0f);
}

void Example06::doPause(Ref * pSender)
{
	//schedule �Ͻ�����
	Director::getInstance()->getScheduler()->pauseTarget(this);
}

void Example06::doResume(Ref * pSender)
{
	Director::getInstance()->getScheduler()->resumeTarget(this);
}

void Example06::doChange(Ref * pSender)
{
	//Ư�� �������� �ð� ����
	if (_change)
	{
		_change = false;
		
		//_change�� true��� tick2�� ���ణ���� 1�ʷ� ����
		this->unschedule(schedule_selector(Example06::tick2));
		this->schedule(schedule_selector(Example06::tick2), 1.0f);
	}
	else
	{
		_change = true;

		//_change�� false��� tick2�� ���ణ���� 3�ʷ� ����
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
