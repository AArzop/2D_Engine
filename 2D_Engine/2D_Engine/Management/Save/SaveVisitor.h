#pragma once

#include "ISaveVisitor.h"
#include <string>
#include <fstream>

namespace engine
{
#pragma region Forward declaration
	
	class Engine;

	#pragma region Gampleay

	namespace gameplay
	{
		class Manager;
		class Entity;

		namespace component
		{
			class Component;
			class Transform;
		}
	}

	#pragma endregion

#pragma endregion

	namespace management
	{
		namespace save
		{
			class SaveVisitor : public ISaveVisitor
			{
			public:

				SaveVisitor() = delete;
				SaveVisitor(const std::string& path);

				void End();

				void Visit(engine::Engine* const engine);

#pragma region Gameplay

				void Visit(engine::gameplay::Manager* const gameplayManager);
				void Visit(engine::gameplay::Entity* const entity);
				void Visit(engine::gameplay::component::Component* const component);

#pragma endregion

				// Default behavior
				void Visit(ISaveVisitable* const visitable) override;

			private:

				std::ofstream Output;
			};
		}
	}
}