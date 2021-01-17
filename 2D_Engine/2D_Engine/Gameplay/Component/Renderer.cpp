#include "Renderer.h"

#include "../Entity.h"
#include "../ManagerContext.h"
#include "../../Graphics/GraphicManager.h"
#include "Transform.h"
#include "../../Graphics/ShapeListInstance.h"
#include "../../Graphics/Shape/RectangleShape.h"

namespace engine
{
	namespace gameplay
	{
		namespace component
		{
			Renderer::Renderer(Entity& entity): Component(entity)
			{
				shapeListInst = GetGraphicsManager().CreateShapeListInstance();
			}

			Renderer::~Renderer()
			{}

			void Renderer::Start()
			{}

			void Renderer::Update()
			{
				if (!shapeListInst.expired())
				{
					component::Transform* transform = GetEntity().GetComponent<component::Transform>();
					if (transform)
					{
						shapeListInst.lock()->transform = transform->GetMatrix();
					}
				}
			}

			std::string Renderer::GetComponentName() const
			{
				return "Renderer";
			}

			std::string Renderer::GetSerializeData() const
			{
				return "Renderer:SerializeData";
			}

			graphics::Manager& Renderer::GetGraphicsManager()
			{
				return GetEntity().GetContext().graphicsManager;
			}
		}
	}
}