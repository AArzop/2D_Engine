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
			Renderer::Renderer(gameplay::Entity& entity) : Component(entity)
			{}

			Renderer::~Renderer()
			{}

			void Renderer::LinkTo(uint64 id)
			{
				ShapeListInst = GetGraphicsManager().FindShapeListInstanceById(id);
			}

			void Renderer::Start()
			{
				UpdateWithTransform();
			}

			void Renderer::Update()
			{
				UpdateWithTransform();
			}

			std::string Renderer::GetComponentName() const
			{
				return GetComponentName_Static();
			}

			std::string Renderer::GetComponentName_Static()
			{
				return "Renderer";
			}

			std::string Renderer::GetSerializeData() const
			{
				return "{SaveId:" + std::to_string(ShapeListInst.lock()->SaveId) + "}";
			}

			void Renderer::UpdateWithTransform()
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

			graphics::Manager& Renderer::GetGraphicsManager()
			{
				return GetEntity().GetContext().GraphicsManager;
			}
		}
	}
}