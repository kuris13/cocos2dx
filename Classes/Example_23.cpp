#include "Example_23.h"

USING_NS_CC;

cocos2d::Scene * Example_23::createScene()
{
	return Example_23::create();
}

bool Example_23::init()
{
	if (Scene::initWithPhysics())
	{
		createMyPhysicsWorld();
	}
	else
	{
		return false;
	}


	//��������Ʈ
	auto sprite = Sprite::create("priconne/Icons/kyaru_6_Icon.png");
	sprite->setPosition(Vec2(640, 360));

	//PhysicsBody
	auto body = PhysicsBody::createBox(sprite->getContentSize());

	//Angular Velocity
	/*
		<setAngularDamping>
		���� �ο��� ȸ���ϰ� �ִ� ������Ʈ�� ������ �ɾ��ش�.
		���밪���� ���� ȸ���� ���� ������Ʈ�� �� �̻� ȸ���� ���� �ʴ´�.
		������ ��ü����, ���� �ùķ��̼� � ����� �� �ִٰ� �Ѵ�.
		�������� 0.0 ~ 1.0 ����.

		<setAngularVelocity>
		ȸ���ӵ��� �󸶳� �� ���� ���� �޼���.
		������ ���� ���� �ش� ������Ʈ�� ���� ȸ���Ѵ�.

		<setAngularVelocityLimit>
		ȸ������ ���Ѽ��� �����Ѵ�.
		�̰� �����صθ�setAngularVelocity ���� �󸶳� ū ���� �Է��ϵ� �Ѱ�ġ �̻��� ���� ������� �ʴ´�.
	*/
	//body->setAngularVelocity(2);
	//body->setAngularDamping(0.5f);


	//�߷¿� ������ ���� �ʵ��� ����
	body->setDynamic(false);

	//setCollisionBitmask : �浹�� �Ͼ�� �ϱ� ���� ��ȣ ����
	body->setCollisionBitmask(2);

	//setContactTestBitmask : �浹�� ���� �̺�Ʈ ó���� ������ ���ΰ�?
	body->setContactTestBitmask(true);

	sprite->setPhysicsBody(body);
	this->addChild(sprite);


	//===========================================================


	// Contact EventListener
	auto contact = EventListenerPhysicsContact::create();

	contact->onContactBegin
		= CC_CALLBACK_1(Example_23::onContactBegin, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(contact, this);


	//===========================================================


	// Touch EventListener
	auto touch = EventListenerTouchOneByOne::create();
	touch->onTouchBegan = CC_CALLBACK_2(Example_23::onTouchBegan, this);
	touch->onTouchEnded = CC_CALLBACK_2(Example_23::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touch, this);


	return true;
}

void Example_23::createMyPhysicsWorld()
{
	//�߷��� ����Ǵ� ������ �߷� ������ ����
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vect gravity = Vect(0.0f, -512.0f);
	//Vect gravity = Vect(0.0f, 0.0f);

	// DebugDrawMask �� gravity ���� ����
	m_world = this->getPhysicsWorld();

	//setDebugDrawMask() : ���� ȿ���� ����Ǵ� ������Ʈ�� ���� �ڽ� �ð�ȭ
	m_world->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	//setGravity : �߷��� ���� (Vec2(0,0)���� �ϸ� ������Ʈ ����)
	m_world->setGravity(gravity);

	//setSpeed : ���Ͽ� ���� �߷°��ӵ� ����
	m_world->setSpeed(2.0f);


	//============================================================


	//PhysicsBody::createEdgeBox
	/*
		- ���� �ùķ��̼��� ����� ������ �����Ѵ�. (EdgeBox => �׸�׸��� ����)

		PhysicsBody::createEdgeBox
		(���� �ùķ��̼� ���� ����, ������ ��� ����, ���� ǥ�ü� �β�)

		PHYSICSBODY_MATERIAL_DEFAULT
		: �е�, �ݹ߷�, ������ 3���� ��Ҹ� ����Ʈ������ ������ ��ũ��
	*/
	auto body = PhysicsBody::createEdgeBox
	(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 10);

	//���� �ùķ��̼��� �����ϱ� ���� Node ��ü
	auto edgeNode = Node::create();

	//��� ��ġ ����ֱ�
	edgeNode->setPosition(Vec2(visibleSize) * 0.5f);

	//������ �Ϸ�� ���� �ùķ��̼� ������ ����
	edgeNode->setPhysicsBody(body);

	this->addChild(edgeNode);
}

bool Example_23::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event)
{
	return true;
}

void Example_23::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * event)
{
	auto location = touch->getLocation();
	addNewSpriteAtPosition(location);
}

void Example_23::addNewSpriteAtPosition(cocos2d::Vec2 position)
{
	//��������Ʈ �����
	auto sprite = Sprite::create("ui/sliderThumb.png");
	sprite->setPosition(position);
	sprite->setScale(2.0f);

	//PhysicsBody �����
	auto body = PhysicsBody::createCircle(sprite->getContentSize().width / 2);

	//Velocity
	/*
		1. setVelocity
		  - ��� �������� ��� ������ �ӷ��� �ο��� ���� ����
		  - �μ��� Vec2(Vect)�� �����Ѵ�

		2. setVelocityLimit
		  - �ӷ��� ���Ѽ��� ����
		  - setAngularVelocityLimit�� �����ϰ� ������Ʈ�� ������ �ɾ���
		
		3. setLinearDamping
		  - ���ӵ� ������Ʈ�� ������ �ɾ��ش�.
		  - ���� ���� ���� 0.0 ~ 1.0 ����
	*/
	//body->setVelocity(Vec2(480, 0));

	body->setCollisionBitmask(1);
	body->setContactTestBitmask(true);

	sprite->setPhysicsBody(body);

	this->addChild(sprite);
}

bool Example_23::onContactBegin(cocos2d::PhysicsContact & contact)
{
	//���� �浹�ϴ� ������Ʈ 2���� PhysicsBody ���� �޾ƿ´�
	PhysicsBody* a = contact.getShapeA()->getBody();
	PhysicsBody* b = contact.getShapeB()->getBody();

	//�˻�
	if ((a->getCollisionBitmask() == 1 && b->getCollisionBitmask() == 2)
		||
		(a->getCollisionBitmask() == 2 && b->getCollisionBitmask() == 1))
	{
		log("Collision has occured!");
	}

	return true;
}
