#pragma once

#include <memory>
#include <vector>
#include <map>
#include <string>

#include "ManagerContext.h"
#include "../Management/Save/ISaveVisitable.h"

namespace engine
{
	namespace graphics
	{
		class Manager;
	}

	namespace management::load
	{
		class IComponentLoader;
	}

	namespace gameplay
	{
		class Entity;

		class Manager: public engine::management::save::ISaveVisitable
		{
		public:
			Manager(::engine::graphics::Manager& graphicsManager);
			~Manager();

			void Clear();

			bool Setup();
			void Start();
			void Update();

			Entity* CreateEntity();

#pragma region Management

			// Override SaveVisitable interface
			void Accept(engine::management::save::ISaveVisitor* const visitor) override;

			void FillComponentLoaders(std::map<std::string, management::load::IComponentLoader*>& shapeLoaders);

#pragma endregion

		private:
			using EntityPtr = std::unique_ptr<Entity>;

			std::vector<EntityPtr> Entities;

			ManagerContext Context;
		};
	}
}

