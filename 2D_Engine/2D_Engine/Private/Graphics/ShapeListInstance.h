#pragma once

#include "ShapeList.h"
#include <SFML/Graphics/Transform.hpp>

#include "../Management/Save/ISaveVisitable.h"

namespace engine
{
	namespace graphics
	{
		class ShapeListInstance : public engine::management::save::ISaveVisitable
		{
		public:
			ShapeList ShapeList;
			::sf::Transform Transform;
			uint64 Id;

			// Override SaveVisitable interface
			void Accept(engine::management::save::ISaveVisitor* const visitor) override;
		};
	}
}