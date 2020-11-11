/*
	2. Lable
	 -txt를 화면에 추가하거나 추가해높은 txt의 내용과 위치,
	  그리고 관련 속성을 담당하는 클래스.

		1) 시스템 폰트를 사용하는 방법
		2) 비트맵 폰트를 사용하는 방법
		3) 캐릭터맵 폰트를 사용하는 방법 (*.plist)
		4) 트루타입 폰트를 사용하는 방법

	 - 예전에는 LableTTF, LableBMFont, LableAtlas 등으로 분할되어 있었음
	 - 최신 버전에서 Deprecated (=Legacy)로 전환되면서,
	   lable클래르소 통폐합되었다.


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

	//배경 깔아두기
	auto layer = LayerColor::create(Color4B::GRAY);
	this->addChild(layer);


	//===================================================================================

	//1. 시스템 폰트를 이용한 Lable ( ver1 )
	//속성을 바꾸면 안된다. 시스템폰트의 규칙을 사용하기 때문이다.
	//Lable::create(내용, 폰트, 사이즈);
	{
		auto pLabel = Label::create("안녕하세요!", "", 48);
		pLabel->setPosition(Vec2(380, 360));
		this->addChild(pLabel);


	}

	//2. 시스템 폰트를 이용한 label (ver2)
	{
		auto pLabel = Label::createWithSystemFont("안녕하세요!안녕하세요!안녕하세요!안녕하세요!안녕하세요!안녕하세요!안녕하세요!",
			"",
			48,
			Size(640, 200),
			TextHAlignment::CENTER,
			TextVAlignment::CENTER
		);

		pLabel->setPosition(Vec2(384, 560));
		this->addChild(pLabel);
	}

	//3. 비트맵 폰트를 이용하 Label
	/*
		시스템 폰트를 이용하여 출력하는 것보다
		각 글자의 모양을 더 다양하게 만들 수 있다는 것이 장점
		각 글자의 별개의 스프라이트로써 처리하기 때문에,
		이것을 변형하거나 액션을 사용할 수 있다.

		비트맵 폰트를 사용하려면 이름이 같은 .fnt파일과 .png파일이 필요하다.

		*.fnt : 텍스트 형식 파일로써, 각 글자에 대한 이미지 정보를 담고 있다.
		*.png  : 폰트 이미지 파일

		비트맵 폰트의 글자는 점으로 그려진다.
		이 비트맵 폰트를 사용하면 성능이 매우 좋다.
		하지만 축소/확대에는 적합하지 않다.
		점으로 이루어졌기 때문에 확대/축소하면 손실이 발생한다.
		label하나하나가 모두 sprite이다.
		즉 스프라이트 속성을 사용가능
	*/
	{
		//fnt파일을 불러오기
		auto pLabel = Label::createWithBMFont
		("fonts/bitmapFontTest.fnt", "Hello World");
		pLabel->setPosition(Vec2(384, 260));
		this->addChild(pLabel);

	}


	//4. 캐릭터맵 폰트 이용한 Label
	/*
		비트맵 폰트와 마찬가지로 캐릭터맵 파일도 이미지 파일
		이미지 속성 정보를 따로 받지 않는다.
		왜냐하면, 미리 정해진 규칙이 존재하기 때문이다.

		- 아스키 코드 순서에 맞춰서 글자 정렬
		- 모든 글자에 너비와 높이가 같다.
		- 사용하면 자동으로 스프라이트 시트에 그려진 첫번째 글자의 아스키 코드값을 불러온다.
		- 사용자가 입력한 값이 첫 번째 글자의 아스키 코드 값으로부터
		 몇 번째에 위치한지 알아서 판단하고 png파일에서 가져온다.
		- 글자 이미지를 잘라올 때의 좌표는 좌측 상단 기준


	*/
	{
		auto pLabel = Label::createWithCharMap
		("fonts/tuffy_bold_italic-charmap.plist");

		pLabel->setString("sentence");
		pLabel->setPosition(Vec2(384, 100));
		this->addChild(pLabel);

	}

	//5. 트루타입 폰트를 이용한 Label
	/*
		디바이스에 내장된 기본 폰트가 아니라 본인이 원하는 폰트를 사용하고 싶을 때,
		다양한 특수효과를 사용할 수 있다.
		확대/축소 시에 손실이 일어나지 않는다.
		비트맵폰트보다 자주 사용하긴 하지만 렌더링 속도가 비교적 느리고
		label의 속성을 변경하는 것에 성능소비가 크다.
		만약 같은 속성을 가진 여러 label을 생성하고자 하면 TTFConfig객체를
		생성하여 동일하게 구성시키자.
		TTFConfig는 중국어 일어 한국어를 그릴 수 있다.
		HTML사용가능
	*/

	//TTF Label 객체에 사용할 폰트 설정
	TTFConfig ttfConfig("fonts/Scissor Cuts.ttf", 60);

	//5-1 기본
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
		//enableShaow(그림자 색상, offset, 블러)
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
