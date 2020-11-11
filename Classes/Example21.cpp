#include "Example21.h"

#include "tinyxml2/tinyxml2.h"

#include "json/rapidjson.h"
#include "json/document.h"
#include "json/stringbuffer.h"
#include "json/prettywriter.h"


USING_NS_CC;
using namespace tinyxml2;


cocos2d::Scene * Example21::createScene()
{
	return Example21::create();
}

bool Example21::init()
{
	if(!Scene::init()) return false;

	//===================================
	
	// getInstace
	FileUtils* xmlUtil = FileUtils::getInstance();

	//xml parse => XML 파일이 위치하는 실제 디렉터리를 구해야한다.
	//cocos2dx는 폴랫폼별로 dircoty가 달라짐 but 이 매서드는 각 플랫폼별 실제 디렉터리를 알아서 구분해줌.
	std::string path = xmlUtil->fullPathForFilename("data/test_data.xml");

	//XML파일을 관리해줄 XMLDocument 객체
	tinyxml2::XMLDocument* xmlDoc = new tinyxml2::XMLDocument();

	//XML 데이터 내부의 오류 검사
	XMLError error = xmlDoc->LoadFile(path.c_str());

	if (error != 0)
	{
		log("Error number = %d", error);
		return false;
	}


	//===================================

	//XML 객체에 포함되어 있는 데이터 중에서 최상위에 위치한 요소를 받아온다
	XMLElement* root = xmlDoc->RootElement();

	// 받아온 데이터 중에서 'total'에 해당하는 값을 대입
	XMLElement* value = root->FirstChildElement("total");

	//XML 내 단일 요소 출력 
	{
		if (value)
		{
			log("Element = %s", value->GetText());
			value = value->NextSiblingElement("page");
		}

		if (value)
		{
			log("Element = %s", value->GetText());
			value = value->NextSiblingElement("per");
		}


		if (value)
		{
			log("Element = %s", value->GetText());
		}
	}

	//XML 네 베열 요소 출력 
	{
		XMLElement* child2 = value->NextSiblingElement()->FirstChildElement();

		while(child2)
		{
			XMLElement* child3 = child2->FirstChildElement();

			while (child3)
			{
				log("Child Element = %s", child3->GetText());
				child3 = child3->NextSiblingElement();
			}
			child2 = child2->NextSiblingElement();

		}
	
	}


	//============================================

	//https://jsoneditoronline.org/

	FileUtils* util = FileUtils::getInstance();

	std::string jsonData = util->getStringFromFile("data/test_data.json");

	//JSON을 관리할 Document객체
	rapidjson::Document doc;

	//불러들인 json 데이터를 string 형식으로 읽어서 객체 doc에 파싱
	doc.Parse<0>(jsonData.c_str());

	//오류 검사
	if (doc.HasParseError())
	{
		log("getParseError : %d\n", doc.GetParseError());
	}
	else
	{
		std::string str = doc["string"].GetString();
		log("name = %s", str.c_str());
	}

	//array불러오기
	const rapidjson::Value &arr = doc["array"];

	if (arr.IsArray())
	{
		for (rapidjson::SizeType i = 0; i < arr.Size(); i++)
		{
			auto name = arr[i]["name"].GetString();
			auto age = arr[i]["age"].GetInt();
			log("name : %s, age : %d", name, age);
		}
	}


	return true;
}
