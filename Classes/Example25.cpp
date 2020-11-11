#include "Example25.h"

USING_NS_CC;

//색상 정보를 static 객체로 생성
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

	// 이벤트 리스너
	auto touch = EventListenerTouchAllAtOnce::create();
	touch->onTouchesEnded = CC_CALLBACK_2(Example25::onTouchesEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touch, this);

	//객체 초기화
	_node = nullptr;

	// 스케쥴 
	this->schedule(schedule_selector(Example25::myTick), 0.5f);


	return true;
}

void Example25::createMyPhysicsWorld()
{
	//중력이 적용되는 범위와 중력 강도 설정
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vect gravity = Vect(0.0f, 0.0f);

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


void Example25::addNewSpriteAtPosition(cocos2d::Vec2 posiotion)
{
}

bool Example25::anyRay(cocos2d::PhysicsWorld & world, const cocos2d::PhysicsRayCastInfo & info, void * data)
{
	//RayCast에 충돌한 객체의 PhysicsBody를 받아온다.
	*((Vec2*)data) = info.contact;


	//PhysicsBody* body = info.shape->getBody();
	//
	////충돌된 객체의 Tag를 받아와 log로 출력
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
		func : 결과값을 처리하기 위한 콜백함수

		point1 : rayCast의 시작점

		point2 : rayCast를 어디까지 쏠건가에 대한 좌표

		data : rayCast가 불특정 객체와 부딪히는 경우,
		       그 객체의 좌표를 받아두는 (버퍼) 객체


	*/


	m_world->rayCast(func, point1, point2, &point3);

	// rayCast의 가시화를 위해 drawSegment 메서드 사용
	// drawSegment( 시작지점, 도착지점, 선의 굵기, 선의 색상 )
	_node->drawSegment(point1, point2, 3,STATIC_COLOR);

	// rayCast 주사 범위 안에 오브젝트가 겹칠 경우
	if (point2 != point3)
	{
		//drawDot 충돌지점, 충돌지점 표시 도트 크기, 도트 색상
		_node->drawDot(point3, 3, Color4F(1.0f, 1.0f,1.0f, 1.0f));
	}
	

	this->addChild(_node);
}

void Example25::onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event * event)
{
	// 멀티 터치를 기반으로 오브젝트 Scene에 생성
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

	//스프라이트 크기만큼의 physicsBody
	auto material = PhysicsMaterial(0.1f, 1.0f, 0.5f);
	auto body = PhysicsBody::createCircle(ball->getContentSize().width / 2, material);

	ball->setPhysicsBody(body);
	ball->setPosition(point);


	return ball;

}
