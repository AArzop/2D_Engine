#pragma once

#include <memory>

#include "../../Constant/Constant.h"
#include "SFML/Graphics/Transform.hpp"
#include "SFML/Graphics/Drawable.hpp"

namespace sf
{
	class Color;
}

namespace engine
{
	namespace graphics
	{
		namespace shape
		{
			class Shape
			{
			public:
				Shape();
				Shape(const sf::Transform& relativePosition);

				virtual ~Shape() {}

				void SetRelativePosition(const sf::Transform& relativePosition);
				virtual void SetColor(sf::Color color) = 0;

				std::pair<const std::unique_ptr<sf::Drawable>&, const sf::Transform> GetShape() const;

			protected:
				sf::Transform relativePos;
				std::unique_ptr<sf::Drawable> drawable;
			};
		}
	}
}