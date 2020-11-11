#include "Example17.h"

USING_NS_CC;

cocos2d::Scene * Example17::createScene()
{
	return Example17::create();
}

bool Example17::init()
{
	if(!Scene::init()) return false;

	//����Ʈ �ڽ��� ������ ����ȭ
	Size editBoxSize = Size(300, 60);

	//����Ʈ �ڽ�1 ( ���̵� Ȥ�� �̸� )
	{
		std::string pNormalSprite = "ui/green_edit.png";
		_editName = ui::EditBox::create(editBoxSize, ui::Scale9Sprite::create(pNormalSprite));

		_editName->setPosition(Vec2(640, 360));
		_editName->setFontSize(25);
		_editName->setFontColor(Color3B::BLACK);

		//�ڽ��� �ƹ� �͵� �Է��� ���� �ʾ��� ��� ����� ���ڿ�
		_editName->setPlaceHolder("�̸�");
		_editName->setPlaceholderFontColor(Color3B::WHITE);
		
		//IOS�� �ȵ���̵��� ���� Ű���忡�� ���� Ű�� ���� ������ ���ΰ�?
		_editName->setReturnType(ui::EditBox::KeyboardReturnType::DONE);

		//�̰� ������ EditBox ���� ��ü�� �� �ȴ�.
		_editName->setDelegate(this);

		this->addChild(_editName);

	}

	//����Ʈ �ڽ�2 ( passward )
	{
		_editPassword = ui::EditBox::create(editBoxSize, "ui/orange_edit.png");
		_editPassword->setPosition(Vec2(640, 260));
		_editPassword->setFontSize(25);
		_editPassword->setFontColor(Color3B::BLACK);
		_editPassword->setPlaceHolder("��й�ȣ");
		_editPassword->setReturnType
		(ui::EditBox::KeyboardReturnType::DONE);

		//�ִ� �Է� ���ڼ� ����
		_editPassword->setMaxLength(20);

		//�Է��� ���ڸ� ****�� ǥ��
		_editPassword->setInputFlag(ui::EditBox::InputFlag::PASSWORD);

		//�Է��� ���� �ٷ� �� ������ �� �ٷ� ǥ��
		_editPassword->setInputMode(ui::EditBox::InputMode::SINGLE_LINE);

		_editPassword->setDelegate(this);

		this->addChild(_editPassword);
	}

	//����Ʈ �ڽ�3 ( email )
	{
		_editEmail = ui::EditBox::create(editBoxSize, "ui/yellow_edit.png");
		_editEmail->setPosition(Vec2(640, 160));
		_editEmail->setFontSize(25);
		_editEmail->setFontColor(Color3B::BLACK);
		_editEmail->setPlaceHolder("�̸���");
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
	label->setString(StringUtils::format("���� : %s", editbox->getText()));

	this->addChild(label);
}
