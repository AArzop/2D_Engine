#pragma once

#include <memory>
#include <vector>
#include <cassert>

#include "Shape/Shape.h"

#include "../Management/Save/ISaveVisitable.h"

namespace engine
{
	namespace graphics
	{
		class ShapeList : public engine::management::save::ISaveVisitable
		{
			using ShapePtr = std::unique_ptr<shape::Shape>;
			using Shapes = std::vector<ShapePtr>;

		public:
			ShapeList();
			~ShapeList();

			template <class S2>
			void Add(S2* shape);

			const Shapes& getShapes() const;

			// Override SaveVisitable interface
			void Accept(engine::management::save::ISaveVisitor* const visitor) override;

		private:
			Shapes shapes;
		};
		
		template<class S2>
		inline void ShapeList::Add(S2* shape)
		{
			if (!dynamic_cast<shape::Shape*>(shape))
			{
				assert(true);
				return;
			}

			std::unique_ptr<S2> s = std::make_unique<S2>(*shape);
			this->shapes.push_back(std::move(s));
		}
	}
}
