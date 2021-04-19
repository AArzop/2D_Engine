#include "Component.h"

#include "../Entity.h"
#include "../../Management/Save/SaveVisitor.h"

namespace engine
{
	namespace gameplay
	{
		namespace component
		{
			Component::Component(gameplay::Entity& entity) : Entity{ entity }
			{}


			Component::~Component()
			{}

			void Component::Start()
			{}

			void Component::Update()
			{}

			void Component::Accept(engine::management::save::ISaveVisitor* const visitor)
			{
				visitor->Visit(this);
			}

			Entity& Component::GetEntity() const
			{
				return Entity;
			}
		}
	}
}