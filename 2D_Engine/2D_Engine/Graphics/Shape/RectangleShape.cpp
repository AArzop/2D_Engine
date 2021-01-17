#include "RectangleShape.h"

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

			RectangleShape::~RectangleShape()
			{
				drawable = nullptr;
			}
		}
	}
}

