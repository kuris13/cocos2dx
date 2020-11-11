#include "Example17.h"

USING_NS_CC;

cocos2d::Scene * Example17::createScene()
{
	return Example17::create();
}

bool Example17::init()
{
	if(!Scene::init()) return false;

	//에디트 박스의 사이즈 균일화
	Size editBoxSize = Size(300, 60);

	//에디트 박스1 ( 아이디 혹은 이름 )
	{
		std::string pNormalSprite = "ui/green_edit.png";
		_editName = ui::EditBox::create(editBoxSize, ui::Scale9Sprite::create(pNormalSprite));

		_editName->setPosition(Vec2(640, 360));
		_editName->setFontSize(25);
		_editName->setFontColor(Color3B::BLACK);

		//박스에 아무 것도 입력이 되지 않았을 경우 출력할 문자열
		_editName->setPlaceHolder("이름");
		_editName->setPlaceholderFontColor(Color3B::WHITE);
		
		//IOS나 안드로이드의 가상 키보드에서 리턴 키를 뭘로 설정할 것인가?
		_editName->setReturnType(ui::EditBox::KeyboardReturnType::DONE);

		//이게 없으면 EditBox 실행 자체가 안 된다.
		_editName->setDelegate(this);

		this->addChild(_editName);

	}

	//에디트 박스2 ( passward )
	{
		_editPassword = ui::EditBox::create(editBoxSize, "ui/orange_edit.png");
		_editPassword->setPosition(Vec2(640, 260));
		_editPassword->setFontSize(25);
		_editPassword->setFontColor(Color3B::BLACK);
		_editPassword->setPlaceHolder("비밀번호");
		_editPassword->setReturnType
		(ui::EditBox::KeyboardReturnType::DONE);

		//최대 입력 글자수 제한
		_editPassword->setMaxLength(20);

		//입력한 문자를 ****로 표현
		_editPassword->setInputFlag(ui::EditBox::InputFlag::PASSWORD);

		//입력을 여러 줄로 안 나누고 한 줄로 표시
		_editPassword->setInputMode(ui::EditBox::InputMode::SINGLE_LINE);

		_editPassword->setDelegate(this);

		this->addChild(_editPassword);
	}

	//에디트 박스3 ( email )
	{
		_editEmail = ui::EditBox::create(editBoxSize, "ui/yellow_edit.png");
		_editEmail->setPosition(Vec2(640, 160));
		_editEmail->setFontSize(25);
		_editEmail->setFontColor(Color3B::BLACK);
		_editEmail->setPlaceHolder("이메일");
		_editEmail->setReturnType(ui::EditBox::KeyboardReturnType::DONE);
		_editEmail->setInputMode(ui::EditBox::InputMode::EMAIL_ADDRESS);
		
		_editEmail->setDelegate(this);
		this->addChild(_editEmail);

	}



	return true;
}

void Example17::editBoxEditingDidBegin(cocos2d::ui::EditBox * editbox)
{
	log("editBox %p DidBegin!", editbox);


}

void Example17::editBoxEditingDidEnd(cocos2d::ui::EditBox * editbox)
{
	log("editBox %p DidEnd!", editbox);
}

void Example17::editBoxTextChanged(cocos2d::ui::EditBox * editbox, const::std::string & text)
{
	log("editBox %p TextChanged! , Text : %s", editbox, text.c_str() );
}

void Example17::editBoxReturn(cocos2d::ui::EditBox * editbox)
{
	this->removeChildByTag(1);

	auto label = Label::createWithSystemFont("", "", 28);
	label->setPosition(Vec2(640, 620));
	label->setTag(1);
	label->setString(StringUtils::format("내용 : %s", editbox->getText()));

	this->addChild(label);
}
