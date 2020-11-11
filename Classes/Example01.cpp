#include "Example01.h"
#include <algorithm>
#include <vector>

USING_NS_CC;
using namespace std;
cocos2d::Scene * Example01::createScene()
{
	return Example01::create();
}

bool Example01::init()
{
	if (!Scene::init())
	{
		return false;
	}


	auto ap = AutoPolygon::generatePolygon("priconne/mv_img_kyaru.png");

	//스프라이트
	auto pSprite = Sprite::create(ap);

	//위치 지정
	pSprite->setPosition(Vec2(640, 360));
	pSprite->setAnchorPoint(Vec2(0.0, 1.0));

	//스프라이트의 특정 부분을 잘라서 출력
	pSprite->setTextureRect(Rect(0, 0, 64, 64));

	//스프라이트의 컬러 설정
	//객체가 흰색이거나 되도록 밝은 색일 때 유효
	pSprite->setColor(Color3B::BLACK);


	//Scene에 추가
	addChild(pSprite);


	



	vector<pair<int, int>> v;
	v.push_back(make_pair<int,int>(10,10));
	vector<pair<int,int>>::iterator itr = v.begin();

	
	//for_each(v.begin(), v.end(), printLog);  -> ???? 안됨.


	for_each(itr, itr + v.size(), [](auto n) {
		log("%d, %d", n.first, n.second);
		});

	
	return true;



}
void Example01::printLog(int n)
{
	log("%d", n);
	
}

//< 좌표계 ( coordinate system ) >
/*
	< 좌표계 ( coordinate system ) >

	1. UI좌표계
		-IOS나 안드로이드에서는 좌측 상단이 원점
		-오른쪽으로 가면 X값이 증가, 아래로 갈수록 Y값 증가
		-cocos2d-x에서 스프라이트 일부분을 잘라오거나 부분 표시를 할 때 사용

	2. cocos2d-x 좌표계
		- cocos2d-x는 OpenGL을 사용하므로 좌표계의 원점이 좌측 하단
		- y값이 위로 올라갈 수록 증가
		- 오른손 좌표계



*/

//앵커포인트 AnchorPoint
/*
	1. 개요
	 -메뉴, 레이블, 스프라이트 등의 객체가
	  Layer나 Scene에 포함될 때 기준 축이 되는 좌표
	 -범위는 0.0 ~ 1.0 까지


*/