/*
	1. ����
		< audioEngine >
		���� cocos2dx- 4.0 �������� ǥ�� ���� ���� ���� ������ ��ũ

		ver3.3���������� cocosDenshion �̶�� ���ӽ����̽� �ȿ� ��ġ�� 
		SimpleAudioEngine �����ӿ�ũ�� �����

		ver3.3 ���ĺ��� AudioEngine�� ���� �߰��Ǿ���.
		2019�⿡ ��ǥ�� ver4.0���ʹ� �� �ý��۸��� ����� �� �ִ�.

		ver3.13 �������� Ư�� android ��Ⱑ ����� ������ ����� ��
		�����Ǵ� ������ �߻��߾���.

		ver3.13 ���ʹ� AudioEngine�� �����͸��ؼ� �����ϴ� ��


	2. < SimpleAudioEngine �� AudioEngine�� �� >

		1) SimpleAudioEngine
			- ���ÿ� ���� ���� BGM�� ����� �� ����.
			- ���� ����� ����ǰ� �ݹ��Լ��� ȣ���ϴ� ����� ����.
			- SE�� BGM ��¿� ���� �ٸ� �޼��带 ����Ѵ�.
		
		2) AudioEngine
			- C++11�� std::thread �� ���
			- ���ÿ� ���� ���� �Ҹ��� ����� �� �ִ�.
			- ���� ����� ����ǰ� �ݹ��Լ��� ȣ���� �� �ִ�.
			- SE�� BGM ��¿� ������ �޼��带 ����Ѵ�.
			- 3.17���� �������� �׽�Ʈ���̶� experimental ���ӽ����̽� ���� �ʿ�.

			
	
*/

#include "Example13.h"
#include "AudioEngine.h"

USING_NS_CC;
using namespace experimental;

//string ��ü�� ���� ���� �� �ʱ�ȭ
const std::string BGM_1_PATH = "background.mp3";
const std::string BGM_2_PATH = "background-music-aac.mp3";

cocos2d::Scene * Example13::createScene()
{
	return Example13::create();
}

bool Example13::init()
{
	if(!Scene::init()) return false;

	//���� �ʱ�ȭ
	_soundVolume = 1.0f;

	// Menu#1
	{
		MenuItemFont::setFontSize(24);
		auto pMenuItem1A = MenuItemFont::create(
			"Preload All", CC_CALLBACK_1(Example13::preloadAll, this));

		auto pMenuItem1B = MenuItemFont::create(
			"Uncache All", CC_CALLBACK_1(Example13::preloadAll, this));

		auto pMenuItem1C = MenuItemFont::create(
			"Volume Up", CC_CALLBACK_1(Example13::preloadAll, this));

		auto pMenuItem1D = MenuItemFont::create(
			"Volume Down", CC_CALLBACK_1(Example13::preloadAll, this));

		auto pMenu = Menu::create(pMenuItem1A, pMenuItem1B, pMenuItem1C, pMenuItem1D, nullptr);

		pMenu->alignItemsHorizontallyWithPadding(20);
		pMenu->setPosition(Vec2(640, 560));
		this->addChild(pMenu);


	}

	// Menu#2
	{
		MenuItemFont::setFontSize(36);

		auto pMenuItem1A = MenuItemFont::create(
			"Play Sound1", CC_CALLBACK_1(Example13::playSound1, this));

		auto pMenuItem1B = MenuItemFont::create(
			"Pause Sound1", CC_CALLBACK_1(Example13::pauseSound1, this));

		auto pMenuItem1C = MenuItemFont::create(
			"Resume Sound1", CC_CALLBACK_1(Example13::resumeSound1, this));

		auto pMenuItem1D = MenuItemFont::create(
			"Stop Sound1", CC_CALLBACK_1(Example13::stopSound1, this));

		auto pMenu = Menu::create(pMenuItem1A, pMenuItem1B, pMenuItem1C, pMenuItem1D, nullptr);

		pMenu->alignItemsVertically();
		pMenu->setPosition(Vec2(440, 360));
		this->addChild(pMenu);

	}

	// Menu#3
	{
		MenuItemFont::setFontSize(36);

		auto pMenuItem1A = MenuItemFont::create(
			"Play Sound2", CC_CALLBACK_1(Example13::playSound2, this));

		auto pMenuItem1B = MenuItemFont::create(
			"Pause Sound2", CC_CALLBACK_1(Example13::pauseSound2, this));

		auto pMenuItem1C = MenuItemFont::create(
			"Resume Sound2", CC_CALLBACK_1(Example13::resumeSound2, this));

		auto pMenuItem1D = MenuItemFont::create(
			"Stop Sound2", CC_CALLBACK_1(Example13::stopSound2, this));

		auto pMenu = Menu::create(pMenuItem1A, pMenuItem1B, pMenuItem1C, pMenuItem1D, nullptr);

		pMenu->alignItemsVertically();
		pMenu->setPosition(Vec2(840, 360));
		this->addChild(pMenu);

	}

	return true;
}

void Example13::preloadAll(Ref * pSender)
{
	//��� ������ �����ϱ� ���� �̸� �о�鿩 ĳ�� �޸𸮿� �ӽú���
	AudioEngine::preload(BGM_1_PATH);
	AudioEngine::preload(BGM_2_PATH);
}

void Example13::uncacheAll(Ref * pSender)
{
	//���� ��� ���� ���带 ��� ����
	AudioEngine::stopAll();
	
	//AudioEngine::uncache(BGM_1_PATH);
	//AudioEngine::uncache(BGM_2_PATH);

	AudioEngine::uncacheAll();
}

void Example13::upVolume(Ref * pSender)
{
	//���� : 0.0 ~ 1.0 
	
	//������ 100%�� �ƴ� ��� ( != 1.0f )
	if (_soundVolume < 1.0f)
	{
		_soundVolume += 0.1f;
	}
	
	//���� ������� ���忡 ���� ����
	AudioEngine::setVolume(audioId1, _soundVolume);
	AudioEngine::setVolume(audioId2, _soundVolume);

}

void Example13::downVolume(Ref * pSender)
{
	//������ 0%�� �ƴ� ��� 
	if (_soundVolume > 0.0f)
	{
		_soundVolume -= 0.1f;
	}

	//���� ������� ���忡 ���� ����
	AudioEngine::setVolume(audioId1, _soundVolume);
	AudioEngine::setVolume(audioId2, _soundVolume);

}

void Example13::playSound1(Ref * pSender)
{
	//Ư�� ���尡 ��������� �ƴ��� ����
	if (AudioEngine::getState(audioId1) != AudioEngine::AudioState::PLAYING )
	{
		audioId1 = AudioEngine::play2d(BGM_1_PATH, true, _soundVolume);
	}
}

void Example13::playSound2(Ref * pSender)
{
	//Ư�� ���尡 ��������� �ƴ��� ����
	if (AudioEngine::getState(audioId2) != AudioEngine::AudioState::PLAYING)
	{
		audioId2 = AudioEngine::play2d(BGM_2_PATH, false, _soundVolume);

		//audioId2�� �Ҵ�� ������ ����� ����Ǿ��� ��
		if (audioId2 != AudioEngine::INVALID_AUDIO_ID)
		{
			//�ݹ��Լ� ȣ��
			AudioEngine::setFinishCallback(audioId2, CC_CALLBACK_2(Example13::bgmPlayFinishedCallback, this));


		}

	}
}

void Example13::pauseSound1(Ref* pSender)
{
	//Ư�� ���尡 ��������� �ƴ��� ����
	if (AudioEngine::getState(audioId1) == AudioEngine::AudioState::PLAYING)
	{
		AudioEngine::pause(audioId1);
	}

}

void Example13::pauseSound2(Ref* pSender)
{
	//Ư�� ���尡 ��������� �ƴ��� ����
	if (AudioEngine::getState(audioId2) == AudioEngine::AudioState::PLAYING)
	{
		AudioEngine::pause(audioId2);
	}
}

void Example13::resumeSound1(Ref* pSender)
{
	//Ư�� ���尡 ��������� �ƴ��� ����
	if (AudioEngine::getState(audioId1) == AudioEngine::AudioState::PAUSED)
	{
		AudioEngine::resume(audioId1);
	}
}

void Example13::resumeSound2(Ref* pSender)
{
	//Ư�� ���尡 ��������� �ƴ��� ����
	if (AudioEngine::getState(audioId2) == AudioEngine::AudioState::PAUSED)
	{
		AudioEngine::resume(audioId2);
	}
}

void Example13::stopSound1(Ref* pSender)
{
	if (AudioEngine::getState(audioId1) == AudioEngine::AudioState::PLAYING)
	{
		AudioEngine::stop(audioId1);
	}
}

void Example13::stopSound2(Ref* pSender)
{
	if (AudioEngine::getState(audioId2) == AudioEngine::AudioState::PLAYING)
	{
		AudioEngine::stop(audioId2);
	}
}

void Example13::bgmPlayFinishedCallback(int audioId, const std::string & filepath)
{
	log("[ %s ]",filepath.c_str());
}

Example13::~Example13()
{
	AudioEngine::end();
}
