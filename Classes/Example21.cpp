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

	//xml parse => XML ������ ��ġ�ϴ� ���� ���͸��� ���ؾ��Ѵ�.
	//cocos2dx�� ���������� dircoty�� �޶��� but �� �ż���� �� �÷����� ���� ���͸��� �˾Ƽ� ��������.
	std::string path = xmlUtil->fullPathForFilename("data/test_data.xml");

	//XML������ �������� XMLDocument ��ü
	tinyxml2::XMLDocument* xmlDoc = new tinyxml2::XMLDocument();

	//XML ������ ������ ���� �˻�
	XMLError error = xmlDoc->LoadFile(path.c_str());

	if (error != 0)
	{
		log("Error number = %d", error);
		return false;
	}


	//===================================

	//XML ��ü�� ���ԵǾ� �ִ� ������ �߿��� �ֻ����� ��ġ�� ��Ҹ� �޾ƿ´�
	XMLElement* root = xmlDoc->RootElement();

	// �޾ƿ� ������ �߿��� 'total'�� �ش��ϴ� ���� ����
	XMLElement* value = root->FirstChildElement("total");

	//XML �� ���� ��� ��� 
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

	//XML �� ���� ��� ��� 
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

	//JSON�� ������ Document��ü
	rapidjson::Document doc;

	//�ҷ����� json �����͸� string �������� �о ��ü doc�� �Ľ�
	doc.Parse<0>(jsonData.c_str());

	//���� �˻�
	if (doc.HasParseError())
	{
		log("getParseError : %d\n", doc.GetParseError());
	}
	else
	{
		std::string str = doc["string"].GetString();
		log("name = %s", str.c_str());
	}

	//array�ҷ�����
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
