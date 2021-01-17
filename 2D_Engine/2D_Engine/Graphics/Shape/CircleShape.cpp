#include "CircleShape.h"
#include <sstream>

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

			std::string CircleShape::GetShapeName() const
			{
				return "CircleShape";
			}

			std::string CircleShape::GetSerializeData() const
			{
				const sf::CircleShape* cs = reinterpret_cast<sf::CircleShape*>(drawable.get());

				std::ostringstream oss;
				oss << "{Radius," << cs->getRadius();
				oss << "," << GetTransformSerialize() << "}";
				return oss.str();
			}

			CircleShape::~CircleShape()
			{
				drawable = nullptr;
			}
		}
	}
}