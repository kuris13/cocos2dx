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


	//Ÿ�ϸ� ��ü �ҷ�����
	tmap = TMXTiledMap::create("TileMaps/222222.tmx");

	// Ÿ�ϸ� ���̾�
	background = tmap->getLayer("Background");
	items = tmap->getLayer("Items");
	metainfo = tmap->getLayer("MetaInfo");
	metainfo->setVisible(false);



	//Ÿ�ϸ��� z���� -1���Ϸ� �ϸ� ȭ�鿡 �� ���´�. 
	this->addChild(tmap, 0, 11);

	// Ÿ�ϸ� ���α׷����� Object��� ����� ���̾��� ���� �޾ƿ���
	auto objects = tmap->getObjectGroup("Object Layer 1");

	// SpawnPount��� ������ ������Ʈ�� ������Ƽ �޾ƿ���
	ValueMap spawnPoint = objects->getObject("SpawnPoint");

	int x = spawnPoint["x"].asInt();
	int y = spawnPoint["y"].asInt();

	//SpawnPoint ��ġ���� �巡���� ����
	dragonPosition = Vec2(x, y);

	// �巡��
	this->createDragon();




	return true;
}

void Example29::onEnter()
{
	Scene::onEnter();

	//�̱� ��ġ ���� �̺�Ʈ�����ʸ� �ʱ�ȭ 
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

	// ȭ�鿡 ��ġ�� ������ ���� �̵��� ��ġ�� ����� �� �������� ����
	// ���� ���� ȭ�麸�� ũ�� ������, ȭ�鿡�� ���� �Ϻκи� ���̴� ���� �Ϲ���.
	Vec2 playerPos = dragon->getPosition();

	// ���� ������ �Ÿ� ���ϱ�
	Vec2 diff = touchPoint - playerPos;

	// ��ǥ ������� ĳ���͸� �̵�
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
		// �巡���� ��ġ�� ��ǥ�� ��Ȯ�ϰ� ���� 
		//dragon->setPosition(playerPos);

		// �巡���� �̵��� �� ��ֹ��� ������ ó���� ���� �޼��带 ������ �����.
		this->setPlayerPosition(playerPos);
	}

	// �巡���� ��ġ�� ���缭 ȭ�鵵 ���� ����
	this->setViewPointCenter(dragon->getPosition());


}

void Example29::createDragon()
{
	// �巡�� �ִϸ��̼�
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
	// �Ű������� ������ �����ǿ� ���� ȭ���� �����δ�.
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
	// ������ ������ Ÿ���� ��ġ�� �����´�
	int x = position.x / tmap->getTileSize().width;
	int y = ( (tmap->getTileSize().height * tmap->getTileSize().height) - position.y) / tmap->getTileSize().height;

	return Vec2(x, y);
}

void Example29::setPlayerPosition(cocos2d::Vec2 position)
{
	// ��ġ�� ��ġ�� Ÿ���� Ÿ�ϸʿ��� � ��ġ�� �ִ��� ��������
	Vec2 tileCoord = this->tileCoordForPosition(position);

	// ������ ���� Ÿ���� Gid�� �޾ƿ´�.
	int tileGid = metainfo->getTileGIDAt(tileCoord);
	
	if (tileGid)
	{
		// Ÿ�ϸſ��� GID�� �ش��ϴ� �Ӽ����� ��������
		Value properties = tmap->getPropertiesForGID(tileGid);
		
		if (!properties.isNull())
		{
			// �ش� Gid�� Wall�̶�� �Ӽ��� �ִٸ� ���� ���Ѵ�.
			std::string wall = properties.asValueMap()["Wall"].asString();
			if (wall == "YES")
			{
				// Wall�� �Ӽ����� YES�� ���� �����Ƿ� �̵��� �Ұ����ϵ��� return�� ��Ų��.
				return;
			}
			// ===================================================
			// �ʿ��� �������� ��ġ�� Ÿ���� ������ �޾ƿ´� 
			std::string item1 = properties.asValueMap()["Items"].asString();
			if (item1 == "Apple")
			{
				// item1�� ��� string ���� Apple�� �ش� items, metaOnfo ���̾��� Ÿ�� ����
				this->metainfo->removeTileAt(tileCoord);
				items->removeTileAt(tileCoord);
	
				//������ ȹ�� ó��
				log("�������� ȹ���Ͽ����ϴ�");
	
	
			}
	
	
	
		}
	}
	
	
	// �Ű������� ���� ��ġ�� �巡���� ��ġ�ϱ�
	dragon->setPosition(position);

}
