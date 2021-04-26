#include "GraphicManager.h"

#include "../EventHandler.h"
#include "ShapeListInstance.h"

#include <SFML/Window/Event.hpp>

#include "../Management/Load/ILoader.h"
#include "Shape/Shape Loader/RectangleShapeLoader.h"
#include "Shape/RectangleShape.h"
#include "Shape/Shape Loader/CircleShapeLoader.h"
#include "Shape/CircleShape.h"

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

		std::shared_ptr<ShapeListInstance>& Manager::CreateShapeListInstance(uint64 saveId)
		{
			ShapeListInstance.push_back(std::make_shared<graphics::ShapeListInstance>(saveId));
			return ShapeListInstance[ShapeListInstance.size() - 1];
		}

		void Manager::Accept(engine::management::save::ISaveVisitor* const visitor)
		{
			GenerateShapeListInstanceSaveID();
			visitor->Visit(this);

			for (auto& instance : ShapeListInstance)
			{
				instance->Accept(visitor);
			}

			visitor->AddEndSection();
		}

		void Manager::GenerateShapeListInstanceSaveID()
		{
			for (uint32 i = 0; i < ShapeListInstance.size(); ++i)
			{
				ShapeListInstance[i]->SaveId = i;
			}
		}

		void Manager::FillShapeLoaders(std::map<std::string, management::load::IShapeLoader*>& shapeLoaders)
		{
			shapeLoaders[shape::RectangleShape::GetShapeName_Static()] = new shape::RectangleShapeLoader();
			shapeLoaders[shape::CircleShape::GetShapeName_Static()] = new shape::CircleShapeLoader();
		}

		void Manager::Clear()
		{
			ShapeListInstance.clear();
		}
	}
}