#pragma once
#include "cocos2d.h"

/*

*/

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class Example04 : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	CREATE_FUNC(Example04);

private:
	cocos2d::Sprite* pSprite1;
	cocos2d::Sprite* pSprite2;
	cocos2d::Sprite* pSprite3;

	void doAction(Ref* pSender);


	// Basic Action
	void doActionMove();
	void doActionJump();
	void doActionRotate();
	void doActionScale();
	void doActionTint();
	void doActionPlace();
	void doActionBlink();
	void doActionShow();
	void doActionFadeInOut();

	// Composition Action
	void doActionSequence();
	void doActionSpawn();
	void doActionRepeat();
	void doActionRepeatForever();
	void doActionDelayTime();

	//Ease Action
	void doActionEase();
	void doActionElastic();
	void doActionBounce();
	void doActionSpeed();


	//Callback Action
	void doActionCallFunc();
	void callback1();
	void callback2();
	void callback3();


	//�׼� ( Action )�� �з�
	/*

		�� By�� To�� ���̴� �����ΰ�?
		 - By : ���� ������ ������ ����ŭ ���ϴ� �׼�
		 - To : ���� ���� ���� �Ƶ� ������ ������ ���ϴ� �׼�



		1. �⺻ �׼� Basic Actions
		 - ��ü�� �⺻ �Ӽ�(properties)�� �����ϴ� �׼�
		 - ��ǥ������ �̵�, ȸ��, ����, ũ�� ��ȯ ��.

		 1) ��ġ ���� (position)
		  : MoveTo / MoveBy
		  : JumpTo / JumpBy
		  : BezierBy / BezierTo // ������ �
		  : Place

		 2) ũ�� ���� (Scale)
		  : ScaleBy / ScaleTo

		 3) ���� ����( Rotation )
		  : RotateBy / RotateTo

		 4) ���ü� ( visible )
		  : Show, Hide, Blink, ToggleVisibility

		 5) ����( Opacity )
		  : FadeIn, FadeOut, FadeTo

		 6) ���� ����( RGB )
		  : TintBy, TintTo


		2. ���� �׼� composite Actions
		 - ���� ���� �׼��� ���������� �����ϰų� ���ÿ� ���� �׼��� ����

		 1) ���� ���� : Squence
		 2) ���� ���� : Spawn
		 3) ���� ���� : DelayTime
		 4) �ݺ� ���� : Repeat
		 5) ���� ���� : RepeatForever

		3. ���� �׼� Ease Actions
		 - �׼� ������ �׼� ����ð��� �����ϴ� Ư�� ���� �׼�.
		 - �׼� ���� �ӵ��� ���� ( ����ȭ or ����ȭ ) ������,
		  �׼��� ��ü ���� �ð��� �޶����� �ʴ´�.
		 - ������ ũ�� 3����

		 1) Ease[�׼Ǹ�]In : �׼��� ó������ �����ٰ� ������ ��������.
		 1) Ease[�׼Ǹ�]Out : �׼��� ó������ �����ٰ� ������ ��������.
		 1) Ease[�׼Ǹ�]InOut : 1,2�� ��ģ ��.


		4. �ݹ� �׼� CallFunc Actions
		 - Ư�� �׼��� ����Ǹ� �ݺ��Լ��� ȣ���ϴ� �׼�




	*/

};
