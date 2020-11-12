/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "AppDelegate.h"
#include "HelloWorldScene.h"

#include "Example01.h"
#include "Example02.h"
#include "Example03.h"
#include "Example04.h"
#include "Example05.h"
#include "Example06.h"
#include "Example07.h"
#include "Example08.h"
#include "Example0901.h"
#include "Example0902.h"
#include "Example0903.h"
#include "Example10.h"
#include "Example11.h"
#include "Example12.h"
#include "Example13.h"
#include "Example14.h"
#include "Example15.h"
#include "Example16.h"
#include "Example17.h"
#include "Example18.h"
#include "Example19.h"
#include "Example20.h"
//#include "Example21.h"
#include "Example22.h"
#include "Example_23.h"
#include "Example_24.h"
#include "Example25.h"
#include "Example26.h"
#include "Example27.h"
#include "Example28.h"
#include "Example29.h"


#include "hw02.h"
#include "hw01.h"
#include "hw0301.h"
#include "Introduce.h"
#include "Test1.h"

//define USE_AUDIO_ENGINE 1
// #define USE_SIMPLE_AUDIO_ENGINE 1

#if USE_AUDIO_ENGINE && USE_SIMPLE_AUDIO_ENGINE
#error "Don't use AudioEngine and SimpleAudioEngine at the same time. Please just select one in your game!"
#endif

#if USE_AUDIO_ENGINE
#include "audio/include/AudioEngine.h"
using namespace cocos2d::experimental;
#elif USE_SIMPLE_AUDIO_ENGINE
#include "audio/include/SimpleAudioEngine.h"
using namespace CocosDenshion;
#endif

USING_NS_CC;

static cocos2d::Size designResolutionSize = cocos2d::Size(480, 320);
static cocos2d::Size smallResolutionSize = cocos2d::Size(480, 320);
static cocos2d::Size mediumResolutionSize = cocos2d::Size(1024, 768);
static cocos2d::Size largeResolutionSize = cocos2d::Size(2048, 1536);

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate() 
{
#if USE_AUDIO_ENGINE
    AudioEngine::end();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::end();
#endif
}

// if you want a different context, modify the value of glContextAttrs
// it will affect all platforms
void AppDelegate::initGLContextAttrs()
{
    // set OpenGL context attributes: red,green,blue,alpha,depth,stencil,multisamplesCount
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8, 0};

    GLView::setGLContextAttrs(glContextAttrs);
}

// if you want to use the package manager to install more packages,  
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
        glview = GLViewImpl::createWithRect("Prj0929", cocos2d::Rect(0, 0,1280, 720));   //처음 실행되는 크기
#else
        glview = GLViewImpl::create("Prj0929");
#endif
        director->setOpenGLView(glview);
    }

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0f / 60);

    // Set the design resolution
    glview->setDesignResolutionSize(1280, 760, ResolutionPolicy::SHOW_ALL);
   

    // create a scene. it's an autorelease object
   // auto scene = HelloWorld::createScene();
	//auto scene = Example01::createScene();
   // auto scene = Example02::createScene();
	//auto scene = Example03::createScene();
	//auto scene = Example04::createScene();
	//auto scene = hw01::create();
	//auto scene = Example05::createScene();
	//auto scene = Example06::createScene();
	//auto scene = Example07::createScene();
	//auto scene = Example08::createScene();
	//auto scene = Example0901::createScene();
	//auto scene = Example0902::createScene();
	//auto scene = Example0903::createScene();
	//auto scene = Example10::createScene();
	//auto scene = Example11::createScene();
	//auto scene = Example12::createScene();
	//auto scene = Example13::createScene();
	//auto scene = Example14::createScene();
	//auto scene = hw02::createScene();
	//auto scene = Example15::createScene();
	//auto scene = Example16::createScene();
	//auto scene = Example17::createScene();
	//auto scene = Example18::createScene();
	//auto scene = Example19::createScene();
	//auto scene = Example20::createScene();
	//auto scene = Example21::createScene();
	//auto scene = hw0301::createScene();
	//auto scene = Introduce::createScene();
	//auto scene = Example22::createScene();
	//auto scene = Example_23::createScene();
	//auto scene = Example_24::createScene();
	//auto scene = Example25::createScene();
	//auto scene = Example26::createScene();
	//auto scene = Example27::createScene();
	//auto scene = Example28::createScene();
	//auto scene = Example29::createScene();
	auto scene = Test1::createScene();
	// run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. Note, when receiving a phone call it is invoked.
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

#if USE_AUDIO_ENGINE
    AudioEngine::pauseAll();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
    SimpleAudioEngine::getInstance()->pauseAllEffects();
#endif
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

#if USE_AUDIO_ENGINE
    AudioEngine::resumeAll();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    SimpleAudioEngine::getInstance()->resumeAllEffects();
#endif
}
