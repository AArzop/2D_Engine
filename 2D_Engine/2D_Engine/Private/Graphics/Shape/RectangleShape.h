#pragma once

#include "Shape.h"
#include "SFML/Graphics/RectangleShape.hpp"

namespace engine
{
	namespace graphics
	{
		namespace shape
		{
			class RectangleShape : public Shape
			{
			public:
				RectangleShape(const RectangleShape& rectangle);
				RectangleShape(uint32 width, uint32 height, const sf::Transform& relativePosition = sf::Transform());

				void SetColor(sf::Color color) override;

				std::string GetShapeName() const override;
				static std::string GetShapeName_Static();

				std::string GetSerializeData() const override;

				~RectangleShape();
			private:
				sf::RectangleShape Rect;
			};
		}
	}
}