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
				void SetScale(sf::Vector2f newScale);

				std::string GetComponentName() const override;
				static std::string GetComponentName_Static();
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

