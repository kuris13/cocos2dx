#include "Example16.h"

cocos2d::Scene * Example16::createScene()
{
	return Example16::create();
}

bool Example16::init()
{
	if(!Scene::init()) return false;

	auto item = MenuItemFont::create(
		"UserDefault integer++",
		CC_CALLBACK_1(Example16::setValue, this));

	auto menu = Menu::create(item, nullptr);
	this->addChild(menu);

	//=========================================
	
	/* UserDefault의 데이터 저장과 쓰기 */

	// 1. 문자열 
	USERDEFAULT->setStringForKey("str_key", "테스트");
	std::string a = USERDEFAULT->getStringForKey("str_key");
	
	// 2. 정수
	//USERDEFAULT->setIntegerForKey("int_key", 10);
	//int b = USERDEFAULT->getIntegerForKey("int_key");

	// 3. 실수 ( float )
	USERDEFAULT->setFloatForKey("float_key", 3.141592f);
	float c = USERDEFAULT->getFloatForKey("float_key");

	// 4. 실수 ( double )
	USERDEFAULT->setDoubleForKey("double_key", 3.141592);
	double d = USERDEFAULT->getDoubleForKey("double_key");

	// 5. 논리형 ( bool )
	USERDEFAULT->setBoolForKey("bool_key", true);
	bool e = USERDEFAULT->getBoolForKey("bool_key");

	
	//========================================


	//log("string 객체 a : %s" , a);
	//log("int형 변수 b: %d", b);
	//log("float형 변수 c: %f", c);
	//log("double형 변수 d : %lf",d);
	//log("bool형 변수 e : %d", e);


	return true;
}

void Example16::setValue(Ref * pSender)
{
	int i = USERDEFAULT->getIntegerForKey("int_key");
	++i;

	USERDEFAULT->setIntegerForKey("int_key", i);
	log("integer value released : %d", i);

	//flush()를 사용하지 않으면 실행중일 땐 값이 저장되어도
	//앱이 종료되는 순간 데이터가 증발한다.
	USERDEFAULT->flush();

	//string메서드를 userdefault에서도 사용가능 
	//bool temp = USERDEFAULT->getStringForKey("str_key").empty();

}
