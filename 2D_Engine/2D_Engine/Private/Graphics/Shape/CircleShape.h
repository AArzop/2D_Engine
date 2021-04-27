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

				std::string GetShapeName() const override;
				static std::string GetShapeName_Static();

				std::string GetSerializeData() const override;

				~CircleShape();
			private:
				sf::CircleShape Circle;
			};
		}
	}
}