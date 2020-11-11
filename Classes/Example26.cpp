#include "Example26.h"

USING_NS_CC;

Example26::Example26() : _numAllSprites(17),_LoadedNowSprites(0)
{

}

cocos2d::Scene * Example26::createScene()
{
	return Example26::create();
}

bool Example26::init()
{
	if(!Scene::init())  return false;

	auto visibleSize = Director::getInstance()->getVisibleSize();

	//==========================================
	_loadingLabel = Label::createWithSystemFont("로딩....", "", 36);
	_percentLabel = Label::createWithSystemFont("0", "", 36);

	_loadingLabel->setPosition(Vec2(visibleSize.width -128,visibleSize.height)*0.5f);
	_percentLabel->setPosition(Vec2(visibleSize.width + 128, visibleSize.height)*0.5f);


	this->addChild(_loadingLabel);
	this->addChild(_percentLabel);


	//==========================================
	
	//callfunc
	auto path = CC_CALLBACK_0(Example26::loadingCallFunc, this);

	auto cache = Director::getInstance()->getTextureCache();


	cache->addImageAsync("priconne/backgrounds/@char1.jpg", path);
	cache->addImageAsync("priconne/backgrounds/@char2.jpg", path);
	cache->addImageAsync("priconne/backgrounds/@char3.jpg", path);
	cache->addImageAsync("priconne/backgrounds/@char4.jpg", path);






	return true;
}

void Example26::addSprite()
{
	//로딩할 때마다 스프라이트 연출을 하고 싶은 경우 사용하는 함수


}

void Example26::SceneTransition()
{
	//로딩이 완료되었을 때 사용하는 함수

}

void Example26::loadingCallFunc()
{
	++_LoadedNowSprites;

	auto str = StringUtils::format(
		"%d",
		(int)(((float)_LoadedNowSprites / _numAllSprites) * 100)
	);

	std::string value = str;

	_percentLabel->setString(str);

	//로딩이 완료되면 씬 전환 함수를 호출
	if (_LoadedNowSprites == _numAllSprites)
	{
		SceneTransition();
	}
}
