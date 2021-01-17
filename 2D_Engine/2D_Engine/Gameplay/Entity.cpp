#include "Entity.h"

#include "Component/Component.h"
#include "Component/Transform.h"

namespace engine
{
	namespace gameplay
	{
		Entity::Entity(ManagerContext & context) : context { context }
		{
			AddComponent<component::Transform>();
		}

		Entity::~Entity()
		{}

		const ManagerContext & Entity::GetContext() const
		{
			return context;
		}

		void Entity::Start()
		{
			for (auto& component : components)
			{
				component->Start();
			}
		}

		void Entity::UpdateComponents()
		{
			for (auto& component : components)
			{
				component->Update();
			}
		}
	}
}