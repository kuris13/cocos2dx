#include "Example0903.h"

USING_NS_CC;

cocos2d::Scene * Example0903::createScene()
{
	return Example0903::create();
}

bool Example0903::init()
{
	if(!Scene::init()) return false;

	auto aa = AutoPolygon::generatePolygon("priconne/mv_img_peco.png");


	pSprite[0] = Sprite::create(aa);
	pSprite[0]->setPosition(Vec2(640,360));
	this->addChild(pSprite[0]);

	pSprite[1] = Sprite::create("priconne/mv_img_kyaru.png");
	pSprite[1]->setPosition(Vec2(256,360));
	this->addChild(pSprite[1]);

	pSprite[2] = Sprite::create("priconne/mv_img_kokkoro.png");
	pSprite[2]->setPosition(Vec2(864,360));
	this->addChild(pSprite[2]);


	return true;
}

void Example0903::onEnter()
{
	Scene::onEnter();

	_listener = EventListenerTouchOneByOne::create();
	_listener->setSwallowTouches(true);

	//람다식 ( Lambda Expressions )
	/*
		1. 정의
		 - 간이 함수를 즉석에서 정의하여 별도 선언 없이 인라인 함수처럼 사용

		2. 구조
		 [캡처](매개변수){실행코드};

		3. 캡처 블록
		 [   ] : 외부 변수 사용 않겠다.
		 [ = ] : 파라미터(매개변수)로 설정한 값을 복사해서 람다식 내부에서 사용
	*/

	//람다식을 이용한 터치 이벤트 콜백함수 작성
	_listener->onTouchBegan = [=](Touch* touch, Event* event)
	{
		//getCurrentTarget() : 터치 이벤트에 반응한 모든 타겟의 정보를 받아온다.
		//무슨 자료형의 포인터를 얻을 것인지, 혹은 터치하기 전에 미리 태그를 부여해서 어떤 노드를
		//받아올 것인지에 대해 포커스를 좁혀야 한다.
		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		//convertToNodeSpace() : 인자값을 특정 노드 기준의 좌표값으로 변경해준다.
		//world Space에서 local Space로 바꾸는 것!
		Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());

		//타겟의 크기를 받아와 가상의 Rect를 생성
		Size s = target->getContentSize();
		Rect rect = Rect(0, 0, s.width, s.height);

		//만약 터치한 곳이 Rect랑 겹칠 경우
		if (rect.containsPoint(locationInNode))
		{
			//터치한 타겟의 Z값을 바꾼다.
			changeZOrder(target);

			//터치한 타겟의 투명도를 바꾼다.
			target->setOpacity(128);
			
			return true;
		}


		return false;
	};

	_listener->onTouchMoved = [](Touch* touch, Event* event)
	{
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		//getDelta() : 스크린 터치상의 좌표를 받아오는 것!
		//현재 좌표 - 이전좌표 한 것!
		target->setPosition(target->getPosition() + touch->getDelta());


	};

	_listener->onTouchEnded = [=](Touch* touch, Event* event)
	{
		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		target->setOpacity(255);


	};

	//해당 스파라이트를 터치했을 때, 해당 이미지만 선택되게 하기 위한 내용
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener, pSprite[0]);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener->clone(), pSprite[1]);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener->clone(), pSprite[2]);
}

void Example0903::onExit()
{
	//모든 이벤트 리스너 삭제
	_eventDispatcher->removeAllEventListeners();

	Scene::onExit();
}

void Example0903::changeZOrder(cocos2d::Sprite * sprite)
{
	//모든 객체의 z축을 초기화
	for (int i = 0; i < 3; i++)
	{
		pSprite[i]->setZOrder(0);
	}

	//터치된 객체만 별도 설정
	sprite->setLocalZOrder(1);

}
