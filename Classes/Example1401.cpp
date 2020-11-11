#include "Example1401.h"

USING_NS_CC;


cocos2d::Scene * Example1401::createScene()
{
	return Example1401::create();
}

bool Example1401::init()
{
	if(!Scene::init()) return false;

	//Scene ���� ���̾�
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
	//���� Scene���� �ǵ��ư���
	Director::getInstance()->popScene();
}
