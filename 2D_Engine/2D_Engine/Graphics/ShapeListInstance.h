#pragma once

#include "ShapeList.h"
#include <SFML/Graphics/Transform.hpp>

namespace engine
{
	namespace graphics
	{
		struct ShapeListInstance
		{
			ShapeList shapeList;
			::sf::Transform transform;
			uint64 Id;
		};
	}
}