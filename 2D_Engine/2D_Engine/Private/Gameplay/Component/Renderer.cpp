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
			Renderer::Renderer(gameplay::Entity& entity): Component(entity)
			{
				ShapeListInst = GetGraphicsManager().CreateShapeListInstance();
			}

			Renderer::~Renderer()
			{}

			void Renderer::Start()
			{}

			void Renderer::Update()
			{
				if (!ShapeListInst.expired())
				{
					component::Transform* transform = GetEntity().GetComponent<component::Transform>();
					if (transform)
					{
						ShapeListInst.lock()->Transform = transform->GetMatrix();
					}
				}
			}

			std::string Renderer::GetComponentName() const
			{
				return "Renderer";
			}

			std::string Renderer::GetSerializeData() const
			{
				return "{Id:" + std::to_string(ShapeListInst.lock()->Id) + "}";
			}

			graphics::Manager& Renderer::GetGraphicsManager()
			{
				return GetEntity().GetContext().GraphicsManager;
			}
		}
	}
}