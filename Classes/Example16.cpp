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
	
	/* UserDefault�� ������ ����� ���� */

	// 1. ���ڿ� 
	USERDEFAULT->setStringForKey("str_key", "�׽�Ʈ");
	std::string a = USERDEFAULT->getStringForKey("str_key");
	
	// 2. ����
	//USERDEFAULT->setIntegerForKey("int_key", 10);
	//int b = USERDEFAULT->getIntegerForKey("int_key");

	// 3. �Ǽ� ( float )
	USERDEFAULT->setFloatForKey("float_key", 3.141592f);
	float c = USERDEFAULT->getFloatForKey("float_key");

	// 4. �Ǽ� ( double )
	USERDEFAULT->setDoubleForKey("double_key", 3.141592);
	double d = USERDEFAULT->getDoubleForKey("double_key");

	// 5. ���� ( bool )
	USERDEFAULT->setBoolForKey("bool_key", true);
	bool e = USERDEFAULT->getBoolForKey("bool_key");

	
	//========================================


	//log("string ��ü a : %s" , a);
	//log("int�� ���� b: %d", b);
	//log("float�� ���� c: %f", c);
	//log("double�� ���� d : %lf",d);
	//log("bool�� ���� e : %d", e);


	return true;
}

void Example16::setValue(Ref * pSender)
{
	int i = USERDEFAULT->getIntegerForKey("int_key");
	++i;

	USERDEFAULT->setIntegerForKey("int_key", i);
	log("integer value released : %d", i);

	//flush()�� ������� ������ �������� �� ���� ����Ǿ
	//���� ����Ǵ� ���� �����Ͱ� �����Ѵ�.
	USERDEFAULT->flush();

	//string�޼��带 userdefault������ ��밡�� 
	//bool temp = USERDEFAULT->getStringForKey("str_key").empty();

}
