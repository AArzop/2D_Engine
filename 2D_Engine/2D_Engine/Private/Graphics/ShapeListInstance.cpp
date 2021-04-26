#include "ShapeListInstance.h"

#include "../Management/Save/ISaveVisitor.h"

namespace engine
{
	namespace graphics
	{
		ShapeListInstance::ShapeListInstance(uint64 saveId): SaveId(saveId)
		{}
		void ShapeListInstance::Accept(engine::management::save::ISaveVisitor* const visitor)
		{
			visitor->Visit(this);
			ShapeList.Accept(visitor);
		}
	}
}