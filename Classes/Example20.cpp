
//배경 스크롤
/*
	1. 배경을 왼쪽 혹은 오른쪽으로 스크롤하는 방법
	 - 단순하게 큰 이미지를 움직여주기만 하면 된다.
	 - 이렇게 해도 보는 사람은 디바이스의 화면만 계속 주시하기 때문에
	  마치 화면이 스스로 스크롤되는 것처럼 보인다.

	2. 안정적인 동작을 보장하는 이미지 사이즈
	 - win32 : 2048 x 2048 까지
	 - Android : 4096 x 4096 까지
	 - IPhone 3 이전 : 1024 x 1024 까지
	 - IPhone 3 이후 : 2048 x 2048 까지

	이미지 사이즈가 시뮬레이터에서는 아무런 상관이 없으나,
	특정 디바이스에서 정상적으로 동작할 거라는 보장은 못한다.

	이런 문제를 예방하고 모든 디바이스에서 작동하도록 프로그래밍한다면,
	기준이 되는 크기는 가장 작은 사이즈가 된다.
	그래도 최근에는 웬만하면 2048 x 2048를 지원한다.

*/


#include "Example20.h"

USING_NS_CC;

cocos2d::Scene * Example20::createScene()
{
	return Example20::create();
}

bool Example20::init()
{
	if(!Scene::init()) return false;


	//레이어 1: 배경
	layer1 = Layer::create();
	this->addChild(layer1);

	//레이어 2: UI
	layer2 = Layer::create();
	this->addChild(layer2);

	//화살표와 배경, 그리고 캐릭터 객체 만들기
	this->createArrowButtons();
	this->createBackground();
	this->createCharacter();



	return true;
}

void Example20::createBackground()
{
	//배경 스프라이트 삽입
	auto background1 = Sprite::create("priconne/background1.png");
	background1->setAnchorPoint(Vec2::ZERO);
	background1->setPosition(Vec2(0, -480));

	auto background2 = Sprite::create("priconne/background2.png");
	background2->setAnchorPoint(Vec2::ZERO);
	background2->setPosition(Vec2(960, -480));

	//배경 전용 레이어에 addChild
	layer1->addChild(background1);
	layer1->addChild(background2);
	
	/*
	//계단 설정 
	background1->getTexture()->setAliasTexParameters();

	//안티 얼라이징 설정
	background1->getTexture()->setAntiAliasTexParameters();
	*/

}

void Example20::createCharacter()
{
	//plist를 SpriteFrameCache에 추가
	auto cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile
	("priconne/Sprites_pecorinne/Sprites_pecorinne.plist");


	//cocos2d::Vector
	Vector<SpriteFrame*> animFrames;

	//Vector에 SpriteFrame 삽입
	for (int i = 0; i < 18; i++)
	{
		//StringUtils::format() -> 지정된 형식으로 string을 만들어준다.
		std::string _frames = StringUtils::format("0%02d.png", i + 1);

		//추출한 문자열을 이용하여 SpriteFrame을 받아오기
		SpriteFrame* frame = cache->getSpriteFrameByName(_frames);

		//벡터에 삽입
		animFrames.pushBack(frame);
	}

	//plist를 기반하여 만든 SpriteFrame 정보를 활용해 Sprite 객체 생성
	animSprite = Sprite::createWithSpriteFrameName("001.png");
	animSprite->setPosition(Vec2(640,360));
	layer1->addChild(animSprite,1);

	//Animation 설정
	auto vecAnim = Animation::createWithSpriteFrames(animFrames, 0.05f);
	auto vecAnimate = Animate::create(vecAnim);
	auto VecRep = RepeatForever::create(vecAnimate);

	animSprite->runAction(VecRep);


}

void Example20::createArrowButtons()
{
	//왼쪽 화살표 idle
	leftChevron = Sprite::create("ui/b1.png");
	leftChevron->setPosition(Vec2(440, 100));
	layer2->addChild(leftChevron,2);
	

	//왼족 화살표 selected
	leftChevronPressed = Sprite::create("ui/b2.png");
	leftChevronPressed->setPosition(Vec2(440, 100));
	layer2->addChild(leftChevronPressed, 1);

	//오른쪽 화살표
	rightChevron = Sprite::create("ui/f1.png");
	rightChevron->setPosition(Vec2(840, 100));
	layer2->addChild(rightChevron, 2);

	//오른쪽 화살표
	rightChevronPressed = Sprite::create("ui/f2.png");
	rightChevronPressed->setPosition(Vec2(840, 100));
	layer2->addChild(rightChevronPressed, 1);

}

void Example20::onEnter()
{

	Scene::onEnter();

	//싱글 터치 모드로 이벤트리스너를 초기화 
	_listener = EventListenerTouchOneByOne::create();

	_listener->setSwallowTouches(true);

	//이벤트 리스터를 통해 실행한 콜백함수 연결
	_listener->onTouchBegan = CC_CALLBACK_2(Example20::onTouchBegan, this);
	_listener->onTouchMoved = CC_CALLBACK_2(Example20::onTouchMoved, this);
	_listener->onTouchEnded = CC_CALLBACK_2(Example20::onTouchEnded, this);

	//터치 이벤트의 우선 순위를 화면에 그려진 순서대로 한다.
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener, this);
}

void Example20::onExit()
{


	_eventDispatcher->removeEventListener(_listener);
	Scene::onExit();
}

bool Example20::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event)
{
	isLeftPressed = false;
	isRightPressed = false;

	//터치가 화살표 스프라이트 안에서 실행됐는지 검사
	if (this->isTouchInside(leftChevron, touch))
	{
		//판정이 true가 놔왔으면 idle 이미지를 안 보이게 만든다.
		leftChevron->setVisible(false);
		isLeftPressed = true;

		animSprite->setFlippedX(true);
	}
	else if (this->isTouchInside(rightChevron, touch))
	{
		rightChevron->setVisible(false);
		isRightPressed = true;

		animSprite->setFlippedX(false);
	}

	//화살표를 눌렀을 때 화면을 움지이게 만든다.
	if (isLeftPressed || isRightPressed)
	{
		this->startMovingBackground();
	}

	return true;

}

void Example20::onTouchMoved(cocos2d::Touch * touch, cocos2d::Event * event)
{
	//버튼을 누른 상태로 좌표를 벗어나면 상태 초기화
	if (isLeftPressed && !this->isTouchInside(leftChevron, touch))
	{
		leftChevron->setVisible(true);
		this->stopMovingBackground();
	}
	else if (isRightPressed && !this->isTouchInside(rightChevron, touch))
	{
		rightChevron->setVisible(true);
		this->stopMovingBackground();
	}




}

void Example20::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * event)
{
	//베경화면 이동을 멈추기
	if (isLeftPressed || isRightPressed)
	{
		this->stopMovingBackground();
	}

	if (isLeftPressed)
	{
		leftChevron->setVisible(true);
	}
	else if (isRightPressed)
	{
		rightChevron->setVisible(true);
	}


}

bool Example20::isTouchInside(cocos2d::Sprite * sprite, cocos2d::Touch * touch)
{
	auto touchPoint = touch->getLocation();
	bool bTouch = sprite->getBoundingBox().containsPoint(touchPoint);


	return bTouch;
}

void Example20::startMovingBackground()
{
	if (isLeftPressed && isRightPressed)
	{
		//만약 버튼 2개를 동시에 누르는 경우
		return;
	}
	
	//스케줄을 이용하여 매 프레임마다 배경화면 위치를 갱신하게 만들어준다.
	this->schedule(schedule_selector(Example20::moveBackground));


}

void Example20::stopMovingBackground()
{
	//unscaedule을 이용하여 배경화면 위치 이동을 종료한다.
	this->unschedule(schedule_selector(Example20::moveBackground));
}

void Example20::moveBackground(float t)
{
	//매 프레임마다 캐릭터가 이동할 거리 설정
	int move = 0;
	
	//선택한 방향에 따라 캐릭터의 이동량을 지정
	if (isLeftPressed)
	{
		move = -5;
		animSprite->setFlippedX(true);	//큰 의미 x
	}
	else
	{
		move = 5;
		animSprite->setFlippedX(false);
	}

	//좌우 이동 값을 적용한 Vec2 객체
	auto resetPosition = Vec2(animSprite->getPositionX() + move, animSprite->getPositionY());

	//배경 이미지를 캐릭터 스프라이트가 벗어나지 않도록 예외처리
	if (resetPosition.x < 0)
	{
		resetPosition.x = 0;
	}
	else if (resetPosition.x > 960 * 2)
	{
		resetPosition.x = 960 * 2;
	}

	//세부 조정된 좌표를 스프라이트에 대입
	animSprite->setPosition(resetPosition);

	//스프라이트의 좌표에 맞춰 배경 스프라이트 이동
	auto follow = Follow::create(animSprite, Rect(0, 0, 960 * 2, 720));
	layer1->runAction(follow);

}


// Follow 액션
/*
	Follow::create(followNodem cocos2d::Rect(x1,y1,x2,y2));

	followNode : 카메라가 따라다닐 객체를 설정한다.
	cocos2d::Rect : 카메라의 이동 범위, 카메라가 이동할 수 있는 범위 내에서는 자동으로 객체를 화면의 중심에 둔다.
*/