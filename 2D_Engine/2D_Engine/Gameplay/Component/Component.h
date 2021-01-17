#pragma once

namespace engine
{
	namespace gameplay
	{
		class Entity;

		namespace component
		{
			class Component
			{
			public:
				Component() = delete;
				Component(Entity& entity);

				virtual ~Component();

				virtual void Start();

				virtual void Update();

			protected:
				Entity& GetEntity() const;

			private:
				Entity& entity;
			};
		}
	}
}