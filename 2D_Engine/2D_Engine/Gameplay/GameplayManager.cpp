#include "GameplayManager.h"

#include "Entity.h"

#include "Component/Transform.h"
#include "Component/Renderer.h"

#include "../Graphics/Shape/RectangleShape.h"
#include "../Graphics/Shape/CircleShape.h"

#include "../Management/Save/ISaveVisitor.h"


namespace engine
{
	namespace gameplay
	{
		Manager::Manager(::engine::graphics::Manager & graphicsManager) : context { graphicsManager }
		{}

		Manager::~Manager()
		{}

		bool Manager::Setup()
		{
			entities.push_back(std::make_unique<Entity>(context));
			entities[0]->AddComponent<component::Renderer>();

			component::Transform& t = *entities[0]->GetComponent<component::Transform>();
			t.SetPosition(sf::Vector2f(50, 50));

			component::Renderer& r = *entities[0]->GetComponent<component::Renderer>();
			graphics::shape::RectangleShape rect(10, 10);
			rect.SetColor(sf::Color::Red);
			r.AddNewShape<graphics::shape::RectangleShape>(&rect);

			graphics::shape::CircleShape circle(7);
			//r.AddNewShape<graphics::shape::CircleShape>(&circle);

			return true;
		}

		void Manager::Update()
		{
			for (auto& entity : entities)
			{
				entity->UpdateComponents();
			}
		}

		void Manager::Accept(engine::management::save::ISaveVisitor* const visitor)
		{
			visitor->Visit(this);

			for (auto& entity : entities)
			{
				entity->Accept(visitor);
			}
		}
	}
}		
