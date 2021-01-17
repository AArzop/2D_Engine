#include "ShapeListInstance.h"

#include "../Management/Save/ISaveVisitor.h"

namespace engine
{
	namespace graphics
	{
		void ShapeListInstance::Accept(engine::management::save::ISaveVisitor* const visitor)
		{
			visitor->Visit(this);
			shapeList.Accept(visitor);
		}
	}
}