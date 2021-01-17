#include "GraphicManager.h"

#include "../EventHandler.h"
#include "ShapeListInstance.h"

#include <SFML/Window/Event.hpp>

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>


namespace engine
{
	namespace graphics
	{
		Manager::Manager(::engine::EventHandler& handler) : eventHandler(handler)
		{}

		Manager::~Manager()
		{}

		bool Manager::Setup()
		{
			window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Engine");
			if (!window.isOpen())
				return false;

			window.setVerticalSyncEnabled(true);
			return true;
		}

		void Manager::Draw()
		{
			window.clear(sf::Color::Black);

			for (auto& instance : shapeListInstance)
			{
				for (auto& shape : instance->shapeList.getShapes())
				{
					auto p = shape->GetShape();
					sf::RenderStates renderStates(instance->transform.combine(p.second));
					window.draw(*p.first, renderStates);
				}
			}

			window.display();
		}

		void Manager::PollEvent()
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				eventHandler.HandleEvent(event);
			}
		}
		std::shared_ptr<ShapeListInstance>& Manager::CreateShapeListInstance()
		{
			shapeListInstance.push_back(std::make_shared<ShapeListInstance>());
			return shapeListInstance[shapeListInstance.size() - 1];
		}
	}
}