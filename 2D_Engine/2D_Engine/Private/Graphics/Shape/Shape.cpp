#include "Shape.h"

#include "SFML/Graphics/Color.hpp"
#include "../../Management/Save/ISaveVisitor.h"

#include <sstream>

namespace engine
{
	namespace graphics
	{
		namespace shape
		{
			Shape::Shape()
			{}

			Shape::Shape(const sf::Transform & relativePosition) : RelativePos(relativePosition)
			{}

			void Shape::SetRelativePosition(const sf::Transform & relativePosition)
			{
				RelativePos = relativePosition;
			}

			std::pair<const std::unique_ptr<sf::Drawable>&, const sf::Transform> Shape::GetShape() const
			{
				return std::pair<const std::unique_ptr<sf::Drawable>&, const sf::Transform>(Drawable, RelativePos);
			}

			void Shape::Accept(engine::management::save::ISaveVisitor* const visitor)
			{
				visitor->Visit(this);
			}
		}
	}
}
