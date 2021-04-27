#include "Transform.h"

#include "../Entity.h"
#include "../../Management/Save/SaveVisitor.h"
#include "../../Management/UtilFunctions.h"

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"


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

			void Transform::SetScale(sf::Vector2f newScale)
			{
				Scale = newScale;
				UpdateMatrix();
			}

			std::string Transform::GetComponentName() const
			{
				return GetComponentName_Static();
			}

			std::string Transform::GetComponentName_Static()
			{
				return "Transform";
			}

			std::string Transform::GetSerializeData() const
			{
				rapidjson::Document d;
				d.SetObject();

				auto alloc = d.GetAllocator();
				FillVector2fField(d, "Position", Position);
				FillVector2fField(d, "Scale", Scale);

				rapidjson::Value rot(rapidjson::kNumberType);
				rot.SetFloat(Rotation);
				d.AddMember("Rotation", rot, d.GetAllocator());

				rapidjson::StringBuffer buffer;
				rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
				d.Accept(writer);

				return buffer.GetString();
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
