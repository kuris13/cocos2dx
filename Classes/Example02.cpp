/*
	2. Lable
	 -txt�� ȭ�鿡 �߰��ϰų� �߰��س��� txt�� ����� ��ġ,
	  �׸��� ���� �Ӽ��� ����ϴ� Ŭ����.

		1) �ý��� ��Ʈ�� ����ϴ� ���
		2) ��Ʈ�� ��Ʈ�� ����ϴ� ���
		3) ĳ���͸� ��Ʈ�� ����ϴ� ��� (*.plist)
		4) Ʈ��Ÿ�� ��Ʈ�� ����ϴ� ���

	 - �������� LableTTF, LableBMFont, LableAtlas ������ ���ҵǾ� �־���
	 - �ֽ� �������� Deprecated (=Legacy)�� ��ȯ�Ǹ鼭,
	   lableŬ������ �����յǾ���.


*/

#include "Example02.h"

USING_NS_CC;

cocos2d::Scene * Example02::createScene()
{
	return Example02::create();
}

bool Example02::init()
{
	if (!Scene::init())
	{
		return false;
	}

	//��� ��Ƶα�
	auto layer = LayerColor::create(Color4B::GRAY);
	this->addChild(layer);


	//===================================================================================

	//1. �ý��� ��Ʈ�� �̿��� Lable ( ver1 )
	//�Ӽ��� �ٲٸ� �ȵȴ�. �ý�����Ʈ�� ��Ģ�� ����ϱ� �����̴�.
	//Lable::create(����, ��Ʈ, ������);
	{
		auto pLabel = Label::create("�ȳ��ϼ���!", "", 48);
		pLabel->setPosition(Vec2(380, 360));
		this->addChild(pLabel);


	}

	//2. �ý��� ��Ʈ�� �̿��� label (ver2)
	{
		auto pLabel = Label::createWithSystemFont("�ȳ��ϼ���!�ȳ��ϼ���!�ȳ��ϼ���!�ȳ��ϼ���!�ȳ��ϼ���!�ȳ��ϼ���!�ȳ��ϼ���!",
			"",
			48,
			Size(640, 200),
			TextHAlignment::CENTER,
			TextVAlignment::CENTER
		);

		pLabel->setPosition(Vec2(384, 560));
		this->addChild(pLabel);
	}

	//3. ��Ʈ�� ��Ʈ�� �̿��� Label
	/*
		�ý��� ��Ʈ�� �̿��Ͽ� ����ϴ� �ͺ���
		�� ������ ����� �� �پ��ϰ� ���� �� �ִٴ� ���� ����
		�� ������ ������ ��������Ʈ�ν� ó���ϱ� ������,
		�̰��� �����ϰų� �׼��� ����� �� �ִ�.

		��Ʈ�� ��Ʈ�� ����Ϸ��� �̸��� ���� .fnt���ϰ� .png������ �ʿ��ϴ�.

		*.fnt : �ؽ�Ʈ ���� ���Ϸν�, �� ���ڿ� ���� �̹��� ������ ��� �ִ�.
		*.png  : ��Ʈ �̹��� ����

		��Ʈ�� ��Ʈ�� ���ڴ� ������ �׷�����.
		�� ��Ʈ�� ��Ʈ�� ����ϸ� ������ �ſ� ����.
		������ ���/Ȯ�뿡�� �������� �ʴ�.
		������ �̷������ ������ Ȯ��/����ϸ� �ս��� �߻��Ѵ�.
		label�ϳ��ϳ��� ��� sprite�̴�.
		�� ��������Ʈ �Ӽ��� ��밡��
	*/
	{
		//fnt������ �ҷ�����
		auto pLabel = Label::createWithBMFont
		("fonts/bitmapFontTest.fnt", "Hello World");
		pLabel->setPosition(Vec2(384, 260));
		this->addChild(pLabel);

	}


	//4. ĳ���͸� ��Ʈ �̿��� Label
	/*
		��Ʈ�� ��Ʈ�� ���������� ĳ���͸� ���ϵ� �̹��� ����
		�̹��� �Ӽ� ������ ���� ���� �ʴ´�.
		�ֳ��ϸ�, �̸� ������ ��Ģ�� �����ϱ� �����̴�.

		- �ƽ�Ű �ڵ� ������ ���缭 ���� ����
		- ��� ���ڿ� �ʺ�� ���̰� ����.
		- ����ϸ� �ڵ����� ��������Ʈ ��Ʈ�� �׷��� ù��° ������ �ƽ�Ű �ڵ尪�� �ҷ��´�.
		- ����ڰ� �Է��� ���� ù ��° ������ �ƽ�Ű �ڵ� �����κ���
		 �� ��°�� ��ġ���� �˾Ƽ� �Ǵ��ϰ� png���Ͽ��� �����´�.
		- ���� �̹����� �߶�� ���� ��ǥ�� ���� ��� ����


	*/
	{
		auto pLabel = Label::createWithCharMap
		("fonts/tuffy_bold_italic-charmap.plist");

		pLabel->setString("sentence");
		pLabel->setPosition(Vec2(384, 100));
		this->addChild(pLabel);

	}

	//5. Ʈ��Ÿ�� ��Ʈ�� �̿��� Label
	/*
		����̽��� ����� �⺻ ��Ʈ�� �ƴ϶� ������ ���ϴ� ��Ʈ�� ����ϰ� ���� ��,
		�پ��� Ư��ȿ���� ����� �� �ִ�.
		Ȯ��/��� �ÿ� �ս��� �Ͼ�� �ʴ´�.
		��Ʈ����Ʈ���� ���� ����ϱ� ������ ������ �ӵ��� ���� ������
		label�� �Ӽ��� �����ϴ� �Ϳ� ���ɼҺ� ũ��.
		���� ���� �Ӽ��� ���� ���� label�� �����ϰ��� �ϸ� TTFConfig��ü��
		�����Ͽ� �����ϰ� ������Ű��.
		TTFConfig�� �߱��� �Ͼ� �ѱ�� �׸� �� �ִ�.
		HTML��밡��
	*/

	//TTF Label ��ü�� ����� ��Ʈ ����
	TTFConfig ttfConfig("fonts/Scissor Cuts.ttf", 60);

	//5-1 �⺻
	{
		auto pLabel = Label::createWithTTF(ttfConfig, "Normal");
		pLabel->setPosition(Vec2(960, 660));
		pLabel->setColor(Color3B::WHITE);
		this->addChild(pLabel);

	}

	//5-2 Glow
	{
		auto pLabel = Label::createWithTTF(ttfConfig, "Glow");
		pLabel->setPosition(Vec2(960, 560));
		pLabel->setColor(Color3B::WHITE);
		pLabel->enableGlow(Color4B::RED);
		this->addChild(pLabel);

	}

	//5-3 OutLine
	{
		ttfConfig.outlineSize = 3;

		auto pLabel = Label::createWithTTF(ttfConfig, "OutLine");
		pLabel->setPosition(Vec2(960, 460));
		pLabel->setColor(Color3B::WHITE);
		pLabel->enableOutline(Color4B::BLUE);
		this->addChild(pLabel);

		ttfConfig.outlineSize = 0;
	}

	//5-4 Shadow
	{
		auto pLabel = Label::createWithTTF(ttfConfig, "Shadow");
		pLabel->setPosition(Vec2(960, 360));
		pLabel->setColor(Color3B::WHITE);
		//enableShaow(�׸��� ����, offset, ��)
		pLabel->enableShadow(Color4B::BLACK, Size(5, -5), 0);
		this->addChild(pLabel);

	}

	//5-5 Bold
	{
		ttfConfig.bold = true;
		auto pLabel = Label::createWithTTF(ttfConfig, "Bold");
		pLabel->setPosition(Vec2(960, 260));
		pLabel->setColor(Color3B::WHITE);
		pLabel->enableBold();
		this->addChild(pLabel);
		ttfConfig.bold = false;
	}

	//5-5 italic
	{
		ttfConfig.italics = true;
		auto pLabel = Label::createWithTTF(ttfConfig, "italic");
		pLabel->setPosition(Vec2(960, 160));
		pLabel->setColor(Color3B::WHITE);
		pLabel->enableItalics();
		this->addChild(pLabel);
		ttfConfig.italics = false;
	}

	return true;

}
