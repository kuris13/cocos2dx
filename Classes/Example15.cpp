//파티클 ( particle )
/*
	작은 그래픽들이 모인 집합체
	연기, 연소, 폭발, 궤적, 날씨 효과와 같이 스프라이트로 표현하기 힘든 효과.
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
	//이펙트와 폰트가 겹치는 걸 방지하기 위해 RemoveChildByTag
	this->removeChildByTag(10);
	this->removeChildByTag(20);

	//카운트용 변수
	static int nIndex = 0;

	//코드 길어지니까 가독성을 위해 분리
	auto dir = Director::getInstance();

	//==================================================

	//파티클 시스템의 선언
	//파티클 시스템과 파티클에 사용할 텍스처, 무슨 파티클인지 표시해줄 레이블
	ParticleSystem* particle;
	Texture2D* texture;
	Label* name;

	//cocos2d-x 내장 파티클 이펙트
	switch (nIndex)
	{
	case 0:
		//모닥불으 모습을 한 무언가
		particle = ParticleFire::create();
		texture = dir->getTextureCache()->addImage("particles/fire.png");
		name = Label::createWithSystemFont("Fire", "", 30);
		break;
	case 1:
		//태양
		particle = ParticleSun::create();
		texture = dir->getTextureCache()->addImage("particles/fire.png");
		name = Label::createWithSystemFont("Sun", "", 30);
		break;
	case 2:
		//성운
		particle = ParticleGalaxy::create();
		texture = dir->getTextureCache()->addImage("particles/fire.png");
		name = Label::createWithSystemFont("Galaxy", "", 30);
		break;
	case 3:
		//나선
		particle = ParticleSpiral::create();
		texture = dir->getTextureCache()->addImage("particles/fire.png");
		name = Label::createWithSystemFont("Spiral", "", 30);
		break;
	case 4:
		//연기
		particle = ParticleSmoke::create();
		texture = dir->getTextureCache()->addImage("particles/fire.png");
		name = Label::createWithSystemFont("Fire", "", 30);
		break;
	case 5:
		//유성
		particle = ParticleMeteor::create();
		texture = dir->getTextureCache()->addImage("particles/fire.png");
		name = Label::createWithSystemFont("Meteor", "", 30);
		break;
	case 6:
		//꽃
		particle = ParticleFlower::create();
		texture = dir->getTextureCache()->addImage("particles/stars.png");
		name = Label::createWithSystemFont("Flower", "", 30);
		break;
	case 7:
		//폭죽
		particle = ParticleFireworks::create();
		texture = dir->getTextureCache()->addImage("particles/stars.png");
		name = Label::createWithSystemFont("Fireworks", "", 30);
		break;
	case 8:
		//폭발
		particle = ParticleExplosion::create();
		texture = dir->getTextureCache()->addImage("particles/stars.png");
		name = Label::createWithSystemFont("Explosion", "", 30);

		break;
	}

	//카운트 변수 조정
	++nIndex;
	if (nIndex > 8) nIndex = 0;

	//particle 객체에 적용할 텍스처 ( 이미지 )를 지정
	particle->setTexture(texture);

	//particle 객체가 nullptr이 아닐 때 생성이 되도록 한다.
	if (particle != nullptr)
	{
		//파티클의 사이즈
		particle->setScale(1.5f);

		//파티클의 지속시간 ( -1로 설정하면 무한 반복 )
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
	//커스텀 파티클 이펙트
	//http://particle2dx.com/

		//이펙트와 폰트가 겹치는 걸 방지하기 위해 RemoveChildByTag
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
