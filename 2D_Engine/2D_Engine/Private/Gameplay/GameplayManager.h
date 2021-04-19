#pragma once

#include <memory>
#include <vector>

#include "ManagerContext.h"
#include "../Management/Save/ISaveVisitable.h"

namespace engine
{
	namespace graphics
	{
		class Manager;
	}

	namespace gameplay
	{
		class Entity;

		class Manager: public engine::management::save::ISaveVisitable
		{
		public:
			Manager(::engine::graphics::Manager& graphicsManager);
			~Manager();

			bool Setup();
			void Update();

			// Override SaveVisitable interface
			void Accept(engine::management::save::ISaveVisitor* const visitor) override;

		private:
			using EntityPtr = std::unique_ptr<Entity>;

			std::vector<EntityPtr> Entities;

			ManagerContext Context;
		};
	}
}

