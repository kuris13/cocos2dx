#include "hw02.h"

USING_NS_CC;


cocos2d::Scene * hw02::createScene()
{
	return hw02::create();
}

bool hw02::init()
{
	if(!Scene::init()) return false;


	auto bg = Sprite::create("priconne/page_bg.jpg");
	bg->setPosition(640, 360);
	this->addChild(bg);

	box = Sprite::create("priconne/guildList.png");
	box->setPosition(1050, 140);
	box->setScale(0.8f, 0.25f);
	box->setTag(1);
	this-> addChild(box);

	moveBox = Sprite::create("priconne/Icons/kyaru_summer_Icon.png");
	moveBox->setPosition(640, 560);
	this->addChild(moveBox);


	TTFConfig ttfConfig("fonts/Scissor Cuts.ttf", 40);

	ttfConfig.outlineSize = 3;
	ttfConfig.bold = true;
	auto txt1 = Label::createWithTTF(
		ttfConfig, "<- put the profile Image in the box");
	txt1->setPosition(moveBox->getPosition().x+350, moveBox->getPosition().y);
	txt1->setColor(Color3B::WHITE);
	txt1->enableBold();
	txt1->enableOutline(Color4B::RED);
	this->addChild(txt1);


	//================================================================================

	kyarl = Sprite::create("priconne/Sprites_kyarl/001.png");
	kyarl->setPosition(Vec2(400, 300));
	this->addChild(kyarl);

	//애니메이션 재생을 위한 Animation 객체
	//이미지 전환에 필요한 SpriteFrame과 관련 정보가 그룹화되어 있음
	auto animation = Animation::create();

	//초당 프레임 재생 속도
	animation->setDelayPerUnit(0.05f);

	//애니메이션에 사용할 프레임(이미지) 추가
	{
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/001.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/002.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/003.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/004.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/005.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/006.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/007.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/008.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/009.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/010.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/011.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/012.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/013.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/014.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/015.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/016.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/017.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/018.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/019.png");

	}


	//=================================================================================

	ttfConfig.outlineSize = 3;
	ttfConfig.bold = true;
	auto txt2 = Label::createWithTTF(
		ttfConfig, "It runs When profile Image placed in the box");
	txt2->setPosition(kyarl->getPosition().x,kyarl->getPosition().y-150);
	txt2->setColor(Color3B::WHITE);
	txt2->enableBold();
	txt2->enableOutline(Color4B::RED);
	this->addChild(txt2);



	//SpriteFrame정보가 추가된 Animation객체를 재생시키는 액션
	
	





	return true;
}

void hw02::onEnter()
{
	Scene::onEnter();

	_listener = EventListenerTouchOneByOne::create();
	_listener->setSwallowTouches(true);

	_listener->onTouchBegan = CC_CALLBACK_2(hw02::onTouchBegan, this);
	_listener->onTouchMoved = CC_CALLBACK_2(hw02::onTouchMoved, this);
	_listener->onTouchEnded = CC_CALLBACK_2(hw02::onTouchEnded, this);


	
	//해당 스파라이트를 터치했을 때, 해당 이미지만 선택되게 하기 위한 내용
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener, moveBox);

}

void hw02::onExit()
{
	//모든 이벤트 리스너 삭제
	_eventDispatcher->removeAllEventListeners();

	Scene::onExit();
}

bool hw02::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event)
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
		//터치한 타겟의 투명도를 바꾼다.
		target->setOpacity(128);

		return true;
	}


	return false;
}

void hw02::onTouchMoved(cocos2d::Touch * touch, cocos2d::Event * event)
{
	auto target = static_cast<Sprite*>(event->getCurrentTarget());
	//getDelta() : 스크린 터치상의 좌표를 받아오는 것!
	//현재 좌표 - 이전좌표 한 것!
	target->setPosition(target->getPosition() + touch->getDelta());
}

void hw02::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * event)
{
	auto target = static_cast<Sprite*>(event->getCurrentTarget());

	//터치한 곳의 좌표 받아오기
	auto touchPoint = touch->getLocation();
	

	bool colision = box->getBoundingBox().containsPoint(touchPoint);
	if (colision)
	{
		target->setPosition(box->getPosition());

		target->setOpacity(255);
		setAnim();

		return;
	}

	kyarl->stopAllActions();
	target->setOpacity(255);
}

void hw02::setAnim()
{
	auto animation = Animation::create();

	//초당 프레임 재생 속도
	animation->setDelayPerUnit(0.05f);

	//애니메이션에 사용할 프레임(이미지) 추가
	{
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/001.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/002.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/003.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/004.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/005.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/006.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/007.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/008.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/009.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/010.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/011.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/012.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/013.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/014.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/015.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/016.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/017.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/018.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_kyarl/019.png");

	}

	auto animate = Animate::create(animation);

	//애니메이션 무한 반복
	auto rep = RepeatForever::create(animate);
	
	kyarl->stopAllActions();
	kyarl->runAction(rep);

}
