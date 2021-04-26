#pragma once

#include "../../../Management/Load/ILoader.h"

namespace engine::graphics::shape
{
	class CircleShapeLoader : public management::load::IShapeLoader
	{
	public:
		virtual void Instanciate(graphics::ShapeList& shapeList, std::string json) override;
	};
}