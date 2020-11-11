#include "Example07.h"

USING_NS_CC;

cocos2d::Scene * Example07::createScene()
{
	return Example07::create();
}

bool Example07::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto item1 = MenuItemFont::create(
		"Pause", CC_CALLBACK_1(Example07::doClick, this));
	auto item2 = MenuItemFont::create(
		"Resume", CC_CALLBACK_1(Example07::doClick, this));
	auto item3 = MenuItemFont::create(
		"shut Down", CC_CALLBACK_1(Example07::doClick, this));
	item1->setTag(1);
	item2->setTag(2);
	item3->setTag(3);

	auto pMenu = Menu::create(item1, item2, item3,nullptr);
	pMenu->alignItemsHorizontallyWithPadding(50.0f);
	this->addChild(pMenu);

	//======================================================

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
			std::string _frames = StringUtils::format("0%02d.png", i + 1);

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


	



	return true;
}

void Example07::doClick(Ref * pSender)
{
	auto tag = (MenuItem*)pSender;
	int i = tag->getTag();

	if (i == 1)
	{
		//�Ͻ�����
		Director::getInstance()->pause();

	}
	else if (i == 2)
	{
		//�����
		Director::getInstance()->resume();
	}
	else if (i == 3)
	{
		//���α׷� ����
		Director::getInstance()->end();
	}


}
