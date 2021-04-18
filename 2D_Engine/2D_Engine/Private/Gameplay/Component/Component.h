#pragma once

#include <string>
#include "../../Management/Save/ISaveVisitable.h"

namespace engine
{
	namespace gameplay
	{
		class Entity;

		namespace component
		{
			class Component : public engine::management::save::ISaveVisitable
			{
			public:
				Component() = delete;
				Component(Entity& entity);

				virtual ~Component();

				virtual void Start();

				virtual void Update();

				// Return the component's name. Have to be unique
				virtual std::string GetComponentName() const = 0;

				// Return json, mandatory to save
				virtual std::string GetSerializeData() const = 0;

				// Override SaveVisitable interface
				void Accept(engine::management::save::ISaveVisitor* const visitor) override;

			protected:
				Entity& GetEntity() const;

			private:
				Entity& entity;
			};
		}
	}
}