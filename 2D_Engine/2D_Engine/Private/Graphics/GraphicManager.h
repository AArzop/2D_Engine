#pragma once

#include "SFML/Graphics/RenderWindow.hpp"

#include <vector>
#include <map>

#include "../Management/Save/ISaveVisitable.h"
#include "../Constant/Constant.h"

namespace engine
{
	class EventHandler;

	namespace management
	{
		namespace load
		{
			class IShapeLoader;
		}
	}

	namespace graphics
	{
		class ShapeListInstance;

		class Manager : public engine::management::save::ISaveVisitable
		{
		public:
			Manager() = delete;
			Manager(EventHandler& handler);

			~Manager();

			bool Setup();

			void Draw();

			void PollEvent();

			void Clear();

			std::shared_ptr<ShapeListInstance>& CreateShapeListInstance(uint64 saveId = 0);
			std::shared_ptr<ShapeListInstance>& FindShapeListInstanceById(uint64 id);

#pragma region Management

			// Override SaveVisitable interface
			void Accept(engine::management::save::ISaveVisitor* const visitor) override;

			// Call to set shapeListInst saveId
			void GenerateShapeListInstanceSaveID();

			// Fill map with all shape loader. Must free memory
			void FillShapeLoaders(std::map<std::string, management::load::IShapeLoader*>& shapeLoaders);

#pragma endregion

		private:
			sf::RenderWindow Window;

			::engine::EventHandler &EventHandler;

			std::vector<std::shared_ptr<ShapeListInstance>> ShapeListInstance;

			const unsigned SCREEN_WIDTH = 700;
			const unsigned SCREEN_HEIGHT = 400;

		};
	}
}