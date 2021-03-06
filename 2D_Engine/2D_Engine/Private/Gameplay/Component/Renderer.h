#pragma once

#include "Component.h"
#include "../../Graphics/Shape/Shape.h"

namespace engine
{
	namespace graphics
	{
		class ShapeListInstance;
		class Manager;

		namespace shape
		{
			class Shape;
			class RectangleShape;
		}
	}

	namespace gameplay
	{
		class Entity;

		namespace component
		{
			class Renderer : public Component
			{
			public:
				Renderer(gameplay::Entity& entity);
				~Renderer();

				void LinkTo(uint64 id);

				template<typename S>
				void AddNewShape(S* shape);

				void Start() override;
				void Update() override;

				std::string GetComponentName() const override;
				static std::string GetComponentName_Static();
				std::string GetSerializeData() const override;

			private:

				void UpdateWithTransform();

				std::weak_ptr<graphics::ShapeListInstance> ShapeListInst;
				graphics::Manager& GetGraphicsManager();
			};
			
			
		}
	}
}

#include "Renderer.hxx"