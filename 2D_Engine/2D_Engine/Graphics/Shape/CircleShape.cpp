#include "CircleShape.h"

namespace engine
{
	namespace graphics
	{
		namespace shape
		{
			CircleShape::CircleShape(const CircleShape& circleShape) : Shape(circleShape.relativePos), circle{ circleShape.circle }
			{
				drawable = std::make_unique<sf::CircleShape>(circle);
			}

			CircleShape::CircleShape(uint32 radius, const sf::Transform& relativePosition): Shape(relativePosition), circle{ static_cast<float>(radius) }
			{
				drawable = std::make_unique<sf::CircleShape>(circle);
			}

			void CircleShape::SetColor(sf::Color color)
			{
				circle.setFillColor(color);
			}

			CircleShape::~CircleShape()
			{
				drawable = nullptr;
			}
		}
	}
}