/*
	1. 개요
		< audioEngine >
		현재 cocos2dx- 4.0 버전에서 표준 지원 중인 사운드 프레임 워크

		ver3.3이전까지는 cocosDenshion 이라는 네임스페이스 안에 위치한 
		SimpleAudioEngine 프레임워크를 사용함

		ver3.3 이후부터 AudioEngine이 새로 추가되었다.
		2019년에 발표된 ver4.0부터는 이 시스템만을 사용할 수 있다.

		ver3.13 버전에서 특정 android 기기가 오디오 파일을 재생할 때
		지연되는 문제가 발생했었다.

		ver3.13 부터는 AudioEngine을 리팩터링해서 제공하는 중


	2. < SimpleAudioEngine 과 AudioEngine의 비교 >

		1) SimpleAudioEngine
			- 동시에 여러 개의 BGM을 재생할 수 없다.
			- 사운드 출력이 종료되고 콜백함수를 호출하는 기능이 없다.
			- SE와 BGM 출력에 각각 다른 메서드를 사용한다.
		
		2) AudioEngine
			- C++11의 std::thread 를 사용
			- 동시에 여러 개의 소리를 재생할 수 있다.
			- 사운드 출력이 종료되고 콜백함수를 호출할 수 있다.
			- SE와 BGM 출력에 동일한 메서드를 사용한다.
			- 3.17버전 기준으로 테스트판이라 experimental 네임스페이스 선언 필요.

			
	
*/

#include "Example13.h"
#include "AudioEngine.h"

USING_NS_CC;
using namespace experimental;

//string 객체를 전역 선언 및 초기화
const std::string BGM_1_PATH = "background.mp3";
const std::string BGM_2_PATH = "background-music-aac.mp3";

cocos2d::Scene * Example13::createScene()
{
	return Example13::create();
}

bool Example13::init()
{
	if(!Scene::init()) return false;

	//봄륨 초기화
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
	//재생 지연을 방지하기 위해 미리 읽어들여 캐시 메모리에 임시보관
	AudioEngine::preload(BGM_1_PATH);
	AudioEngine::preload(BGM_2_PATH);
}

void Example13::uncacheAll(Ref * pSender)
{
	//먼저 재생 중인 사운드를 모두 정지
	AudioEngine::stopAll();
	
	//AudioEngine::uncache(BGM_1_PATH);
	//AudioEngine::uncache(BGM_2_PATH);

	AudioEngine::uncacheAll();
}

void Example13::upVolume(Ref * pSender)
{
	//볼륨 : 0.0 ~ 1.0 
	
	//봄륨이 100%가 아닐 경우 ( != 1.0f )
	if (_soundVolume < 1.0f)
	{
		_soundVolume += 0.1f;
	}
	
	//현재 재생중인 사운드에 볼륨 적용
	AudioEngine::setVolume(audioId1, _soundVolume);
	AudioEngine::setVolume(audioId2, _soundVolume);

}

void Example13::downVolume(Ref * pSender)
{
	//봄륨이 0%가 아닐 경우 
	if (_soundVolume > 0.0f)
	{
		_soundVolume -= 0.1f;
	}

	//현재 재생중인 사운드에 볼륨 적용
	AudioEngine::setVolume(audioId1, _soundVolume);
	AudioEngine::setVolume(audioId2, _soundVolume);

}

void Example13::playSound1(Ref * pSender)
{
	//특정 사운드가 재생중인지 아닌지 구분
	if (AudioEngine::getState(audioId1) != AudioEngine::AudioState::PLAYING )
	{
		audioId1 = AudioEngine::play2d(BGM_1_PATH, true, _soundVolume);
	}
}

void Example13::playSound2(Ref * pSender)
{
	//특정 사운드가 재생중인지 아닌지 구분
	if (AudioEngine::getState(audioId2) != AudioEngine::AudioState::PLAYING)
	{
		audioId2 = AudioEngine::play2d(BGM_2_PATH, false, _soundVolume);

		//audioId2에 할당된 사운드의 재생이 종료되었을 때
		if (audioId2 != AudioEngine::INVALID_AUDIO_ID)
		{
			//콜백함수 호출
			AudioEngine::setFinishCallback(audioId2, CC_CALLBACK_2(Example13::bgmPlayFinishedCallback, this));


		}

	}
}

void Example13::pauseSound1(Ref* pSender)
{
	//특정 사운드가 재생중인지 아닌지 구분
	if (AudioEngine::getState(audioId1) == AudioEngine::AudioState::PLAYING)
	{
		AudioEngine::pause(audioId1);
	}

}

void Example13::pauseSound2(Ref* pSender)
{
	//특정 사운드가 재생중인지 아닌지 구분
	if (AudioEngine::getState(audioId2) == AudioEngine::AudioState::PLAYING)
	{
		AudioEngine::pause(audioId2);
	}
}

void Example13::resumeSound1(Ref* pSender)
{
	//특정 사운드가 재생중인지 아닌지 구분
	if (AudioEngine::getState(audioId1) == AudioEngine::AudioState::PAUSED)
	{
		AudioEngine::resume(audioId1);
	}
}

void Example13::resumeSound2(Ref* pSender)
{
	//특정 사운드가 재생중인지 아닌지 구분
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
