//�ִϸ��̼�?
/*
	- ���� �̹����� �����ؼ� ���� �ӵ��� ��ȯ�Ǿ�,
      ��ġ �ϳ��� �̹����� �����̴� ��ó�� �����ִ� ���

	  1. ������ ���е� ��������Ʈ���� ���� ���
	  2. ��������Ʈ ��Ʈ Ȱ�� (*.png)
	  3. .plist ������ ���� �����Ͽ� ���
	  4. vector�� ������� for���� ����� ���


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

	// 1. ������ �� ��������Ʈ�� ����Ͽ� �ִϸ��̼� ���
	auto aSprite = Sprite::create("priconne/Sprites_pecorinne/001.png");
	aSprite->setPosition(Vec2(640, 360));
	this->addChild(aSprite);

	//�ִϸ��̼� ����� ���� Animation ��ü
	//�̹��� ��ȯ�� �ʿ��� SpriteFrame�� ���� ������ �׷�ȭ�Ǿ� ����
	auto animation = Animation::create();

	//�ʴ� ������ ��� �ӵ�
	animation->setDelayPerUnit(0.05f);

	//�ִϸ��̼ǿ� ����� ������(�̹���) �߰�
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

	//SpriteFrame������ �߰��� Animation��ü�� �����Ű�� �׼�
	auto animate = Animate::create(animation);
	
	//�ִϸ��̼� ���� �ݺ�
	auto rep = RepeatForever::create(animate);

	aSprite->runAction(rep);


	//=================================================================================
	

	// 2. ��������Ʈ ��Ʈ(png)�� �̿��� �ִϸ��̼� ���
	{
		auto asSheet = Sprite::create(
			"priconne/Sprites_pecorinne/Sprites_pecorinne.png");

		//��������Ʈ ��Ʈ�� �ؽ��� ������ �޾ƿ���
		auto texture = asSheet->getTexture();

		//Animation ��ü
		auto animation = Animation::create();

		//�ʴ� ������ ��� �ӵ�
		animation->setDelayPerUnit(0.05f);

		//��������Ʈ ������ ����
		for (int i = 0; i < 18; i++)
		{
			//��������Ʈ ��Ʈ�� X��ǥ (������ ���ϱ�)
			int col = i % 6;
			//��������Ʈ ��Ʈ�� Y��ǥ (�� ���ϱ�)
			int row = i / 6;

			//�������̸� �߰� �ɰ��� �߰��Ѵ�
			animation->addSpriteFrameWithTexture
			(texture,Rect(col*300,row*300,300,300));
		}

		//�ִϸ��̼� ����� ���� ��ü(���)
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

	
	// 3. .plist�� �̿��� �ִϸ��̼� ���
	//�ܺ� ���α׷��� ����Ͽ� ���� plist������ �̿��Ͽ� �ִϸ��̼��� ����Ѵ�.
	{
		//plist�� SpriteFrameCache�� �߰�
		auto cache = SpriteFrameCache::getInstance();
		cache->addSpriteFramesWithFile
		("priconne/Sprites_pecorinne/Sprites_pecorinne.plist");


		//cocos2d::Vector
		Vector<SpriteFrame*> animFrames;

		//Vector�� SpriteFrame ����
		for (int i = 0; i < 18; i++)
		{
			//StringUtils::format() -> ������ �������� string�� ������ش�.
			std::string _frames = StringUtils::format("0%02d.png", i+1);

			//������ ���ڿ��� �̿��Ͽ� SpriteFrame�� �޾ƿ���
			SpriteFrame* frame = cache->getSpriteFrameByName(_frames);

			//���Ϳ� ����
			animFrames.pushBack(frame);
		}

		//plist�� ����Ͽ� ���� SpriteFrame ������ Ȱ���� Sprite ��ü ����
		auto animSprite = Sprite::createWithSpriteFrameName("001.png");
		animSprite->setPosition(Vec2(1024, 360));
		this->addChild(animSprite);

		//Animation ����
		auto vecAnim = Animation::createWithSpriteFrames(animFrames, 0.05f);
		auto vecAnimate = Animate::create(vecAnim);
		auto VecRep = RepeatForever::create(vecAnimate);

		animSprite->runAction(VecRep);
		

	}
	

	return true;
}
