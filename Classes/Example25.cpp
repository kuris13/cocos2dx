#include "Example25.h"

USING_NS_CC;

//���� ������ static ��ü�� ����
static const Color4F STATIC_COLOR( 1.0f, 0.0f, 0.0f,1.0f);


cocos2d::Scene * Example25::createScene()
{
	return Example25::create();
}

bool Example25::init()
{
	if (Scene::initWithPhysics())
	{
		createMyPhysicsWorld();
	}
	else
	{
		return false;
	}

	// �̺�Ʈ ������
	auto touch = EventListenerTouchAllAtOnce::create();
	touch->onTouchesEnded = CC_CALLBACK_2(Example25::onTouchesEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touch, this);

	//��ü �ʱ�ȭ
	_node = nullptr;

	// ������ 
	this->schedule(schedule_selector(Example25::myTick), 0.5f);


	return true;
}

void Example25::createMyPhysicsWorld()
{
	//�߷��� ����Ǵ� ������ �߷� ���� ����
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vect gravity = Vect(0.0f, 0.0f);

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


void Example25::addNewSpriteAtPosition(cocos2d::Vec2 posiotion)
{
}

bool Example25::anyRay(cocos2d::PhysicsWorld & world, const cocos2d::PhysicsRayCastInfo & info, void * data)
{
	//RayCast�� �浹�� ��ü�� PhysicsBody�� �޾ƿ´�.
	*((Vec2*)data) = info.contact;


	//PhysicsBody* body = info.shape->getBody();
	//
	////�浹�� ��ü�� Tag�� �޾ƿ� log�� ���
	//auto sp = (Sprite*)body->getNode();
	//
	//int tag = sp->getTag();
	//log("Tag information : %d", tag);
	//
	return false;

}

void Example25::myTick(float dt)
{
	Vec2 point1 = Vec2(128, 360);
	Vec2 point2 = Vec2(768, 360);

	removeChild(_node);
	_node = DrawNode::create();

	Vec2 point3 = point2;

	auto func = CC_CALLBACK_3(Example25::anyRay, this);
	
	//================================================

	//rayCast(func,point1,point2,data)
	/*
		func : ������� ó���ϱ� ���� �ݹ��Լ�

		point1 : rayCast�� ������

		point2 : rayCast�� ������ ��ǰ��� ���� ��ǥ

		data : rayCast�� ��Ư�� ��ü�� �ε����� ���,
		       �� ��ü�� ��ǥ�� �޾Ƶδ� (����) ��ü


	*/


	m_world->rayCast(func, point1, point2, &point3);

	// rayCast�� ����ȭ�� ���� drawSegment �޼��� ���
	// drawSegment( ��������, ��������, ���� ����, ���� ���� )
	_node->drawSegment(point1, point2, 3,STATIC_COLOR);

	// rayCast �ֻ� ���� �ȿ� ������Ʈ�� ��ĥ ���
	if (point2 != point3)
	{
		//drawDot �浹����, �浹���� ǥ�� ��Ʈ ũ��, ��Ʈ ����
		_node->drawDot(point3, 3, Color4F(1.0f, 1.0f,1.0f, 1.0f));
	}
	

	this->addChild(_node);
}

void Example25::onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event * event)
{
	// ��Ƽ ��ġ�� ������� ������Ʈ Scene�� ����
	for (const auto &touch : touches)
	{
		auto location = touch->getLocation();

		auto sprite = makeBall(location);
		sprite->setTag(1);
		this->addChild(sprite);

	}


}

cocos2d::Sprite * Example25::makeBall(cocos2d::Vec2 point)
{
	Sprite* ball = Sprite::create("ui/sliderThumb.png");

	//��������Ʈ ũ�⸸ŭ�� physicsBody
	auto material = PhysicsMaterial(0.1f, 1.0f, 0.5f);
	auto body = PhysicsBody::createCircle(ball->getContentSize().width / 2, material);

	ball->setPhysicsBody(body);
	ball->setPosition(point);


	return ball;

}
