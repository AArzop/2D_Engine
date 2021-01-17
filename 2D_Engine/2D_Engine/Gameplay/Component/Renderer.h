#pragma once

#include "Component.h"
#include "../../Graphics/Shape/Shape.h"

namespace engine
{
	namespace graphics
	{
		struct ShapeListInstance;
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
				Renderer(Entity& entity);
				~Renderer();

				template<typename S>
				void AddNewShape(S* shape);

				void Start() override;
				void Update() override;

				std::string GetComponentName() const override;
				std::string GetSerializeData() const override;

			private:
				std::weak_ptr<graphics::ShapeListInstance> shapeListInst;
				graphics::Manager& GetGraphicsManager();
			};
			
			
		}
	}
}

#include "Renderer.hxx"