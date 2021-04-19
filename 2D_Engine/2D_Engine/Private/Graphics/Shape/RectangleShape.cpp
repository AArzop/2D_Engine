#include "RectangleShape.h"

#include <sstream>

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
				return "RectangleShape";
			}

			std::string RectangleShape::GetSerializeData() const
			{
				const sf::RectangleShape* rs = reinterpret_cast<sf::RectangleShape*>(Drawable.get());

				std::ostringstream oss;
				oss << "{Width:" << rs->getSize().x << ",height:" << rs->getSize().y;
				oss << "," << GetTransformSerialize() << "}";
				return oss.str();
			}

			RectangleShape::~RectangleShape()
			{
				Drawable = nullptr;
			}
		}
	}
}

