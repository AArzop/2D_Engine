#include "CircleShape.h"

#include "../../Management/UtilFunctions.h"

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

namespace engine
{
	namespace graphics
	{
		namespace shape
		{
			CircleShape::CircleShape(const CircleShape& circleShape) : Shape(circleShape.RelativePos), Circle{ circleShape.Circle }
			{
				Drawable = std::make_unique<sf::CircleShape>(Circle);
			}

			CircleShape::CircleShape(uint32 radius, const sf::Transform& relativePosition): Shape(relativePosition), Circle{ static_cast<float>(radius) }
			{
				Drawable = std::make_unique<sf::CircleShape>(Circle);
			}

			void CircleShape::SetColor(sf::Color color)
			{
				sf::CircleShape* cs = reinterpret_cast<sf::CircleShape*>(Drawable.get());
				cs->setFillColor(color);
			}

			std::string CircleShape::GetShapeName() const
			{
				return GetShapeName_Static();
			}

			std::string CircleShape::GetShapeName_Static()
			{
				return "CircleShape";
			}

			std::string CircleShape::GetSerializeData() const
			{
				const sf::CircleShape* cs = reinterpret_cast<sf::CircleShape*>(Drawable.get());

				rapidjson::Document d;
				d.SetObject();

				auto alloc = d.GetAllocator();

				rapidjson::Value radius(rapidjson::kNumberType);
				radius.SetFloat(cs->getRadius());
				d.AddMember("Radius", radius, alloc);

				rapidjson::Value color(rapidjson::kNumberType);
				color.SetUint(cs->getFillColor().toInteger());
				d.AddMember("Color", color, alloc);

				FillTransformField(d, "Transform", RelativePos);

				rapidjson::StringBuffer buffer;
				rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
				d.Accept(writer);

				return buffer.GetString();
			}

			CircleShape::~CircleShape()
			{
				Drawable = nullptr;
			}
		}
	}
}