#include "CircleShapeLoader.h"

#include "../../ShapeList.h"
#include "../CircleShape.h"

#include "rapidjson/document.h"

namespace engine::graphics::shape
{
	void CircleShapeLoader::Instanciate(graphics::ShapeList& shapeList, std::string json)
	{
		rapidjson::Document d;
		d.Parse(json.c_str());

		rapidjson::GenericArray arr = d["Transform"].GetArray();
		sf::Transform transform(arr[0].GetFloat(), arr[1].GetFloat(), arr[2].GetFloat(), arr[3].GetFloat(), arr[4].GetFloat(), arr[5].GetFloat(), arr[6].GetFloat(), arr[7].GetFloat(), arr[8].GetFloat());

		shapeList.Add<CircleShape>(new CircleShape(d["Radius"].GetUint(), transform));
	}
}