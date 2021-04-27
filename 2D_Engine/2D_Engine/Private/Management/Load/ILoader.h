#pragma once

#include <string>

namespace engine
{
	namespace graphics
	{
		class ShapeList;
	}

	namespace gameplay
	{
		class Entity;
	}

	namespace management::load
	{
		class IShapeLoader
		{
		public:
			virtual void Instanciate(graphics::ShapeList& shapeList, std::string json) = 0;
		};

		class IComponentLoader
		{
		public:
			virtual void Instanciate(gameplay::Entity& entity, std::string json) = 0;
		};
	}
}
