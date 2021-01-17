#include "ShapeList.h"

#include <SFML/Graphics/Shape.hpp>

namespace engine
{
	namespace graphics
	{
		ShapeList::ShapeList(): shapes{}
		{}

		ShapeList::~ShapeList()
		{
			shapes.clear();
		}

		const ShapeList::Shapes& ShapeList::getShapes() const
		{
			return shapes;
		}
	}
}