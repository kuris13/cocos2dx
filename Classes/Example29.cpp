#include "Example29.h"

cocos2d::Scene * Example29::createScene()
{

	return Example29::create();

}

bool Example29::init()
{
	if(!Scene::init()) return false;

	//Ÿ�ϸ� �ҷ�����
	auto tmap = TMXTiledMap::create("TileMaps/222222.tmx");
	//Ÿ�ϸ��� z���� -1���Ϸ� �ϸ� ȭ�鿡 �� ���´�. 
	this->addChild(tmap, 0, 11);

	Size s = tmap->getContentSize();
	log("ContentSize : %f, %f", s.width, s.height);





	return true;
}

void Example29::onEnter()
{
	Scene::onEnter();

	//�̱� ��ġ ���� �̺�Ʈ�����ʸ� �ʱ�ȭ 
	listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(Example29::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(Example29::onTouchMoved, this);


	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void Example29::Exit()
{

	_eventDispatcher->removeEventListener(listener);
	Scene::onExit();

}

bool Example29::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event)
{
	

	return true;
}

void Example29::onTouchMoved(cocos2d::Touch * touch, cocos2d::Event * event)
{
	Vec2 diff = touch->getDelta();
	//log("aa");

	Node* node = this->getChildByTag(11);
	Vec2 currentPos = node->getPosition();

	Vec2 newPos = currentPos + diff;

	if (newPos.x < -160)
	{
		newPos.x = -160;
	}
	if (newPos.x > 0)
	{
		newPos.x = 0;
	}

	newPos.y = 0;
	node->setPosition(newPos);

}
