#include "Component.h"

#include "../Entity.h"

namespace engine
{
	namespace gameplay
	{
		namespace component
		{
			Component::Component(Entity& entity) : entity{ entity }
			{}


			Component::~Component()
			{
			}

			void Component::Start()
			{
			}

			void Component::Update()
			{
			}
			Entity & Component::GetEntity() const
			{
				return entity;
			}
		}
	}
}