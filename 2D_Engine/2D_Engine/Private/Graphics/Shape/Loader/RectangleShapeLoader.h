#pragma once

#include "../../../Management/Load/ILoader.h"

namespace engine::graphics::shape
{
	class RectangleShapeLoader : public management::load::IShapeLoader
	{
	public:
		void Instanciate(graphics::ShapeList& shapeList, std::string json) override;

	};
}