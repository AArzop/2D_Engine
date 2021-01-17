#pragma once

#include "SFML/Graphics/RenderWindow.hpp"
#include <vector>

namespace engine
{
	class EventHandler;

	namespace graphics
	{
		struct ShapeListInstance;

		class Manager
		{
		public:
			Manager() = delete;
			Manager(EventHandler& handler);
			
			~Manager();

			bool Setup();

			void Draw();

			void PollEvent();

			std::shared_ptr<ShapeListInstance>& CreateShapeListInstance();

		private:
			sf::RenderWindow window;

			::engine::EventHandler &eventHandler;

			std::vector<std::shared_ptr<ShapeListInstance>> shapeListInstance;

			const unsigned SCREEN_WIDTH = 700;
			const unsigned SCREEN_HEIGHT = 400;

		};
	}
}