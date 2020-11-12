#include "Example29.h"

cocos2d::Scene * Example29::createScene()
{

	return Example29::create();

}

bool Example29::init()
{
	if (!Scene::init()) return false;

	//winSize
	winSize = Director::getInstance()->getVisibleSize();


	//타일맵 전체 불러오기
	tmap = TMXTiledMap::create("TileMaps/222222.tmx");

	// 타일맵 레이어
	background = tmap->getLayer("Background");
	items = tmap->getLayer("Items");
	metainfo = tmap->getLayer("MetaInfo");
	metainfo->setVisible(false);



	//타일맵은 z축을 -1이하로 하면 화면에 안 나온다. 
	this->addChild(tmap, 0, 11);

	// 타일맵 프로그램에서 Object라고 명명한 레이어의 정보 받아오기
	auto objects = tmap->getObjectGroup("Object Layer 1");

	// SpawnPount라고 지정한 오브젝트의 프로퍼티 받아오기
	ValueMap spawnPoint = objects->getObject("SpawnPoint");

	int x = spawnPoint["x"].asInt();
	int y = spawnPoint["y"].asInt();

	//SpawnPoint 위치에서 드래곤을 생성
	dragonPosition = Vec2(x, y);

	// 드래곤
	this->createDragon();




	return true;
}

void Example29::onEnter()
{
	Scene::onEnter();

	//싱글 터치 모드로 이벤트리스너를 초기화 
	listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(Example29::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(Example29::onTouchEnded, this);


	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void Example29::Exit()
{

	_eventDispatcher->removeEventListener(listener);
	Scene::onExit();

}

bool Example29::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event)
{


	return true;
}

void Example29::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * event)
{
	auto touchPoint = touch->getLocation();
	touchPoint = this->convertToNodeSpace(touchPoint);

	// 화면에 터치한 지점을 맵이 이동한 위치도 고려해 맵 기준으로 재계산
	// 보통 맵이 화면보다 크기 때문에, 화면에는 맵의 일부분만 보이는 것이 일반적.
	Vec2 playerPos = dragon->getPosition();

	// 두점 사이의 거리 구하기
	Vec2 diff = touchPoint - playerPos;

	// 좌표 계산으로 캐릭터를 이동
	if (abs(diff.x) > abs(diff.y))
	{
		if (diff.x > 0)
		{
			playerPos.x += tmap->getTileSize().width;
			dragon->setFlippedX(true);
		}
		else
		{
			playerPos.x -= tmap->getTileSize().width;
			dragon->setFlippedX(false);
		}
	}
	else
	{
		if (diff.y > 0)
		{
			playerPos.y += tmap->getTileSize().height;
		}
		else
		{
			playerPos.y -= tmap->getTileSize().height;
		}


	}

	if ( playerPos.x <= (tmap->getMapSize().width * tmap->getTileSize().width)
		&& playerPos.y <= (tmap->getMapSize().height * tmap->getTileSize().height)
		&& playerPos.y >= 0
		&& playerPos.x >= 0 )
	{
		// 드래곤이 위치할 좌표를 정확하게 지정 
		//dragon->setPosition(playerPos);

		// 드래곤이 이동할 때 장애물과 아이템 처리를 위한 메서드를 별도로 만든다.
		this->setPlayerPosition(playerPos);
	}

	// 드래곤의 위치에 맞춰서 화면도 같이 조정
	this->setViewPointCenter(dragon->getPosition());


}

void Example29::createDragon()
{
	// 드래곤 애니메이션
	auto texture = Director::getInstance()->getTextureCache()->addImage("dragon_animation.png");
	
	auto animation = Animation::create();
	animation->setDelayPerUnit(0.1f);
	
	for (int i = 0; i < 6; i++)
	{
		int index = i % 4;
		int rowIndex = i / 4;
	
	
		animation->addSpriteFrameWithTexture(texture, Rect(index * 130, rowIndex * 140 + 70, 110, 70));
	
	
	}
	
	dragon = Sprite::createWithTexture(texture, Rect(0, 70, 110, 70));
	dragon->setPosition(dragonPosition);
	this->addChild(dragon);
	
	dragon->setFlippedX(true);
	dragon->setScale(0.5f);
	
	auto animate = Animate::create(animation);
	auto rep = RepeatForever::create(animate);
	dragon->runAction(rep);



}

void Example29::setViewPointCenter(cocos2d::Vec2 position)
{
	// 매개변수로 들어오는 포지션에 맞춰 화면을 움직인다.
	int x = MAX(position.x, winSize.width / 2);
	int y = MAX(position.y, winSize.height / 2);

	x = MIN(x, (tmap->getMapSize().width * tmap->getTileSize().width) - winSize.width / 2);
	y = MIN(y, (tmap->getMapSize().height * tmap->getTileSize().height) - winSize.height / 2);

	Vec2 actualPosition = Vec2(x, y);
	Vec2 centerOfView = Vec2(winSize.width / 2, winSize.height / 2);
	Vec2 viewPoint = centerOfView - actualPosition;

	this->setPosition(viewPoint);
	

}

cocos2d::Vec2 Example29::tileCoordForPosition(cocos2d::Vec2 position)
{
	// 탭으로 선택한 타일의 위치를 가져온다
	int x = position.x / tmap->getTileSize().width;
	int y = ( (tmap->getTileSize().height * tmap->getTileSize().height) - position.y) / tmap->getTileSize().height;

	return Vec2(x, y);
}

void Example29::setPlayerPosition(cocos2d::Vec2 position)
{
	// 터치된 위치의 타일이 타일맵에서 어떤 위치에 있는지 가져오기
	Vec2 tileCoord = this->tileCoordForPosition(position);

	// 위에서 구한 타일의 Gid를 받아온다.
	int tileGid = metainfo->getTileGIDAt(tileCoord);
	
	if (tileGid)
	{
		// 타일매에서 GID에 해당하는 속성값을 가져오기
		Value properties = tmap->getPropertiesForGID(tileGid);
		
		if (!properties.isNull())
		{
			// 해당 Gid에 Wall이라는 속성이 있다면 값을 구한다.
			std::string wall = properties.asValueMap()["Wall"].asString();
			if (wall == "YES")
			{
				// Wall의 속성값이 YES면 벽이 있으므로 이동이 불가능하도록 return을 시킨다.
				return;
			}
			// ===================================================
			// 맵에서 아이템이 위치한 타일의 정볼르 받아온다 
			std::string item1 = properties.asValueMap()["Items"].asString();
			if (item1 == "Apple")
			{
				// item1에 담긴 string 값이 Apple면 해당 items, metaOnfo 레이어의 타일 삭제
				this->metainfo->removeTileAt(tileCoord);
				items->removeTileAt(tileCoord);
	
				//아이템 획득 처리
				log("아이템을 획득하였습니다");
	
	
			}
	
	
	
		}
	}
	
	
	// 매개변수로 들어온 위치에 드래곤을 위치하기
	dragon->setPosition(position);

}
