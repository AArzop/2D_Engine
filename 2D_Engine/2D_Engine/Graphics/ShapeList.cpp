#include "ShapeList.h"

#include <SFML/Graphics/Shape.hpp>

#include "../Management/Save/ISaveVisitor.h"

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

		void ShapeList::Accept(engine::management::save::ISaveVisitor* const visitor)
		{
			visitor->Visit(this);

			for (auto& shape : shapes)
			{
				shape->Accept(visitor);
			}
		}
	}
}