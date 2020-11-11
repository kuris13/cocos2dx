#pragma once
#include "cocos2d.h"


USING_NS_CC;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class Example29 : public cocos2d::Scene
{
public:


	static cocos2d::Scene* createScene();
	virtual bool init();


	CREATE_FUNC(Example29);

	cocos2d::EventListenerTouchOneByOne* listener;

	cocos2d::Size winSize;
	cocos2d::Vec2 dragonPosition;
	cocos2d::Sprite* dragon;
	cocos2d::TMXTiledMap* tmap;
	cocos2d::TMXLayer* background;
	cocos2d::TMXLayer* items;
	cocos2d::TMXLayer* metainfo;

	



	void onEnter();
	void Exit();
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

	void createDragon();
	void setViewPointCenter(cocos2d::Vec2 position);

	cocos2d::Vec2 tileCoordForPosition(cocos2d::Vec2 position);
	void setPlayerPosition(cocos2d::Vec2 position);

private:
	


};

//cocos2d-x 지원 타일맵 
/*
	1. Orthogonal ( 정사각형 )
		- 타일 크기가 일정하다는 장점
		- RPG를 비롯한 플랫포머 게임에서 흔히 볼 수 있다

	2. Isometric ( 마름모형 )
		- 정사각형 맵보다 입체감이 느껴지는 것이 특징
		- 보드게임이나 RPG에서 볼 수 있다.

	3. Hexa ( 육각형 )
		- 벌집을 연상하게 디자인
		- 이동 방향이 6방향이기 때문에 다른 타일맵에 비해 차별화
		- 턴제 전략 시뮬레이션에서 자주 사용



*/