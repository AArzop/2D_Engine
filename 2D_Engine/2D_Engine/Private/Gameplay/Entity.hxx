#pragma once

#include "Entity.h"
#include "Component/Component.h"

namespace engine
{
	namespace gameplay
	{
		template <typename C>
		inline C* Entity::GetComponent() const
		{
			if (!std::is_base_of<component::Component, C>())
				return nullptr;

			for (auto& component : components)
			{
				if (dynamic_cast<C*>(component.get()))
					return reinterpret_cast<C*>(component.get());
			}
			
			return nullptr;
		}

		template<typename C>
		inline bool Entity::AddComponent()
		{
			if (!std::is_base_of<component::Component, C>())
				return false;

			if (GetComponent<C>())
				return false;

			ComponentPtr component = std::make_unique<C>(*this);
			components.push_back(std::move(component));
			return true;
		}
	}
}