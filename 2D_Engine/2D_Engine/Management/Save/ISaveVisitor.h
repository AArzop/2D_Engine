#pragma once

#include "../IVisitor.h"

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
		}
	}

	#pragma endregion

#pragma endregion

	namespace management
	{
		namespace save
		{
			class ISaveVisitable;

			class ISaveVisitor : public IVisitor
			{
			public:

				void Visit(IVisitable* const visitable) override {};
				virtual void Visit(ISaveVisitable* const visitable) = 0;
				virtual void Visit(engine::Engine* const visitable) = 0;
				virtual void Visit(engine::gameplay::Manager* const gameplayManager) = 0;
				virtual void Visit(engine::gameplay::Entity* const entity) = 0;
				virtual void Visit(engine::gameplay::component::Component* const component) = 0;

			};
		}
	}
}