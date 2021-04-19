#include "Entity.h"

#include "Component/Component.h"
#include "Component/Transform.h"

#include "../Management/Save/ISaveVisitor.h"

namespace engine
{
	namespace gameplay
	{
		Entity::Entity(ManagerContext & context) : Context { context }
		{
			AddComponent<component::Transform>();
		}

		Entity::~Entity()
		{}

		const ManagerContext & Entity::GetContext() const
		{
			return Context;
		}

		void Entity::Start()
		{
			for (auto& component : Components)
			{
				component->Start();
			}
		}

		void Entity::UpdateComponents()
		{
			for (auto& component : Components)
			{
				component->Update();
			}
		}

		void Entity::Accept(engine::management::save::ISaveVisitor* const visitor)
		{
			visitor->Visit(this);

			for (auto& component : Components)
			{
				component->Accept(visitor);
			}
		}
	}
}