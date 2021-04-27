#include "UtilFunctions.h"


void FillTransformField(rapidjson::Document& document, const std::string& fieldName, const sf::Transform& transform)
{
	rapidjson::Value arr(rapidjson::kArrayType);
	arr.SetArray().Reserve(16, document.GetAllocator());
	for (int i = 0; i < 16; ++i)
	{
		rapidjson::Value v(rapidjson::kNumberType);
		v.SetFloat(transform.getMatrix()[i]);

		arr.PushBack(v, document.GetAllocator());
	}

	rapidjson::Value name(fieldName.c_str(), document.GetAllocator());
	document.AddMember(name, arr, document.GetAllocator());
}

sf::Transform GetTransformFromJson(const rapidjson::Document& document, const std::string& fieldName)
{
	rapidjson::GenericArray arr = document[fieldName.c_str()].GetArray();
	return sf::Transform(arr[0].GetFloat(), arr[4].GetFloat(), arr[12].GetFloat(), arr[1].GetFloat(), arr[5].GetFloat(), arr[13].GetFloat(), arr[3].GetFloat(), arr[7].GetFloat(), arr[15].GetFloat());
}

void FillVector2fField(rapidjson::Document& document, const std::string& fieldName, const sf::Vector2f& vector)
{
	rapidjson::Value arr(rapidjson::kArrayType);
	arr.SetArray().Reserve(2, document.GetAllocator());

	rapidjson::Value v(rapidjson::kNumberType);
	v.SetFloat(vector.x);
	arr.PushBack(v, document.GetAllocator());

	v.SetFloat(vector.y);
	arr.PushBack(v, document.GetAllocator());

	rapidjson::Value name(fieldName.c_str(), document.GetAllocator());
	document.AddMember(name, arr, document.GetAllocator());
}
