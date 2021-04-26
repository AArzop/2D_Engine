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

	#pragma region Graphics

	namespace graphics
	{
		class Manager;
		class ShapeList;
		class ShapeListInstance;

		namespace shape
		{
			class Shape;
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

#pragma region Gameplay

				virtual void Visit(engine::gameplay::Manager* const gameplayManager) = 0;
				virtual void Visit(engine::gameplay::Entity* const entity) = 0;
				virtual void Visit(engine::gameplay::component::Component* const component) = 0;

#pragma endregion

#pragma region Graphics

				virtual void Visit(engine::graphics::Manager* const graphicsManager) = 0;
				virtual void Visit(engine::graphics::ShapeList* const shapeList) = 0;
				virtual void Visit(engine::graphics::ShapeListInstance* const shapeListInstance) = 0;
				virtual void Visit(engine::graphics::shape::Shape* const shape) = 0;

#pragma endregion

				virtual void AddEndSection() = 0;

			};
		}
	}
}