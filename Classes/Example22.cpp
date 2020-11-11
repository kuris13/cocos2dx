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
	//중력이 적용되는 범위와 중력 강도 설정
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vect gravity = Vect(0.0f, -512.0f);

	// DebugDrawMask 나 gravity 값을 대입
	m_world = this->getPhysicsWorld();

	// setDebugDrawMask() : 물리효과가 적용되는 오브젝트의 판정 범위 시각화
	m_world->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	// setGravity : 중력을 설정 ( Vec2(0,0)으로 하면 오브젝트 고정 )
	m_world->setGravity(gravity);

	// setSpeed : 낙하에 따른 중력가속도 설정
	m_world->setSpeed(2.0f);

	//================================================================

	// PhysicsBody::createEdgeBox
	/*
		- 물리 시뮬레이션이 적용될 범위를 설정한다. ( EdgeBox => 네모 형태 )

		PhysicsBody::createEdgeBox
	( 물리 시뮬레이션 적용 범위, 물리학 계수 설정, 판정박스 선의 두께)

	PHYSICSBODY_MATERIAL_DEFAULT
	: 밀도, 반발력, 마찰력 3가지 요소를 디폴트값으로 설정한 매크로

	*/
	auto body = PhysicsBody::createEdgeBox
	(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);

	// 물리 시뮬레이션을 적용하기 위한 Node 객체
	auto edgeNode = Node::create();

	//노드 위치 잡아주기 (중간지점)
	edgeNode->setPosition(Vec2(visibleSize) * 0.5f);

	// 설정이 완료된 물리 시뮬레이션 정보를 적용
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
	//스프라이트 만들기
	auto sprite = Sprite::create("ui/sliderThumb.png");
	sprite->setPosition(posiotion);
	sprite->setScale(2.0f);


	auto body = PhysicsBody::createCircle(sprite->getContentSize().width / 2);

	sprite->setPhysicsBody(body);


	this->addChild(sprite);

}
