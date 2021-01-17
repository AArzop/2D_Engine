#include "Transform.h"

#include "../Entity.h"
#include "../../Management/Save/SaveVisitor.h"


namespace engine
{
	namespace gameplay
	{
		namespace component
		{
			Transform::Transform(Entity& entity): Component(entity)
			{
				position = sf::Vector2f();
				rotation = 0.f;
				scale = sf::Vector2f(1.f, 1.f);

				UpdateMatrix();
			}


			Transform::~Transform()
			{}

			const sf::Transform& Transform::GetMatrix() const
			{
				return matrix;
			}

			void Transform::SetPosition(sf::Vector2f newPosition)
			{
				position = newPosition;
				UpdateMatrix();
			}

			void Transform::SetRotation(float newRotation)
			{
				rotation = newRotation;
				UpdateMatrix();
			}

			void Transform::SetScale(float newScale)
			{
				rotation = newScale;
				UpdateMatrix();
			}

			std::string Transform::GetComponentName() const
			{
				return "Transform";
			}

			std::string Transform::GetSerializeData() const
			{
				return "Transform:SerializeData";
			}

			void Transform::UpdateMatrix()
			{
				matrix = sf::Transform::Identity;
				matrix.translate(position);
				matrix.rotate(rotation);
				matrix.scale(scale);

				GetEntity().UpdateComponents();
			}

		}
	}
}
