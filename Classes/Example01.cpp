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

	//��������Ʈ
	auto pSprite = Sprite::create(ap);

	//��ġ ����
	pSprite->setPosition(Vec2(640, 360));
	pSprite->setAnchorPoint(Vec2(0.0, 1.0));

	//��������Ʈ�� Ư�� �κ��� �߶� ���
	pSprite->setTextureRect(Rect(0, 0, 64, 64));

	//��������Ʈ�� �÷� ����
	//��ü�� ����̰ų� �ǵ��� ���� ���� �� ��ȿ
	pSprite->setColor(Color3B::BLACK);


	//Scene�� �߰�
	addChild(pSprite);


	



	vector<pair<int, int>> v;
	v.push_back(make_pair<int,int>(10,10));
	vector<pair<int,int>>::iterator itr = v.begin();

	
	//for_each(v.begin(), v.end(), printLog);  -> ???? �ȵ�.


	for_each(itr, itr + v.size(), [](auto n) {
		log("%d, %d", n.first, n.second);
		});

	
	return true;



}
void Example01::printLog(int n)
{
	log("%d", n);
	
}

//< ��ǥ�� ( coordinate system ) >
/*
	< ��ǥ�� ( coordinate system ) >

	1. UI��ǥ��
		-IOS�� �ȵ���̵忡���� ���� ����� ����
		-���������� ���� X���� ����, �Ʒ��� ������ Y�� ����
		-cocos2d-x���� ��������Ʈ �Ϻκ��� �߶���ų� �κ� ǥ�ø� �� �� ���

	2. cocos2d-x ��ǥ��
		- cocos2d-x�� OpenGL�� ����ϹǷ� ��ǥ���� ������ ���� �ϴ�
		- y���� ���� �ö� ���� ����
		- ������ ��ǥ��



*/

//��Ŀ����Ʈ AnchorPoint
/*
	1. ����
	 -�޴�, ���̺�, ��������Ʈ ���� ��ü��
	  Layer�� Scene�� ���Ե� �� ���� ���� �Ǵ� ��ǥ
	 -������ 0.0 ~ 1.0 ����


*/