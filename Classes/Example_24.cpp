#include "Example_24.h"

USING_NS_CC;

cocos2d::Scene * Example_24::createScene()
{
	return Example_24::create();
}

bool Example_24::init()
{
	if (!Scene::init()) return false;

	auto visibleSize = Director::getInstance()->getVisibleSize();

	label = Label::createWithTTF("테스트로 출력할 문장을 입력합니다.", "fonts/NanumBarunGothic.ttf", 36);
	label->setPosition(Vec2(visibleSize) * 0.5f);
	label->setOpacity(0);
	this->addChild(label);

	//스케줄
	this->schedule(schedule_selector(Example_24::typewriterFunction), 0.1f);

	return true;
}

void Example_24::typewriterFunction(float t)
{
	//label에 담아둔 문자열의 길이가 도움변수 i 보다 작을 때
	if (i < label->getStringLength())
	{
		//getLetter() : 현재 Label 객체에 삽입된 문자열에서 i번째에 위치한 문자를 cocos2d::Sprite 타입으로 자동 변환
		letter = label->getLetter(i);

		//getLetter()는 기본적으로 스페이스를 인식할 수 없어 예외처리가 필요
		if (!letter)
		{
			//빈칸에 접근했을 때 강제로 i를 +1 시키고 해당 파트를 스킵
			i++;
			return;
		}

		//letter 에 값이 무사히 보관됐으면 색상과 투명도를 재조정
		letter->setColor(Color3B::WHITE);
		letter->setOpacity(255);

		//도움변수 i의 값을 +1씩 한다
		i++;
	}
	//label에 담아둔 문자열이 완벽하게 끝까지 출력됐을 경우
	else
	{
		//도움변수 i의 값을 0으로 재초기화
		i = 0;

		//이 함수를 더 이상 실행시키지 않기 위해 unschedule 실시
		this->unschedule(schedule_selector(Example_24::typewriterFunction));
	}
}
