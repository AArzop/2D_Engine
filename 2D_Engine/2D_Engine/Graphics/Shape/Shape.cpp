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

			void Shape::Accept(engine::management::save::ISaveVisitor* const visitor)
			{
				visitor->Visit(this);
			}

			std::string Shape::GetTransformSerialize() const
			{
				std::ostringstream oss;

				oss << "Transform:[";
				for (int i = 0; i < 9; ++i)
				{
					oss << relativePos.getMatrix()[i];
					if (i != 8)
					{
						oss << ",";
					}
				}

				oss << "]";
				return oss.str();
			}
		}
	}
}
