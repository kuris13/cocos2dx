#include "Test1.h"

cocos2d::Scene * Test1::createScene()
{
	return Test1::create();
}

bool Test1::init()
{
	if(!Scene::init()) return false;


	winSize = Director::getInstance()->getWinSize();

	texture = Director::getInstance()->getTextureCache()->addImage("priconne/mv_img_kyaru.png");

	b2Vec2 gravity = b2Vec2(0.0f, -30.0f);
	_world = new b2World(gravity);
	_world->SetAllowSleeping(true);
	_world->SetContinuousPhysics(true);


	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0, 0);

	auto groundBody = _world->CreateBody(&groundBodyDef);

	b2EdgeShape groundEdge;
	b2FixtureDef boxShapeDef;
	boxShapeDef.shape = &groundEdge;

	groundEdge.Set(b2Vec2(0, 0), b2Vec2(winSize.width / PTM_RATIO, 0));
	groundBody->CreateFixture(&boxShapeDef);

	groundEdge.Set(b2Vec2(0, 0), b2Vec2(0,winSize.width / PTM_RATIO));
	groundBody->CreateFixture(&boxShapeDef);

	groundEdge.Set(b2Vec2(0, winSize.height/ PTM_RATIO), b2Vec2(winSize.width / PTM_RATIO, winSize.height / PTM_RATIO));
	groundBody->CreateFixture(&boxShapeDef);

	groundEdge.Set(b2Vec2(winSize.width / PTM_RATIO, winSize.height / PTM_RATIO),
		b2Vec2(winSize.width / PTM_RATIO, 0));
	groundBody->CreateFixture(&boxShapeDef);

	this->schedule(schedule_selector(Test1::tick));


	return true;
}

Test1::~Test1(void)
{
	delete _world;
	_world = nullptr;

}

void Test1::tick(float dt)
{
	int velocityIterations = 8;
	int positionIterations = 3;

	_world->Step(dt, velocityIterations, positionIterations);

	for (b2Body*b = _world->GetBodyList(); b; b = b->GetNext())
	{
		if (b->GetUserData() != nullptr)
		{
			auto spriteData = (Sprite*)b->GetUserData();
			spriteData->setPosition(Vec2(b->GetPosition().x * PTM_RATIO,
				b->GetPosition().y * PTM_RATIO));
			spriteData->setRotation(-1 * CC_RADIANS_TO_DEGREES(b->GetAngle()));
		}


	}

}

void Test1::addNewSpriteAtPosition(Vec2 location)
{
	auto pSprite = Sprite::createWithTexture(texture, Rect(0, 0, 100, 100));
	pSprite->setPosition(Vec2(location.x, location.y));
	this->addChild(pSprite);

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(location.x / PTM_RATIO, location.y / PTM_RATIO);

	bodyDef.userData = pSprite;

	auto body = _world->CreateBody(&bodyDef);

	b2CircleShape circle;
	circle.m_radius = 0.55f;

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &circle;

	fixtureDef.density = 1.0f;

	fixtureDef.friction = 0.2f;


	fixtureDef.restitution = 0.7f;


	body->CreateFixture(&fixtureDef);

}

void Test1::onEnter()
{

	Scene::onEnter();

	//싱글 터치 모드로 이벤트리스너를 초기화 
	listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(Test1::onTouchBegan, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void Test1::Exit()
{
	_eventDispatcher->removeAllEventListeners();

	Scene::onExit();

}

bool Test1::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event)
{
	auto touchPoint = touch->getLocation();

	addNewSpriteAtPosition(touchPoint);

	return true;
}

void Test1::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * event)
{
}
