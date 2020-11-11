/*
	<< ��� ��ȯ >>
	
	1. pussScene()
		- ���ο� Scene�� �����Ͽ� ���� Scene �����ٰ� �������.
		- ���ο� ����� �����Ͽ� ���𰡸� ó���ϰ�,
		 ���� ������� ���ƿ� �� ���� ����� ������ �״�� �����ϴ� Ư���� �ִ�.
		(ex :  �ɼ� )

	2. replaceScene()
		- ���ο� Scene�� �����Ͽ� ����ϴ� ���ÿ� ���� Scene�� �޸𸮿��� �����Ѵ�.
		- �ٽ� ���� ������ ��ü�Ǵ� ����
		- pushScene���� �ٸ��� ���� Scene�� ������ �������� �ʴ´�.

	3. popScene()
		- pushScene���� ������ Scene�� �����ϰ�
		 ���� Scene���� �ǵ��ư� �� ����ϴ� �޼���.

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




	// 14-1�� �̵� pushScene
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
	// 14-2�� �̵� pushScene
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
	//�ð� �������� ȸ��
	case 0: return TransitionProgressRadialCW::create(t, s);
	//�ݽð�
	case 1: return TransitionProgressRadialCCW::create(t, s);

	//����
	case 2: return TransitionCrossFade::create(t, s);
	//������ �ѱ� ȿ�� ( ������ )
	case 3: return TransitionPageTurn::create(t, s, false);
	//�ٵ��� ����
	//TR ( ���� �ϴ� -> ���� ��� ) 
	case 4: return TransitionFadeTR::create(t, s);
	
	case 5: return TransitionFade::create(t, s);
	//case 6: return TransitionFade::create(t, s,Color3B::WHITE);

	default: break;
	}




}
