#include "Renderer.h"

#include "../Entity.h"
#include "../ManagerContext.h"
#include "../../Graphics/GraphicManager.h"
#include "Transform.h"
#include "../../Graphics/ShapeListInstance.h"
#include "../../Graphics/Shape/RectangleShape.h"

#include "../../Management/UtilFunctions.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

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
				rapidjson::Document d;
				d.SetObject();

				rapidjson::Value id(rapidjson::kNumberType);
				id.SetUint64(ShapeListInst.lock()->SaveId);
				d.AddMember("SaveId", id, d.GetAllocator());

				rapidjson::StringBuffer buffer;
				rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
				d.Accept(writer);

				return buffer.GetString();
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