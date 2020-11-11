#include "Example04.h"

USING_NS_CC;

cocos2d::Scene * Example04::createScene()
{
	return Example04::create();
}

bool Example04::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto pMenuItem = MenuItemFont::create("Action", CC_CALLBACK_1(Example04::doAction, this));

	auto pMenu = Menu::create(pMenuItem, nullptr);
	pMenu->setPosition(Vec2(640, 100));
	this->addChild(pMenu);

	pSprite1 = Sprite::create("priconne/mv_img_kokkoro.png");
	pSprite2 = Sprite::create("priconne/mv_img_kyaru.png");
	pSprite3 = Sprite::create("priconne/mv_img_peco.png");

	pSprite1->setPosition(Vec2(128, 590));
	pSprite2->setPosition(Vec2(128, 380));
	pSprite3->setPosition(Vec2(128, 160));

	this->addChild(pSprite1);
	this->addChild(pSprite2);
	this->addChild(pSprite3);


	return true;
}

void Example04::doAction(Ref * pSender)
{

	//doActionMove();

	//doActionJump();

	//doActionRotate();


   // doActionScale();

	//doActionTint();

	//doActionPlace();

	//doActionBlink();

	//doActionShow();


	//doActionFadeInOut();

	//doActionSequence();

	//doActionSpawn();

	//doActionRepeat();


	//doActionRepeatForever();

	//doActionDelayTime();

	/*
	doActionEase();
	doActionElastic();
	doActionBounce();
	*/
	//doActionSpeed();
	doActionCallFunc();

}

//===========Basic Action=========
void Example04::doActionMove()
{
	auto myActionTo = MoveTo::create(3.0f, Vec2(480, 0));
	auto myActionBy = MoveBy::create(3.0f, Vec2(480, 0));


	pSprite1->runAction(myActionTo);
	pSprite2->runAction(myActionBy);
}

void Example04::doActionJump()
{
	//JumpTo::create(�ð�, ��ġ, �������� ,����Ƚ�� )
	//(400,0) ��ǥ�� 2�ʰ� �̵��ϸ鼭 ���̰� 50�� ������ 3ȸ ����
	auto myActionTo = JumpTo::create(2.0f, Vec2(400, 360), 50, 3);
	//JumpBy::create(�ð�, ��ȭ��, �������� ,����Ƚ�� )
	//x�� ���� ��ǥ�� 2�ʰ� �̵��ϸ鼭 ���̰� 50�� ������ 3ȸ ����
	auto myActionBy = JumpBy::create(2.0f, Vec2(400, 0), 50, 3);

	pSprite1->runAction(myActionTo);
	pSprite2->runAction(myActionBy);

}

void Example04::doActionRotate()
{
	//RotateTo : ����� ����� ������ �ּ����� ȸ���� ���� 
	auto myActionTo = RotateTo::create(2.0f, 270);
	//RotateBy : �Է��� ��ġ��ŭ �ð�������� ���ʺй�ȸ��
	auto myActionBy = RotateBy::create(2.0f, 270);

	pSprite1->runAction(myActionTo);
	pSprite2->runAction(myActionBy);
}

void Example04::doActionScale()
{
	auto myActionTo = ScaleTo::create(2.0f, 2);
	auto myActionBy = ScaleBy::create(2.0f, 2);


	pSprite1->runAction(myActionTo);
	pSprite2->runAction(myActionBy);
}

void Example04::doActionTint()
{

	auto myActionTo = TintTo::create(2.0f, Color3B::RED);
	auto myActionBy = TintBy::create(2.0f, 0, 10, 10);


	pSprite1->runAction(myActionTo);
	pSprite2->runAction(myActionBy);

}

void Example04::doActionPlace()
{
	//��� �̵�
	auto myActionTo = Place::create(Vec2::ANCHOR_MIDDLE_RIGHT);


	pSprite1->runAction(myActionTo);

}

void Example04::doActionBlink()
{
	auto myActionTo = Blink::create(2.0f, 100);


	pSprite1->runAction(myActionTo);


}

void Example04::doActionShow()
{
	//Hide & Show : setVisible()�� �׼����� �����ϴ� Ŭ����
	if (pSprite1->isVisible())
	{
		//Hide : ��ü�� ����
		auto myAction = Hide::create();
		pSprite1->runAction(myAction);

	}
	else
	{
		auto myAction = Show::create();


		pSprite1->runAction(myAction);

	}

}

void Example04::doActionFadeInOut()
{
	//FadeIn, FadeOut : ���� ����
	if (pSprite1->getOpacity() == 0)
	{
		auto myAction = FadeIn::create(1.0f);
		pSprite1->runAction(myAction);

	}
	else
	{
		auto myAction = FadeOut::create(1.0f);


		pSprite1->runAction(myAction);

	}

	//FadeTo::create(�ð�, ����)
	auto myAction = FadeTo::create(1.0f, 128);
	pSprite2->runAction(myAction);

}


//==========composition Action==========
void Example04::doActionSequence()
{
	auto a = MoveBy::create(2.0f, Vec2(480, 0));
	auto b = RotateBy::create(2.0f, 720);

	//Sequence : 2�� �̻��� �׼��� �����Ͽ� ���������� ����ϴ� Ŭ����
	auto action = Sequence::create(a, b, nullptr);
	pSprite1->runAction(action);


}

void Example04::doActionSpawn()
{
	auto a = MoveBy::create(2.0f, Vec2(480, 0));
	auto b = RotateBy::create(1.0f, 720);

	//Spawn : 2�� �̻��� �׼��� �����Ͽ� ���ÿ� ����ϴ� Ŭ����
	auto action = Spawn::create(a, b, nullptr);
	pSprite1->runAction(action);
}

void Example04::doActionRepeat()
{
	//Repeat : ������ Ƚ����ŭ �׼��� �ݺ��ϴ� Ŭ����
	auto myActionForWard = MoveBy::create(1.0f, Vec2(480, 0));
	auto myActionBack = myActionForWard->reverse();
	auto myAction = Sequence::createWithTwoActions(myActionForWard, myActionBack);

	auto rep = Repeat::create(myAction, 5);

	pSprite1->runAction(rep);

	pSprite2->runAction(rep->clone());

	pSprite3->runAction(rep->clone());

}

void Example04::doActionRepeatForever()
{
	//Repeat : ������ Ƚ����ŭ �׼��� �ݺ��ϴ� Ŭ����
	auto myActionForWard = MoveBy::create(1.0f, Vec2(480, 0));
	auto myActionBack = myActionForWard->reverse();
	auto myAction = Sequence::createWithTwoActions(myActionForWard, myActionBack);

	auto rep = RepeatForever::create(myAction);

	pSprite1->runAction(rep);

	pSprite2->runAction(rep->clone());

	pSprite3->runAction(rep->clone());


}

void Example04::doActionDelayTime()
{
	//Delay Time : �׼��� �����ð� ���� ����Ų �Ŀ� �����Ѵ�.
	auto act1 = RotateTo::create(0.5f, 170);
	auto act2 = RotateTo::create(0.5f, 0);
	auto delay = DelayTime::create(1.0f);

	auto myAction = Sequence::create(act1, delay, delay, act2, nullptr);
	pSprite1->runAction(myAction);


}






void Example04::doActionEase()
{



}

void Example04::doActionElastic()
{

	//�⺻���� 0.3�̸� ���߻������� �ǰ��ϴ� ��ġ�� 0.3 ~ 0.45
	//moveBy, scaleBy, rotateBy �� ���� ���� �ܼ��� �׼ǿ� �ַ� ���
	//sequence�� spawn�� ���� ���� �׼ǿ� ����ϸ� ���� ����� ������ �𸥴� .
	
}

void Example04::doActionBounce()
{



}

void Example04::doActionSpeed()
{
	auto move = MoveBy::create(2.0f, Vec2(480, 0));


	auto ease_in = Speed::create(move,1.0f);
	auto ease_out=Speed::create(move->clone(), 2.0f);
	auto ease_inout=Speed::create(move->clone(), 3.0f);

	pSprite1->runAction(ease_in);
	pSprite2->runAction(ease_out);
	pSprite3->runAction(ease_inout);

}

void Example04::doActionCallFunc()
{
	auto action = Sequence::create(
		Place::create(Vec2(200, 200)),
		DelayTime::create(1.5),
		CallFunc::create(CC_CALLBACK_0(Example04::callback1, this)),
		MoveBy::create(1.5f, Vec2(200, 0)),
		CallFunc::create(CC_CALLBACK_0(Example04::callback2, this)),
		MoveBy::create(1.5f, Vec2(0,200)),
		CallFunc::create(CC_CALLBACK_0(Example04::callback3, this)),
		DelayTime::create(1.5f),
		RemoveSelf::create(),	//�ڱ� �ڽ�(�׼��� ����� ��ü)�� ����� �׼� RemoveSelf
		nullptr
	);


	pSprite1->runAction(action);

}

void Example04::callback1()
{
	auto label = Label::createWithSystemFont("txt1", "", 36);
	label->setPosition(Vec2(640, 600));
	label->setColor(Color3B::RED);
	this->addChild(label);
}

void Example04::callback2()
{
	auto label = Label::createWithSystemFont("txt2", "", 36);
	label->setPosition(Vec2(640, 600));
	label->setColor(Color3B::YELLOW);
	this->addChild(label);
}

void Example04::callback3()
{
	auto label = Label::createWithSystemFont("txt3", "", 36);
	label->setPosition(Vec2(640, 600));
	label->setColor(Color3B::GREEN);
	this->addChild(label);
}
