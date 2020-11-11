#include "Example1401.h"

USING_NS_CC;


cocos2d::Scene * Example1401::createScene()
{
	return Example1401::create();
}

bool Example1401::init()
{
	if(!Scene::init()) return false;

	//Scene 구분 레이어
	auto wlayer = LayerColor::create(Color4B(200, 35, 35, 255));
	this->addChild(wlayer);

	//MenuItem
	auto item = MenuItemFont::create
	("Close Scene 1", CC_CALLBACK_1(Example1401::doClose, this));

	//Menu
	auto pMenu = Menu::create(item, nullptr);
	pMenu->setPosition(Vec2(640, 360));
	this->addChild(pMenu);



	return true;
}

void Example1401::doClose(Ref * pSender)
{
	//이전 Scene으로 되돌아가기
	Director::getInstance()->popScene();
}
