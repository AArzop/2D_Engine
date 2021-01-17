#pragma once

#include "Component.h"
#include "SFML/Graphics/Transform.hpp"

namespace engine
{
	namespace gameplay
	{
		namespace component
		{
			class Transform : public Component
			{
			public:
				Transform(Entity& entity);
				~Transform();

				const sf::Transform& GetMatrix() const;

				void SetPosition(sf::Vector2f newPosition);
				void SetRotation(float newRotation);
				void SetScale(float newScale);

			private:
				sf::Transform matrix;

				sf::Vector2f position;
				float rotation;
				sf::Vector2f scale;

				void UpdateMatrix();
			};
		}
	}
}

