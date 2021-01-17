#include "Shape.h"

#include "SFML/Graphics/Color.hpp"

namespace engine
{
	namespace graphics
	{
		namespace shape
		{
			Shape::Shape()
			{}

			Shape::Shape(const sf::Transform & relativePosition) : relativePos(relativePosition)
			{}

			void Shape::SetRelativePosition(const sf::Transform & relativePosition)
			{
				relativePos = relativePosition;
			}

			std::pair<const std::unique_ptr<sf::Drawable>&, const sf::Transform> Shape::GetShape() const
			{
				return std::pair<const std::unique_ptr<sf::Drawable>&, const sf::Transform>(drawable, relativePos);
			}
		}
	}
}
