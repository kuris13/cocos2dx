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

//cocos2d-x ���� Ÿ�ϸ� 
/*
	1. Orthogonal ( ���簢�� )
		- Ÿ�� ũ�Ⱑ �����ϴٴ� ����
		- RPG�� ����� �÷����� ���ӿ��� ���� �� �� �ִ�

	2. Isometric ( �������� )
		- ���簢�� �ʺ��� ��ü���� �������� ���� Ư¡
		- ��������̳� RPG���� �� �� �ִ�.

	3. Hexa ( ������ )
		- ������ �����ϰ� ������
		- �̵� ������ 6�����̱� ������ �ٸ� Ÿ�ϸʿ� ���� ����ȭ
		- ���� ���� �ùķ��̼ǿ��� ���� ���



*/