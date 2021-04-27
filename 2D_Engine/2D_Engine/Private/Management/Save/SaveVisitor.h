#pragma once

#include "ISaveVisitor.h"
#include <string>
#include <fstream>

namespace engine
{
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

				virtual void Visit(engine::gameplay::Manager* const gameplayManager) override;
				virtual void Visit(engine::gameplay::Entity* const entity) override;
				virtual void Visit(engine::gameplay::component::Component* const component) override;

#pragma endregion

#pragma region Graphics

				virtual void Visit(engine::graphics::Manager* const graphicsManager) override;
				virtual void Visit(engine::graphics::ShapeList* const shapeList) override;
				virtual void Visit(engine::graphics::ShapeListInstance* const shapeListInstance) override;
				virtual void Visit(engine::graphics::shape::Shape* const shape) override;

#pragma endregion

				// Default behavior
				void Visit(ISaveVisitable* const visitable) override;

				virtual void AddEndSection() override;


			private:

				std::ofstream Output;
			};
		}
	}
}