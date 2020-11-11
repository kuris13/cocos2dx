//애니메이션?
/*
	- 여러 이미지를 연속해서 빠른 속도로 전환되어,
      마치 하나의 이미지가 움직이는 것처럼 보여주는 기술

	  1. 낱개로 구분된 스프라이트들을 순차 재생
	  2. 스프라이트 시트 활용 (*.png)
	  3. .plist 파일을 직접 제작하여 재생
	  4. vector와 범위기반 for문을 사용한 재생


*/

#include "Example05.h"

USING_NS_CC;

cocos2d::Scene * Example05::createScene()
{
	return Example05::create();
}

bool Example05::init()
{
	if (!Scene::init())
	{
		return false;
	}

	// 1. 낱개로 된 스프아이트를 사용하여 애니메이션 재생
	auto aSprite = Sprite::create("priconne/Sprites_pecorinne/001.png");
	aSprite->setPosition(Vec2(640, 360));
	this->addChild(aSprite);

	//애니메이션 재생을 위한 Animation 객체
	//이미지 전환에 필요한 SpriteFrame과 관련 정보가 그룹화되어 있음
	auto animation = Animation::create();

	//초당 프레임 재생 속도
	animation->setDelayPerUnit(0.05f);

	//애니메이션에 사용할 프레임(이미지) 추가
	{
		animation->addSpriteFrameWithFile("priconne/Sprites_pecorinne/001.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_pecorinne/002.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_pecorinne/003.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_pecorinne/004.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_pecorinne/005.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_pecorinne/006.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_pecorinne/007.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_pecorinne/008.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_pecorinne/009.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_pecorinne/010.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_pecorinne/011.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_pecorinne/012.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_pecorinne/013.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_pecorinne/014.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_pecorinne/015.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_pecorinne/016.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_pecorinne/017.png");
		animation->addSpriteFrameWithFile("priconne/Sprites_pecorinne/018.png");

	}

	//SpriteFrame정보가 추가된 Animation객체를 재생시키는 액션
	auto animate = Animate::create(animation);
	
	//애니메이션 무한 반복
	auto rep = RepeatForever::create(animate);

	aSprite->runAction(rep);


	//=================================================================================
	

	// 2. 스프라이트 시트(png)를 이용한 애니메이션 재생
	{
		auto asSheet = Sprite::create(
			"priconne/Sprites_pecorinne/Sprites_pecorinne.png");

		//스프라이트 시트의 텍스쳐 정보를 받아오기
		auto texture = asSheet->getTexture();

		//Animation 객체
		auto animation = Animation::create();

		//초당 프레임 재생 속도
		animation->setDelayPerUnit(0.05f);

		//스프라이트 프레임 추출
		for (int i = 0; i < 18; i++)
		{
			//스프라이트 시트의 X좌표 (나머지 구하기)
			int col = i % 6;
			//스프라이트 시트의 Y좌표 (몫 구하기)
			int row = i / 6;

			//스프라이를 잘게 쪼개어 추가한다
			animation->addSpriteFrameWithTexture
			(texture,Rect(col*300,row*300,300,300));
		}

		//애니메이션 재생을 위한 객체(토대)
		auto pSprite = Sprite::create
		("priconne/Sprites_pecorinne/Sprites_pecorinne.png",
			Rect(0,0,300,300));
		pSprite->setPosition(Vec2(240, 360));
		this->addChild(pSprite);

		auto animate = Animate::create(animation);
		auto rep = RepeatForever::create(animate);
		pSprite->runAction(rep);

	}


	//==================================================

	
	// 3. .plist를 이용한 애니메이션 재생
	//외부 프로그램을 사용하여 만든 plist파일을 이용하여 애니메이션을 재생한다.
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
			std::string _frames = StringUtils::format("0%02d.png", i+1);

			//추출한 문자열을 이용하여 SpriteFrame을 받아오기
			SpriteFrame* frame = cache->getSpriteFrameByName(_frames);

			//벡터에 삽입
			animFrames.pushBack(frame);
		}

		//plist를 기반하여 만든 SpriteFrame 정보를 활용해 Sprite 객체 생성
		auto animSprite = Sprite::createWithSpriteFrameName("001.png");
		animSprite->setPosition(Vec2(1024, 360));
		this->addChild(animSprite);

		//Animation 설정
		auto vecAnim = Animation::createWithSpriteFrames(animFrames, 0.05f);
		auto vecAnimate = Animate::create(vecAnim);
		auto VecRep = RepeatForever::create(vecAnimate);

		animSprite->runAction(VecRep);
		

	}
	

	return true;
}
