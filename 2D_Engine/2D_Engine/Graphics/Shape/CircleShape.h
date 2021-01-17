#pragma once

#include "Shape.h"
#include "SFML/Graphics/CircleShape.hpp"

namespace engine
{
	namespace graphics
	{
		namespace shape
		{
			class CircleShape: public Shape
			{
			public:
				CircleShape(const CircleShape& circle);
				CircleShape(uint32 radius, const sf::Transform& relativePosition = sf::Transform());

				void SetColor(sf::Color color) override;

				~CircleShape();
			private:
				sf::CircleShape circle;
			};
		}
	}
}