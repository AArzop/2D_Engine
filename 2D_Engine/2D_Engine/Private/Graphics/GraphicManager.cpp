#include "GraphicManager.h"

#include "../EventHandler.h"
#include "ShapeListInstance.h"

#include <SFML/Window/Event.hpp>

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "../Management/Save/ISaveVisitor.h"

namespace engine
{
	namespace graphics
	{
		Manager::Manager(::engine::EventHandler& handler) : EventHandler(handler)
		{}

		Manager::~Manager()
		{}

		bool Manager::Setup()
		{
			Window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Engine");
			if (!Window.isOpen())
				return false;

			Window.setVerticalSyncEnabled(true);
			return true;
		}

		void Manager::Draw()
		{
			Window.clear(sf::Color::Black);

			for (auto& instance : ShapeListInstance)
			{
				for (auto& shape : instance->ShapeList.GetShapes())
				{
					auto p = shape->GetShape();
					sf::RenderStates renderStates(instance->Transform.combine(p.second));
					Window.draw(*p.first, renderStates);
				}
			}

			Window.display();
		}

		void Manager::PollEvent()
		{
			sf::Event event;
			while (Window.pollEvent(event))
			{
				EventHandler.HandleEvent(event);
			}
		}

		std::shared_ptr<ShapeListInstance>& Manager::CreateShapeListInstance()
		{
			ShapeListInstance.push_back(std::make_shared<graphics::ShapeListInstance>());
			return ShapeListInstance[ShapeListInstance.size() - 1];
		}

		void Manager::Accept(engine::management::save::ISaveVisitor* const visitor)
		{
			visitor->Visit(this);

			for (auto& instance : ShapeListInstance)
			{
				instance->Accept(visitor);
			}
		}
	}
}