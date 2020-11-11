
#include "cocos2d.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class Example20 :public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	CREATE_FUNC(Example20);



private:
	cocos2d::Sprite* animSprite;
	void createBackground();
	void createCharacter();

	cocos2d::Sprite* leftChevron;
	cocos2d::Sprite* leftChevronPressed;
	cocos2d::Sprite* rightChevron;
	cocos2d::Sprite* rightChevronPressed;

	cocos2d::Size winSize;
	cocos2d::EventListenerTouchOneByOne* _listener;

	bool isLeftPressed;
	bool isRightPressed;

	void createArrowButtons();

	void onEnter();
	void onExit();

	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

	bool isTouchInside(cocos2d::Sprite* sprite, cocos2d::Touch* touch);
	void startMovingBackground();
	void stopMovingBackground();
	void moveBackground(float t);

	cocos2d::Layer* layer1;
	cocos2d::Layer* layer2;


};
