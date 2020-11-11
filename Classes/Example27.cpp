// ui ����  
/*
	1. Button
	2. CheckBox
	3. Layout
	4. LoadingBar
	5. PageView
	6. RichText
	7. Slider
	8. TextField
*/

//ImageView�� Sprite�� ������
/*
	-ImageView�� ���������� Scale9Sprtie�� ����ϰ� ����
	-Scale9Sprite�� ����Ǿ� �ֱ� ������ 9-patch file������ ����� �� �ִ�.

	�� 9-patch file : âũ�⸦ �ݿ��Ͽ� �̹��� ũ�Ⱑ �ڵ����� �����Ǵ� ����

	1. ImageView
		1) ������ġ : cocos/ui 
		2) ������ �ε� : ���� �� ��
		3) �̹��� ���� ��� : loadTexture
		4) 9-patch file ���� ���� : ���� 

	2. Sprite
		1) ������ġ : cocos/2d
		2) ������ �ε� : ����
		3) �̹��� ���� ��� : setTexture
		4) 9-patch file ���� : ���� �� ��



*/


#include "Example27.h"
#define CC_UIPractice 8


using namespace ui;

cocos2d::Scene * Example27::createScene()
{
	return Example27::create();



}

bool Example27::init()
{
	if(!Scene::init()) return false;

	auto visibleSize = Director::getInstance()->getVisibleSize();

	auto wlayer = LayerColor::create(Color4B::WHITE);
	this->addChild(wlayer);

#if CC_UIPractice == 1

	// 1. Button
	auto btn = ui::Button::create("CloseNormal.png", "CloseSelected.png");

	//position
	btn->setPosition(Vec2(visibleSize) * 0.5f);

	//add EventListener
	btn->addTouchEventListener(CC_CALLBACK_2(Example27::ButtonEvent, this));

	//addChild
	this->addChild(btn);

#elif	CC_UIPractice == 2

	// 2. CheckBox
	//ui::CheckBox::create(mnormal, selected)
	//ui::CheckBox::create(normal, press, active, disable)
	auto cBox = ui::CheckBox::create("ui/checkBox_normal.png", "ui/checkBox_selected.png");
	cBox->setScale(0.5f);
	cBox->setPosition(Vec2(visibleSize) * 0.5f);
	cBox->addEventListener(CC_CALLBACK_2(Example27::CheckBoxEvent, this));
	this->addChild(cBox);
	
#elif CC_UIPractice == 3

	// 3. Layout
	// 
	auto btn = ui::Button::create("CloseNormal.png", "CloseSelected.png");

	auto imgView = ui::ImageView::create("HelloWorld.png");
	
	auto layout = ui::Layout::create();

	// Layout�� ���Ե� ��ü���� ����
	layout->setLayoutType(ui::Layout::Type::VERTICAL);
	// Layout�� ��׶��� �̹��� ����
	layout->setBackGroundImage("priconne/page_bg.jpg");

	layout->addChild(btn);
	layout->addChild(imgView);

	layout->setPosition(Vec2(visibleSize)*0.5f);
	this->addChild(layout);

#elif CC_UIPractice == 4

	// 4. LoadingBar
	auto loading = ui::LoadingBar::create("ui/sliderProgress.png");

	// �ε����� ������ ���? ( �⺻���� ���� -> ������ )
	loading->setDirection(LoadingBarType::LEFT);
	
	// �ۼ�Ʈ 
	loading->setPercent(75.0f);

	loading->setPosition(Vec2(visibleSize)*0.5f);
	this->addChild(loading);

#elif CC_UIPractice == 5

	// 5. pageView
	auto image1 = ui::ImageView::create("priconne/Events/109231.png");
	auto image2 = Sprite::create("priconne/Events/109331.png");
	auto image3 = ImageView::create("priconne/Events/109431.png");


	image1->setAnchorPoint(Vec2::ZERO);
	image2->setAnchorPoint(Vec2::ZERO);
	image3->setAnchorPoint(Vec2::ZERO);

	//==================================

	auto pView = ui::PageView::create();
	pView->setContentSize(Size(1024, 640));
	pView->setPosition(Vec2(visibleSize) * 0.1f);

	//==================================
	// 1������
	auto layout1 = ui::Layout::create();
	layout1->addChild(image1);

	// 2������
	auto layout2 = ui::Layout::create();
	layout2->addChild(image2);

	// 3������
	auto layout3 = ui::Layout::create();
	layout3->addChild(image3);

	//==================================
	// ������ �߰� 
	pView->addPage(layout1);
	pView->insertPage(layout2,1);
	pView->insertPage(layout3, 2);

	pView->addEventListener(CC_CALLBACK_2(Example27::PageViewEvent, this));

	//
	pView->setTouchEnabled(true);
	this->addChild(pView);


#elif CC_UIPractice == 6

	//6. RichText
	//����� �ؽ�Ʈ�� ������Ƽ�� ���ÿ� �������� ������ �� �ִ�.

	//create
	auto richText = ui::RichText::create();

	//����ڰ� ���� Ŀ������ content ������ �����ϰ� ������ ���� ����
	richText->ignoreContentAdaptWithSize(false);

	richText->setContentSize(Size(120, 500));
	richText->setPosition(Vec2(visibleSize) * 0.5f);

	//ui::RichElementText::create()
	//( �±�, �÷�, ����, ����� ���ڿ�, ��Ʈ ���, ��Ʈ ������ )
	auto re1 = ui::RichElementText::create(1, Color3B::WHITE, 255, "WHITE", "fonts/NanumBarunGothic.ttf", 24);
	auto re2 = ui::RichElementText::create(2, Color3B::YELLOW, 255, "YELLOW", "fonts/NanumBarunGothic.ttf", 24);
	auto re3 = ui::RichElementText::create(3, Color3B::BLUE, 255, "BLUE", "fonts/NanumBarunGothic.ttf", 24);
	auto re4 = ui::RichElementText::create(4, Color3B::GREEN, 255, "GREEN", "fonts/NanumBarunGothic.ttf", 24);
	auto re5 = ui::RichElementText::create(5, Color3B::RED, 255, "RED", "fonts/NanumBarunGothic.ttf", 24);
	
	//insert element
	richText->pushBackElement(re1);
	richText->pushBackElement(re2);
	richText->pushBackElement(re3);
	richText->pushBackElement(re4);
	
	// additional element
	richText->insertElement(re5, 4);
	
	this->addChild(richText);


#elif CC_UIPractice == 7

	// 7. Slider
	// �ɼ��� �ܰ������� ������ �� �ʿ��� ���
	auto slider = ui::Slider::create();

	// �����̴� �ڿ� ��ġ�ϴ� ���̽� �̹���
	slider->loadBarTexture("ui/sliderTrack.png");

	// �����̴� ������ ������ �̹���
	slider->loadSlidBallTextureNormal("ui/sliderThumb.png");

	// �����̴� �ۼ�Ʈ ǥ�ÿ� �̹���
	slider->loadProgressBarTexture("ui/sliderprogress.png");

	// �ʱⰪ ����
	slider->setPercent(50);

	slider->setPosition(Vec2(visibleSize) * 0.5f);
	slider->setScale(2.0f);
	slider->addEventListener(CC_CALLBACK_2(Example27::sliderEvent, this));

	this->addChild(slider);

#elif CC_UIPractice == 8

	// 8. textField
	// ui::TextField::create( place holder text, ��Ʈ ���, ��Ʈ ������ )
	auto textField = ui::TextField::create("�ؽ�Ʈ�� �Է��ϼ���", "fonts/NanumBarunGothic.ttf", 36);
	textField->setMaxLength(20);
	textField->setMaxLengthEnabled(true);
	textField->setPosition(Vec2(visibleSize) * 0.5f);
	textField->setCursorEnabled(true);
	
	//Ŀ���� ���ڷ� �ٲٱ� �⺻�� nullptr
	textField->setCursorChar('��');

	this->addChild(textField);


#endif





	return true;
}

void Example27::ButtonEvent(Ref * pSender, ui::Widget::TouchEventType type)
{
	switch (type)
	{
	case cocos2d::ui::Widget::TouchEventType::BEGAN:
		log("asdasdasd");
		break;
	case cocos2d::ui::Widget::TouchEventType::MOVED:
		break;
	case cocos2d::ui::Widget::TouchEventType::ENDED:
		break;
	case cocos2d::ui::Widget::TouchEventType::CANCELED:
		break;
	default:
		break;
	}


}

void Example27::CheckBoxEvent(Ref * pSender, ui::CheckBox::EventType type)
{

	switch (type)
	{
	case cocos2d::ui::CheckBox::EventType::SELECTED:
		break;
	case cocos2d::ui::CheckBox::EventType::UNSELECTED:
		break;
	default:
		break;
	}
}

void Example27::PageViewEvent(Ref * pSender, ui::PageView::EventType type)
{

	ui::PageView* pView = dynamic_cast<ui::PageView*>(pSender);


	switch (type)
	{
	case cocos2d::ui::PageView::EventType::TURNING:
		log("Turnig Page : %ld", pView->getCurrentPageIndex());
		break;
	default:
		break;
	}
}

void Example27::sliderEvent(Ref* pSender, ui::Slider::EventType type)
{

	auto slider = dynamic_cast<ui::Slider*>(pSender);
	int percent = slider->getPercent();

	switch (type)
	{
	case cocos2d::ui::Slider::EventType::ON_PERCENTAGE_CHANGED:
		log("slider percent : %ld", percent);
		break;
	case cocos2d::ui::Slider::EventType::ON_SLIDEBALL_DOWN:
		break;
	case cocos2d::ui::Slider::EventType::ON_SLIDEBALL_UP:
		break;
	case cocos2d::ui::Slider::EventType::ON_SLIDEBALL_CANCEL:
		break;
	default:
		break;
	}
}
