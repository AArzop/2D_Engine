#pragma once

#include <memory>

#include "../../Constant/Constant.h"
#include "SFML/Graphics/Transform.hpp"
#include "SFML/Graphics/Drawable.hpp"

#include "../../Management/Save/ISaveVisitable.h"
#include <string>

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
			class Shape : public engine::management::save::ISaveVisitable
			{
			public:
				Shape();
				Shape(const sf::Transform& relativePosition);

				virtual ~Shape() {}

				void SetRelativePosition(const sf::Transform& relativePosition);
				virtual void SetColor(sf::Color color) = 0;

				std::pair<const std::unique_ptr<sf::Drawable>&, const sf::Transform> GetShape() const;

				// Return the shape's name. Have to be unique
				virtual std::string GetShapeName() const = 0;

				virtual std::string GetSerializeData() const = 0;

				// Override SaveVisitable interface
				void Accept(engine::management::save::ISaveVisitor* const visitor) override;

			protected:

				std::string GetTransformSerialize() const;

				sf::Transform RelativePos;
				std::unique_ptr<sf::Drawable> Drawable;
			};
		}
	}
}