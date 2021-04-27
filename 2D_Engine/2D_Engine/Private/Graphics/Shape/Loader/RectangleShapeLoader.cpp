#include "RectangleShapeLoader.h"
#include "../RectangleShape.h"
#include "../../ShapeList.h"
#include "rapidjson/document.h"
#include "../../../Management/UtilFunctions.h"

namespace engine::graphics::shape
{
	void RectangleShapeLoader::Instanciate(graphics::ShapeList& shapeList, std::string json)
	{
		rapidjson::Document d;
		d.Parse(json.c_str());
		Shape* shape = shapeList.Add<RectangleShape>(new RectangleShape(d["Width"].GetFloat(), d["Height"].GetFloat(), GetTransformFromJson(d, "Transform")));
		shape->SetColor(sf::Color(d["Color"].GetUint()));
	}
}