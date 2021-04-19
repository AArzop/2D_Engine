#include "CircleShape.h"
#include <sstream>

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
				Circle.setFillColor(color);
			}

			std::string CircleShape::GetShapeName() const
			{
				return "CircleShape";
			}

			std::string CircleShape::GetSerializeData() const
			{
				const sf::CircleShape* cs = reinterpret_cast<sf::CircleShape*>(Drawable.get());

				std::ostringstream oss;
				oss << "{Radius," << cs->getRadius();
				oss << "," << GetTransformSerialize() << "}";
				return oss.str();
			}

			CircleShape::~CircleShape()
			{
				Drawable = nullptr;
			}
		}
	}
}