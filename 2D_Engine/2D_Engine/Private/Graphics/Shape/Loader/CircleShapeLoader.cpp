#include "CircleShapeLoader.h"

#include "../../ShapeList.h"
#include "../CircleShape.h"

#include "rapidjson/document.h"
#include "../../../Management/UtilFunctions.h"


namespace engine::graphics::shape
{
	void CircleShapeLoader::Instanciate(graphics::ShapeList& shapeList, std::string json)
	{
		rapidjson::Document d;
		d.Parse(json.c_str());

		rapidjson::GenericArray arr = d["Transform"].GetArray();
		sf::Transform transform(arr[0].GetFloat(), arr[4].GetFloat(), arr[12].GetFloat(), arr[1].GetFloat(), arr[5].GetFloat(), arr[13].GetFloat(), arr[3].GetFloat(), arr[7].GetFloat(), arr[15].GetFloat());

		Shape* shape = shapeList.Add<CircleShape>(new CircleShape(d["Radius"].GetFloat(), GetTransformFromJson(d, "Transform")));
		shape->SetColor(sf::Color(d["Color"].GetUint()));
		shape->SetColor(sf::Color::Green);
	}
}