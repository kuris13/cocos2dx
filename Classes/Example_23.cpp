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


	//스프라이트
	auto sprite = Sprite::create("priconne/Icons/kyaru_6_Icon.png");
	sprite->setPosition(Vec2(640, 360));

	//PhysicsBody
	auto body = PhysicsBody::createBox(sprite->getContentSize());

	//Angular Velocity
	/*
		<setAngularDamping>
		값을 부여해 회전하고 있는 오브젝트에 제동을 걸어준다.
		적용값으로 인해 회전이 멈춘 오브젝트는 더 이상 회전을 하지 않는다.
		간단한 유체역학, 마찰 시뮬레이션 등에 사용할 수 있다고 한다.
		범위값은 0.0 ~ 1.0 까지.

		<setAngularVelocity>
		회전속도를 얼마나 할 지에 대한 메서드.
		높으면 높을 수록 해당 오브젝트가 빨리 회전한다.

		<setAngularVelocityLimit>
		회전력의 상한선을 설정한다.
		이걸 설정해두면setAngularVelocity 에서 얼마나 큰 값을 입력하든 한계치 이상의 값은 적용되지 않는다.
	*/
	//body->setAngularVelocity(2);
	//body->setAngularDamping(0.5f);


	//중력에 영향을 받지 않도록 설정
	body->setDynamic(false);

	//setCollisionBitmask : 충돌을 일어나게 하기 위한 번호 지정
	body->setCollisionBitmask(2);

	//setContactTestBitmask : 충돌에 따른 이벤트 처리를 실행할 것인가?
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
	//중력이 적용되는 범위와 중력 강도를 설정
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vect gravity = Vect(0.0f, -512.0f);
	//Vect gravity = Vect(0.0f, 0.0f);

	// DebugDrawMask 나 gravity 값을 대입
	m_world = this->getPhysicsWorld();

	//setDebugDrawMask() : 물리 효과가 적용되는 오브젝트의 판정 박스 시각화
	m_world->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	//setGravity : 중력을 설정 (Vec2(0,0)으로 하면 오브젝트 고정)
	m_world->setGravity(gravity);

	//setSpeed : 낙하에 따른 중력가속도 설정
	m_world->setSpeed(2.0f);


	//============================================================


	//PhysicsBody::createEdgeBox
	/*
		- 물리 시뮬레이션이 적용될 범위를 설정한다. (EdgeBox => 네모네모한 형태)

		PhysicsBody::createEdgeBox
		(물리 시뮬레이션 적용 범위, 물리학 계수 설정, 판정 표시선 두께)

		PHYSICSBODY_MATERIAL_DEFAULT
		: 밀도, 반발력, 마찰력 3가지 요소를 디폴트값으로 설정한 매크로
	*/
	auto body = PhysicsBody::createEdgeBox
	(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 10);

	//물리 시뮬레이션을 적용하기 위한 Node 객체
	auto edgeNode = Node::create();

	//노드 위치 잡아주기
	edgeNode->setPosition(Vec2(visibleSize) * 0.5f);

	//설정이 완료된 물리 시뮬레이션 정보를 적용
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
	//스프라이트 만들기
	auto sprite = Sprite::create("ui/sliderThumb.png");
	sprite->setPosition(position);
	sprite->setScale(2.0f);

	//PhysicsBody 만들기
	auto body = PhysicsBody::createCircle(sprite->getContentSize().width / 2);

	//Velocity
	/*
		1. setVelocity
		  - 어느 방향으로 어느 정도의 속력을 부여할 건지 설정
		  - 인수는 Vec2(Vect)로 기입한다

		2. setVelocityLimit
		  - 속력의 상한선을 설정
		  - setAngularVelocityLimit와 동일하게 오브젝트에 제동을 걸어줌
		
		3. setLinearDamping
		  - 가속된 오브젝트에 제동을 걸어준다.
		  - 적용 범위 값은 0.0 ~ 1.0 까지
	*/
	//body->setVelocity(Vec2(480, 0));

	body->setCollisionBitmask(1);
	body->setContactTestBitmask(true);

	sprite->setPhysicsBody(body);

	this->addChild(sprite);
}

bool Example_23::onContactBegin(cocos2d::PhysicsContact & contact)
{
	//서로 충돌하는 오브젝트 2개의 PhysicsBody 값을 받아온다
	PhysicsBody* a = contact.getShapeA()->getBody();
	PhysicsBody* b = contact.getShapeB()->getBody();

	//검사
	if ((a->getCollisionBitmask() == 1 && b->getCollisionBitmask() == 2)
		||
		(a->getCollisionBitmask() == 2 && b->getCollisionBitmask() == 1))
	{
		log("Collision has occured!");
	}

	return true;
}
