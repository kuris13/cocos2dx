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

	label = Label::createWithTTF("�׽�Ʈ�� ����� ������ �Է��մϴ�.", "fonts/NanumBarunGothic.ttf", 36);
	label->setPosition(Vec2(visibleSize) * 0.5f);
	label->setOpacity(0);
	this->addChild(label);

	//������
	this->schedule(schedule_selector(Example_24::typewriterFunction), 0.1f);

	return true;
}

void Example_24::typewriterFunction(float t)
{
	//label�� ��Ƶ� ���ڿ��� ���̰� ���򺯼� i ���� ���� ��
	if (i < label->getStringLength())
	{
		//getLetter() : ���� Label ��ü�� ���Ե� ���ڿ����� i��°�� ��ġ�� ���ڸ� cocos2d::Sprite Ÿ������ �ڵ� ��ȯ
		letter = label->getLetter(i);

		//getLetter()�� �⺻������ �����̽��� �ν��� �� ���� ����ó���� �ʿ�
		if (!letter)
		{
			//��ĭ�� �������� �� ������ i�� +1 ��Ű�� �ش� ��Ʈ�� ��ŵ
			i++;
			return;
		}

		//letter �� ���� ������ ���������� ����� ������ ������
		letter->setColor(Color3B::WHITE);
		letter->setOpacity(255);

		//���򺯼� i�� ���� +1�� �Ѵ�
		i++;
	}
	//label�� ��Ƶ� ���ڿ��� �Ϻ��ϰ� ������ ��µ��� ���
	else
	{
		//���򺯼� i�� ���� 0���� ���ʱ�ȭ
		i = 0;

		//�� �Լ��� �� �̻� �����Ű�� �ʱ� ���� unschedule �ǽ�
		this->unschedule(schedule_selector(Example_24::typewriterFunction));
	}
}
