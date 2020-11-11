/*
	<< 장면 전환 >>
	
	1. pussScene()
		- 새로운 Scene을 생성하여 현재 Scene 위에다가 덧씌운다.
		- 새로운 장면을 생성하여 무언가를 처리하고,
		 이전 장면으로 돌아올 때 이전 장면의 정보를 그대로 유지하는 특성이 있다.
		(ex :  옵션 )

	2. replaceScene()
		- 새로운 Scene을 생성하여 출력하는 동시에 이전 Scene은 메모리에서 해제한다.
		- 다시 말해 완전히 교체되는 형식
		- pushScene과는 다르게 이전 Scene의 정보가 유지되지 않는다.

	3. popScene()
		- pushScene으로 생성한 Scene을 삭제하고
		 이전 Scene으로 되돌아갈 때 사용하는 메서드.

*/

#include "Example14.h"
#include "Example1401.h"
#include "Exmaple1402.h"

USING_NS_CC;

cocos2d::Scene * Example14::createScene()
{
	return Example14::create();
}

bool Example14::init()
{
	if(!Scene::init()) return false;

	auto item1 = MenuItemFont::create("pushScene", CC_CALLBACK_1(Example14::doPushScene, this));
	auto item2 = MenuItemFont::create("replaceScene", CC_CALLBACK_1(Example14::doReplaceScene, this));

	auto pMenu = Menu::create(item1, item2, nullptr);
	pMenu->alignItemsVertically();
	this->addChild(pMenu);


	return true;
}

void Example14::doPushScene(Ref * pSender)
{
	static int nIndex1 = 0;




	// 14-1로 이동 pushScene
	auto scene = Example1401::createScene();
	Director::getInstance()->pushScene(createTransition(nIndex1,1,scene));

	++nIndex1;
	
	if (nIndex1 > 5)
	{
		nIndex1 = 0;
	}
}

void Example14::doReplaceScene(Ref * pSender)
{
	static int nIndex2 = 0;
	// 14-2로 이동 pushScene
	auto scene = Example1402::createScene();
	Director::getInstance()->replaceScene(createTransition( nIndex2,1,scene));

	++nIndex2;

	if (nIndex2 > 5)
	{
		nIndex2 = 0;
	}
}

cocos2d::TransitionScene * Example14::createTransition(int nIndex, float t, cocos2d::Scene * s)
{
	Director::getInstance()->setDepthTest(false);

	switch (nIndex)
	{
	//시계 방향으로 회전
	case 0: return TransitionProgressRadialCW::create(t, s);
	//반시계
	case 1: return TransitionProgressRadialCCW::create(t, s);

	//교차
	case 2: return TransitionCrossFade::create(t, s);
	//페이지 넘기 효과 ( 앞으로 )
	case 3: return TransitionPageTurn::create(t, s, false);
	//바둑판 무늬
	//TR ( 좌측 하단 -> 우측 상단 ) 
	case 4: return TransitionFadeTR::create(t, s);
	
	case 5: return TransitionFade::create(t, s);
	//case 6: return TransitionFade::create(t, s,Color3B::WHITE);

	default: break;
	}




}
