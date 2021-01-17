#pragma once

#include <memory>
#include <vector>

#include "ManagerContext.h"

namespace engine
{
	namespace graphics
	{
		class Manager;
	}

	namespace gameplay
	{
		class Entity;

		class Manager
		{
		public:
			Manager(::engine::graphics::Manager& graphicsManager);
			~Manager();

			bool Setup();
			void Update();

		private:
			using EntityPtr = std::unique_ptr<Entity>;
			using Entities = std::vector<EntityPtr>;

			Entities entities;

			ManagerContext context;
		};
	}
}

