#include "Example22.h"

USING_NS_CC;

cocos2d::Scene * Example22::createScene()
{
	return Example22::create();
}

bool Example22::init()
{
	if (Scene::initWithPhysics())
	{
		createMyPhysicsWorld();
	}
	else
	{
		return false;
	}

	//EventListener
	auto touch = EventListenerTouchOneByOne::create();
	touch->onTouchBegan = CC_CALLBACK_2(Example22::onTouchBegan, this);
	touch->onTouchEnded = CC_CALLBACK_2(Example22::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touch, this);


	return true;
}

void Example22::createMyPhysicsWorld()
{
	//�߷��� ����Ǵ� ������ �߷� ���� ����
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vect gravity = Vect(0.0f, -512.0f);

	// DebugDrawMask �� gravity ���� ����
	m_world = this->getPhysicsWorld();

	// setDebugDrawMask() : ����ȿ���� ����Ǵ� ������Ʈ�� ���� ���� �ð�ȭ
	m_world->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	// setGravity : �߷��� ���� ( Vec2(0,0)���� �ϸ� ������Ʈ ���� )
	m_world->setGravity(gravity);

	// setSpeed : ���Ͽ� ���� �߷°��ӵ� ����
	m_world->setSpeed(2.0f);

	//================================================================

	// PhysicsBody::createEdgeBox
	/*
		- ���� �ùķ��̼��� ����� ������ �����Ѵ�. ( EdgeBox => �׸� ���� )

		PhysicsBody::createEdgeBox
	( ���� �ùķ��̼� ���� ����, ������ ��� ����, �����ڽ� ���� �β�)

	PHYSICSBODY_MATERIAL_DEFAULT
	: �е�, �ݹ߷�, ������ 3���� ��Ҹ� ����Ʈ������ ������ ��ũ��

	*/
	auto body = PhysicsBody::createEdgeBox
	(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);

	// ���� �ùķ��̼��� �����ϱ� ���� Node ��ü
	auto edgeNode = Node::create();

	//��� ��ġ ����ֱ� (�߰�����)
	edgeNode->setPosition(Vec2(visibleSize) * 0.5f);

	// ������ �Ϸ�� ���� �ùķ��̼� ������ ����
	edgeNode->setPhysicsBody(body);

	this->addChild(edgeNode);

}

bool Example22::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event)
{
	return true;
}

void Example22::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * event)
{
	auto location = touch->getLocation();
	addNewSpriteAtPosition(location);



}

void Example22::addNewSpriteAtPosition(cocos2d::Vec2 posiotion)
{
	//��������Ʈ �����
	auto sprite = Sprite::create("ui/sliderThumb.png");
	sprite->setPosition(posiotion);
	sprite->setScale(2.0f);


	auto body = PhysicsBody::createCircle(sprite->getContentSize().width / 2);

	sprite->setPhysicsBody(body);


	this->addChild(sprite);

}
