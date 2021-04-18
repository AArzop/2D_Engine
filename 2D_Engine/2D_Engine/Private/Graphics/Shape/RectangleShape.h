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
				RectangleShape(uint32 width, uint32 leight, const sf::Transform& relativePosition = sf::Transform());

				void SetColor(sf::Color color) override;

				std::string GetShapeName() const override;

				std::string GetSerializeData() const override;

				~RectangleShape();
			private:
				sf::RectangleShape rect;
			};
		}
	}
}