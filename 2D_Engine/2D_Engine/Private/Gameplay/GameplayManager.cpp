#include "GameplayManager.h"

#include "Entity.h"

#include "Component/Loader/TransformComponentLoader.h"
#include "Component/Loader/RendererComponentLoader.h"
#include "Component/Transform.h"
#include "Component/Renderer.h"

#include "../Graphics/Shape/RectangleShape.h"
#include "../Graphics/Shape/CircleShape.h"

#include "../Management/Save/ISaveVisitor.h"


namespace engine
{
	namespace gameplay
	{
		Manager::Manager(::engine::graphics::Manager & graphicsManager) : Context { graphicsManager }
		{}

		Manager::~Manager()
		{}

		bool Manager::Setup()
		{
			return true;
		}

		void Manager::Start()
		{
			for (auto& entity : Entities)
			{
				entity->Start();
			}
		}

		void Manager::Update()
		{
			for (auto& entity : Entities)
			{
				entity->UpdateComponents();
			}
		}

		Entity* Manager::CreateEntity()
		{
			Entities.push_back(std::make_unique<Entity>(Context));
			return Entities[Entities.size() - 1].get();
		}

		void Manager::Accept(engine::management::save::ISaveVisitor* const visitor)
		{
			visitor->Visit(this);

			for (auto& entity : Entities)
			{
				entity->Accept(visitor);
			}

			visitor->AddEndSection();
		}

		void Manager::FillComponentLoaders(std::map<std::string, management::load::IComponentLoader*>& shapeLoaders)
		{
			shapeLoaders[component::Transform::GetComponentName_Static()] = new component::TransformComponentLoader();
			shapeLoaders[component::Renderer::GetComponentName_Static()] = new component::RendererComponentLoader();
		}

		void Manager::Clear()
		{
			Entities.clear();
		}
	}
}		
