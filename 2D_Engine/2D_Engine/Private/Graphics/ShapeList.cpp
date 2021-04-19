#include "ShapeList.h"

#include <SFML/Graphics/Shape.hpp>

#include "../Management/Save/ISaveVisitor.h"

namespace engine
{
	namespace graphics
	{
		ShapeList::ShapeList(): Shapes{}
		{}

		ShapeList::~ShapeList()
		{
			Shapes.clear();
		}

		const std::vector<ShapeList::ShapePtr>& ShapeList::GetShapes() const
		{
			return Shapes;
		}

		void ShapeList::Accept(engine::management::save::ISaveVisitor* const visitor)
		{
			visitor->Visit(this);

			for (auto& shape : Shapes)
			{
				shape->Accept(visitor);
			}
		}
	}
}