#include "RectangleShape.h"

#include <sstream>

namespace engine
{
	namespace graphics
	{
		namespace shape
		{
			RectangleShape::RectangleShape(const RectangleShape& rectangle) : Shape(rectangle.relativePos), rect {rectangle.rect}
			{
				drawable = std::make_unique<sf::RectangleShape>(rect);
			}

			RectangleShape::RectangleShape(uint32 width, uint32 leight, const sf::Transform & relativePosition) : Shape(relativePosition), rect{ sf::Vector2f(width, leight) }
			{
				drawable = std::make_unique<sf::RectangleShape>(rect);
			}

			void RectangleShape::SetColor(sf::Color color)
			{
				rect.setFillColor(color);
			}

			std::string RectangleShape::GetShapeName() const
			{
				return "RectangleShape";
			}

			std::string RectangleShape::GetSerializeData() const
			{
				const sf::RectangleShape* rs = reinterpret_cast<sf::RectangleShape*>(drawable.get());

				std::ostringstream oss;
				oss << "{Width:" << rs->getSize().x << ",height:" << rs->getSize().y;
				oss << "," << GetTransformSerialize() << "}";
				return oss.str();
			}

			RectangleShape::~RectangleShape()
			{
				drawable = nullptr;
			}
		}
	}
}

