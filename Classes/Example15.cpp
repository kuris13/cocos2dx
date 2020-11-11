//��ƼŬ ( particle )
/*
	���� �׷��ȵ��� ���� ����ü
	����, ����, ����, ����, ���� ȿ���� ���� ��������Ʈ�� ǥ���ϱ� ���� ȿ��.
*/


#include "Example15.h"

USING_NS_CC;

cocos2d::Scene * Example15::createScene()
{
	return Example15::create();
}

bool Example15::init()
{
	if(!Scene::init()) return false;

	//MenuItem
	auto item1 = MenuItemFont::create("Normal Particle",
		CC_CALLBACK_1(Example15::showParticle,this));
	auto item2 = MenuItemFont::create("Import Particle",
		CC_CALLBACK_1(Example15::importParticle, this));

	auto pMenu = Menu::create(item1, item2, nullptr);
	pMenu->setPosition(Vec2(256, 360));
	pMenu->alignItemsVertically();
	this->addChild(pMenu);




	return true;
}

void Example15::showParticle(Ref * pSender)
{
	//����Ʈ�� ��Ʈ�� ��ġ�� �� �����ϱ� ���� RemoveChildByTag
	this->removeChildByTag(10);
	this->removeChildByTag(20);

	//ī��Ʈ�� ����
	static int nIndex = 0;

	//�ڵ� ������ϱ� �������� ���� �и�
	auto dir = Director::getInstance();

	//==================================================

	//��ƼŬ �ý����� ����
	//��ƼŬ �ý��۰� ��ƼŬ�� ����� �ؽ�ó, ���� ��ƼŬ���� ǥ������ ���̺�
	ParticleSystem* particle;
	Texture2D* texture;
	Label* name;

	//cocos2d-x ���� ��ƼŬ ����Ʈ
	switch (nIndex)
	{
	case 0:
		//��ں��� ����� �� ����
		particle = ParticleFire::create();
		texture = dir->getTextureCache()->addImage("particles/fire.png");
		name = Label::createWithSystemFont("Fire", "", 30);
		break;
	case 1:
		//�¾�
		particle = ParticleSun::create();
		texture = dir->getTextureCache()->addImage("particles/fire.png");
		name = Label::createWithSystemFont("Sun", "", 30);
		break;
	case 2:
		//����
		particle = ParticleGalaxy::create();
		texture = dir->getTextureCache()->addImage("particles/fire.png");
		name = Label::createWithSystemFont("Galaxy", "", 30);
		break;
	case 3:
		//����
		particle = ParticleSpiral::create();
		texture = dir->getTextureCache()->addImage("particles/fire.png");
		name = Label::createWithSystemFont("Spiral", "", 30);
		break;
	case 4:
		//����
		particle = ParticleSmoke::create();
		texture = dir->getTextureCache()->addImage("particles/fire.png");
		name = Label::createWithSystemFont("Fire", "", 30);
		break;
	case 5:
		//����
		particle = ParticleMeteor::create();
		texture = dir->getTextureCache()->addImage("particles/fire.png");
		name = Label::createWithSystemFont("Meteor", "", 30);
		break;
	case 6:
		//��
		particle = ParticleFlower::create();
		texture = dir->getTextureCache()->addImage("particles/stars.png");
		name = Label::createWithSystemFont("Flower", "", 30);
		break;
	case 7:
		//����
		particle = ParticleFireworks::create();
		texture = dir->getTextureCache()->addImage("particles/stars.png");
		name = Label::createWithSystemFont("Fireworks", "", 30);
		break;
	case 8:
		//����
		particle = ParticleExplosion::create();
		texture = dir->getTextureCache()->addImage("particles/stars.png");
		name = Label::createWithSystemFont("Explosion", "", 30);

		break;
	}

	//ī��Ʈ ���� ����
	++nIndex;
	if (nIndex > 8) nIndex = 0;

	//particle ��ü�� ������ �ؽ�ó ( �̹��� )�� ����
	particle->setTexture(texture);

	//particle ��ü�� nullptr�� �ƴ� �� ������ �ǵ��� �Ѵ�.
	if (particle != nullptr)
	{
		//��ƼŬ�� ������
		particle->setScale(1.5f);

		//��ƼŬ�� ���ӽð� ( -1�� �����ϸ� ���� �ݺ� )
		particle->setDuration(2.0f);

		particle->setPosition(Vec2(640, 360));
		particle->setTag(10);

		name->setPosition(Vec2(640, 480));
		name->setTag(20);

		this->addChild(particle);
		this->addChild(name);

	}

}

void Example15::importParticle(Ref * pSender)
{
	//Ŀ���� ��ƼŬ ����Ʈ
	//http://particle2dx.com/

		//����Ʈ�� ��Ʈ�� ��ġ�� �� �����ϱ� ���� RemoveChildByTag
	this->removeChildByTag(10);
	this->removeChildByTag(20);


	static int nIndex = 0;
	Label* name;
	char* fileName = "";

	switch (nIndex)
	{
	case 0:
		fileName = "particles/particle_texture.plist";
		name = Label::createWithSystemFont("Import File", "", 30);
		break;
	}

	++nIndex;
	if (nIndex > 0) nIndex = 0;

	ParticleSystem* particle = ParticleSystemQuad::create(fileName);
	particle->setPosition(Vec2(640, 360));
	particle->setTag(10);
	particle->setDuration(2.0f);
	particle->setAutoRemoveOnFinish(true);

	name->setPosition(Vec2(640, 460));
	name->setTag(20);

	this->addChild(particle);
	this->addChild(name);

}
