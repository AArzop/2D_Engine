#pragma once

#include <memory>
#include <vector>

#include <cassert>

#include "ManagerContext.h"

namespace engine
{
	namespace gameplay
	{
		namespace component
		{
			class Component;
		}

		class Entity
		{
			using ComponentPtr = std::unique_ptr<component::Component>;

		public:
			Entity(ManagerContext& context);
			~Entity();

			const ManagerContext& GetContext() const;

			void Start();
			void UpdateComponents();

			template <typename C>
			bool AddComponent();

			template <typename C>
			C* GetComponent() const;

		private:
			ManagerContext context;
			std::vector<ComponentPtr> components;
		};
	}
}

#include "Entity.hxx"

