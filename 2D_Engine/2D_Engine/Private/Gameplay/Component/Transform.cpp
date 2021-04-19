#include "Transform.h"

#include "../Entity.h"
#include "../../Management/Save/SaveVisitor.h"

#include <sstream>


namespace engine
{
	namespace gameplay
	{
		namespace component
		{
			Transform::Transform(gameplay::Entity& entity): Component(entity)
			{
				Position = sf::Vector2f();
				Rotation = 0.f;
				Scale = sf::Vector2f(1.f, 1.f);

				UpdateMatrix();
			}


			Transform::~Transform()
			{}

			const sf::Transform& Transform::GetMatrix() const
			{
				return Matrix;
			}

			void Transform::SetPosition(sf::Vector2f newPosition)
			{
				Position = newPosition;
				UpdateMatrix();
			}

			void Transform::SetRotation(float newRotation)
			{
				Rotation = newRotation;
				UpdateMatrix();
			}

			void Transform::SetScale(float newScale)
			{
				Rotation = newScale;
				UpdateMatrix();
			}

			std::string Transform::GetComponentName() const
			{
				return "Transform";
			}

			std::string Transform::GetSerializeData() const
			{
				std::ostringstream oss;
				oss << "{Position:{x:" << Position.x << ",y:" << Position.y << "},Rotation:" << Rotation << ",Scale:{x:" << Scale.x << ",y:" << Scale.y << "}}";
				return oss.str();
			}

			void Transform::UpdateMatrix()
			{
				Matrix = sf::Transform::Identity;
				Matrix.translate(Position);
				Matrix.rotate(Rotation);
				Matrix.scale(Scale);

				GetEntity().UpdateComponents();
			}

		}
	}
}
