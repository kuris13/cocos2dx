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

	//��������Ʈ

	pSprite = Sprite::create("priconne/mv_img_kyaru.png");
//	pSprite = AutoPolygon::generatePolygon("priconne/mv_img_kyaru.png");
	pSprite->setFlippedX(true);
	pSprite->setPosition(Vec2(640, 360));
	this->addChild(pSprite);


	//źȯ����
	this->createBullet();

	//�浹üũ
	this->schedule(schedule_selector(Example08::collision));


	return true;
}

void Example08::createBullet()
{
	//źȯ ����
	pBullet = Sprite::create("ui/sliderThumb.png");
	pBullet->setPosition(Vec2(0, 360));
	this->addChild(pBullet);

	auto myActionForWard = MoveBy::create(1.5f, Vec2(864, 0));
	auto rep = RepeatForever::create(myActionForWard);

	pBullet->runAction(rep);
}

void Example08::collision(float dt)
{
	//pBullet�� �� ���� nullptr�� ���
	if (pBullet == nullptr)
	{
		//źȯ �����
		this->createBullet();
		return;
	}

	//ĳ���Ϳ� ź�� �浹�ߴ��� �˻�
	auto collision = pBullet->getBoundingBox().intersectsRect(pSprite->getBoundingBox());

	if (collision)
	{
		log("collision checked!");

		//�ִϸ��̼��̳� �׼��� ������ ������ �� �ڱ��ڽ��� ����
		pBullet->removeFromParentAndCleanup(true);
		//���� ������ ������ ���� �� �����Ⱚ�� ������
		pBullet = nullptr;
	}

	
}
