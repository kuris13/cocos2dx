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


	//액션 ( Action )의 분류
	/*

		※ By와 To으 차이는 무엇인가?
		 - By : 현재 값에서 지정한 값만큼 변하는 액션
		 - To : 현재 값이 뭐가 됐든 지정한 값으로 변하는 액션



		1. 기본 액션 Basic Actions
		 - 객체의 기본 속성(properties)을 수정하는 액션
		 - 대표적으로 이동, 회전, 점프, 크기 변환 등.

		 1) 위치 변경 (position)
		  : MoveTo / MoveBy
		  : JumpTo / JumpBy
		  : BezierBy / BezierTo // 베지에 곡선
		  : Place

		 2) 크기 변경 (Scale)
		  : ScaleBy / ScaleTo

		 3) 각도 조절( Rotation )
		  : RotateBy / RotateTo

		 4) 가시성 ( visible )
		  : Show, Hide, Blink, ToggleVisibility

		 5) 투명도( Opacity )
		  : FadeIn, FadeOut, FadeTo

		 6) 색상 변경( RGB )
		  : TintBy, TintTo


		2. 복합 액션 composite Actions
		 - 여러 개의 액션을 순차적으로 실행하거나 동시에 여러 액션을 실행

		 1) 순차 실행 : Squence
		 2) 동시 실행 : Spawn
		 3) 지연 실행 : DelayTime
		 4) 반복 실행 : Repeat
		 5) 무한 실행 : RepeatForever

		3. 이즈 액션 Ease Actions
		 - 액션 내부의 액션 실행시간을 수정하는 특수 복합 액션.
		 - 액션 내부 속도를 수정 ( 저속화 or 가속화 ) 하지만,
		  액션의 전체 동작 시간을 달라지지 않는다.
		 - 유형은 크게 3가지

		 1) Ease[액션명]In : 액션이 처음에는 느리다가 끝에서 빨라진다.
		 1) Ease[액션명]Out : 액션이 처음에서 빠르다가 끝에서 느려진다.
		 1) Ease[액션명]InOut : 1,2번 합친 것.


		4. 콜백 액션 CallFunc Actions
		 - 특정 액션이 종료되면 콜벡함수를 호출하는 액션




	*/

};
