#include "RectangleShape.h"

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
			RectangleShape::RectangleShape(const RectangleShape& rectangle) : Shape(rectangle.RelativePos), Rect {rectangle.Rect}
			{
				Drawable = std::make_unique<sf::RectangleShape>(Rect);
			}

			RectangleShape::RectangleShape(uint32 width, uint32 leight, const sf::Transform & relativePosition) : Shape(relativePosition), Rect{ sf::Vector2f(width, leight) }
			{
				Drawable = std::make_unique<sf::RectangleShape>(Rect);
			}

			void RectangleShape::SetColor(sf::Color color)
			{
				Rect.setFillColor(color);
			}

			std::string RectangleShape::GetShapeName() const
			{
				return GetShapeName_Static();
			}

			std::string RectangleShape::GetShapeName_Static()
			{
				return "RectangleShape";
			}

			std::string RectangleShape::GetSerializeData() const
			{
				const sf::RectangleShape* rs = reinterpret_cast<sf::RectangleShape*>(Drawable.get());

				rapidjson::Document d;
				d.SetObject();

				auto alloc = d.GetAllocator();
				rapidjson::Value w(rapidjson::kNumberType);
				w.SetFloat(rs->getSize().x);
				d.AddMember("Width", w, alloc);

				rapidjson::Value h(rapidjson::kNumberType);
				h.SetFloat(rs->getSize().y);
				d.AddMember("Height", h, alloc);

				rapidjson::Value color(rapidjson::kNumberType);
				color.SetUint(rs->getFillColor().toInteger());
				d.AddMember("Color", color, alloc);

				FillTransformField(d, "Transform", RelativePos);

				rapidjson::StringBuffer buffer;
				rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
				d.Accept(writer);

				return buffer.GetString();
			}

			RectangleShape::~RectangleShape()
			{
				Drawable = nullptr;
			}
		}
	}
}

