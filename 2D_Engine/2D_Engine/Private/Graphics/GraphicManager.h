#pragma once

#include "SFML/Graphics/RenderWindow.hpp"
#include <vector>

#include "../Management/Save/ISaveVisitable.h"

namespace engine
{
	class EventHandler;

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

			std::shared_ptr<ShapeListInstance>& CreateShapeListInstance();

			// Override SaveVisitable interface
			void Accept(engine::management::save::ISaveVisitor* const visitor) override;

		private:
			sf::RenderWindow Window;

			::engine::EventHandler &EventHandler;

			std::vector<std::shared_ptr<ShapeListInstance>> ShapeListInstance;

			const unsigned SCREEN_WIDTH = 700;
			const unsigned SCREEN_HEIGHT = 400;

		};
	}
}