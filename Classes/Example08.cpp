#include "Example08.h"

USING_NS_CC;

cocos2d::Scene * Example08::createScene()
{
	return Example08::create();
}

bool Example08::init()
{
	if (!Scene::init())
	{
		return false;
	}

	//스프라이트

	pSprite = Sprite::create("priconne/mv_img_kyaru.png");
//	pSprite = AutoPolygon::generatePolygon("priconne/mv_img_kyaru.png");
	pSprite->setFlippedX(true);
	pSprite->setPosition(Vec2(640, 360));
	this->addChild(pSprite);


	//탄환생성
	this->createBullet();

	//충돌체크
	this->schedule(schedule_selector(Example08::collision));


	return true;
}

void Example08::createBullet()
{
	//탄환 생성
	pBullet = Sprite::create("ui/sliderThumb.png");
	pBullet->setPosition(Vec2(0, 360));
	this->addChild(pBullet);

	auto myActionForWard = MoveBy::create(1.5f, Vec2(864, 0));
	auto rep = RepeatForever::create(myActionForWard);

	pBullet->runAction(rep);
}

void Example08::collision(float dt)
{
	//pBullet에 들어간 값이 nullptr일 경우
	if (pBullet == nullptr)
	{
		//탄환 재생성
		this->createBullet();
		return;
	}

	//캐릭터와 탄이 충돌했는지 검사
	auto collision = pBullet->getBoundingBox().intersectsRect(pSprite->getBoundingBox());

	if (collision)
	{
		log("collision checked!");

		//애니메이션이나 액션을 완전히 정지한 뒤 자기자신을 제거
		pBullet->removeFromParentAndCleanup(true);
		//전역 변수는 삭제가 됬을 때 쓰레기값이 들어가버림
		pBullet = nullptr;
	}

	
}
