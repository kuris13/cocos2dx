#include "Exmaple1402.h"
#include "Example14.h"
USING_NS_CC;

cocos2d::Scene * Example1402::createScene()
{
	return Example1402::create();
}

bool Example1402::init()
{
	if (!Scene::init()) return false;

	//Scene 구분 레이어
	auto wlayer = LayerColor::create(Color4B(35, 200, 35, 255));
	this->addChild(wlayer);

	//MenuItem
	auto item = MenuItemFont::create
	("Close Scene 2", CC_CALLBACK_1(Example1402::doClose, this));

	//Menu
	auto pMenu = Menu::create(item, nullptr);
	pMenu->setPosition(Vec2(640, 360));
	this->addChild(pMenu);



	return true;
}



void Example1402::doClose(Ref * pSender)
{
	auto scene = Example14::createScene();
	Director::getInstance()->replaceScene(scene);

}
