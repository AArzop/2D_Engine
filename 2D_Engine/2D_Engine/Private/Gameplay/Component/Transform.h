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
				Transform(gameplay::Entity& entity);
				~Transform();

				const sf::Transform& GetMatrix() const;

				void SetPosition(sf::Vector2f newPosition);
				void SetRotation(float newRotation);
				void SetScale(float newScale);

				std::string GetComponentName() const override;
				std::string GetSerializeData() const override;

			private:
				sf::Transform Matrix;

				sf::Vector2f Position;
				float Rotation;
				sf::Vector2f Scale;

				void UpdateMatrix();
			};
		}
	}
}

