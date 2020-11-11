#include "Example12.h"

USING_NS_CC;

cocos2d::Scene * Example12::createScene()
{
	return Example12::create();
}

bool Example12::init()
{
	if(!Scene::init()) return false;

	auto wlayer = LayerColor::create(Color4B::WHITE);
	this->addChild(wlayer);

	pSprite1 = Sprite::create("priconne/mv_img_peco.png");
	pSprite2 = Sprite::create("priconne/mv_img_kyaru.png");
	pSprite3 = Sprite::create("priconne/mv_img_kokkoro.png");

	//this->SpriteProgressToRadoal();
	//this->SpriteProgressHorizontal();
	//this->SpriteProgressVertical();
	//this->SpriteProgresstoRadialMidipointChanged();
	this->SpriteProgressBarVarious();
	//this->SpriteProgressTintAndFade();





	return true;
}

void Example12::SpriteProgressToRadoal()
{
	//progressTo �׼�
	auto to = ProgressTo::create(3.0f, 100.0f);

	auto left = ProgressTimer::create(pSprite1);
	left->setType(ProgressTimer::Type::RADIAL);
	left->setPosition(Vec2(640, 360));
	this->addChild(left);

	auto right = ProgressTimer::create(pSprite2);
	right->setType(ProgressTimer::Type::RADIAL);
	right->setPosition(Vec2(340, 360));
	this->addChild(right);

	left->runAction(to);
	right->runAction(to->clone());
}

void Example12::SpriteProgressHorizontal()
{
	//progressTo �׼�
	auto to = ProgressTo::create(3.0f, 100.0f);

	auto left = ProgressTimer::create(pSprite1);
	left->setType(ProgressTimer::Type::BAR);
	left->setPosition(Vec2(640, 360));
	

	auto right = ProgressTimer::create(pSprite2);
	right->setType(ProgressTimer::Type::BAR);
	right->setPosition(Vec2(340, 360));

	//��� ���⿡������ ���α׷��� �׼��� ������ ���ΰ�?
	//Vec2(0,0) ->���ʿ��� ������
	//Vec2(1,0) ->�����ʿ��� ����
	left->setMidpoint(Vec2(0,0));
	right->setMidpoint(Vec2(1, 0));


	//���� ��Ȳ�� ��� ǥ���� ������ ����
	left->setBarChangeRate(Vec2(1,0));
	right->setBarChangeRate(Vec2(1, 0));

	this->addChild(left);
	this->addChild(right);

	left->runAction(to);
	right->runAction(to->clone());

}

void Example12::SpriteProgressVertical()
{
	//progressTo �׼�
	auto to = ProgressTo::create(3.0f, 100.0f);

	auto left = ProgressTimer::create(pSprite1);
	left->setType(ProgressTimer::Type::BAR);
	left->setPosition(Vec2(640, 360));


	auto right = ProgressTimer::create(pSprite2);
	right->setType(ProgressTimer::Type::BAR);
	right->setPosition(Vec2(340, 360));

	//��� ���⿡������ ���α׷��� �׼��� ������ ���ΰ�?
	//Vec2(0,0) ->�Ʒ����� ����
	//Vec2(0,1) ->������ �Ʒ���
	left->setMidpoint(Vec2(0, 0));
	right->setMidpoint(Vec2(0, 1));


	//���� ��Ȳ�� ��� ǥ���� ������ ����
	left->setBarChangeRate(Vec2(0, 1));
	right->setBarChangeRate(Vec2(0, 1));

	this->addChild(left);
	this->addChild(right);

	left->runAction(to);
	right->runAction(to->clone());
}

void Example12::SpriteProgresstoRadialMidipointChanged()
{
	//progressTo �׼�
	auto to = ProgressTo::create(3.0f, 100.0f);

	auto left = ProgressTimer::create(pSprite1);
	left->setType(ProgressTimer::Type::RADIAL);
	left->setPosition(Vec2(340, 360));


	auto right = ProgressTimer::create(pSprite2);
	right->setType(ProgressTimer::Type::RADIAL);
	right->setPosition(Vec2(640, 360));

	//��� ���⿡������ ���α׷��� �׼��� ������ ���ΰ�?
	//Vec2(0,0) ->�Ʒ����� ����
	//Vec2(0,1) ->������ �Ʒ���
	left->setMidpoint(Vec2(0.1f, 0.8f));
	right->setMidpoint(Vec2(0.8f, 0.1f));


	this->addChild(left);
	this->addChild(right);

	left->runAction(to);
	right->runAction(to->clone());

}

void Example12::SpriteProgressBarVarious()
{
	//progressTo �׼�
	auto to = ProgressTo::create(3.0f, 100.0f);

	auto left = ProgressTimer::create(pSprite1);
	left->setType(ProgressTimer::Type::BAR);
	left->setPosition(Vec2(300, 360));
	left->setMidpoint(Vec2(0.5f, 0.5f));
	left->setBarChangeRate(Vec2(1, 0));
	this->addChild(left);

	auto middle = ProgressTimer::create(pSprite2);
	middle->setPosition(Vec2(640, 360));
	middle->setType(ProgressTimer::Type::BAR);
	middle->setMidpoint(Vec2(0.5f, 0.5f));
	middle->setBarChangeRate(Vec2(1.0f, 1.0f));
	this->addChild(middle);

	auto right = ProgressTimer::create(pSprite3);
	right->setPosition(Vec2(940, 360));
	right->setMidpoint(Vec2(0.5f, 0.5f));
	right->setType(ProgressTimer::Type::BAR);
	right->setBarChangeRate(Vec2(0, 1));
	this->addChild(right);

	left->runAction(to);
	middle->runAction(to->clone());
	right->runAction(to->clone());

}

void Example12::SpriteProgressTintAndFade()
{ 
}
