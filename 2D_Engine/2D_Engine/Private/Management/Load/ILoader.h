#pragma once

#include <string>

namespace engine
{
	namespace graphics
	{
		class ShapeList;
	}

	namespace management::load
	{
		class IShapeLoader
		{
		public:
			virtual void Instanciate(graphics::ShapeList& shapeList, std::string json) = 0;
		};
	}
}
