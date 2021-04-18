#pragma once

#include <memory>
#include <vector>
#include <cassert>

#include "ManagerContext.h"
#include "../Management/Save/ISaveVisitable.h"

namespace engine
{
	namespace gameplay
	{
		namespace component
		{
			class Component;
		}

		class Entity : public engine::management::save::ISaveVisitable
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

			// Override SaveVisitable interface
			void Accept(engine::management::save::ISaveVisitor* const visitor) override;

		private:
			ManagerContext context;
			std::vector<ComponentPtr> components;
		};
	}
}

#include "Entity.hxx"

