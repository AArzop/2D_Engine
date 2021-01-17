#pragma once

#include <memory>
#include <vector>
#include <cassert>

#include "Shape/Shape.h"

namespace engine
{
	namespace graphics
	{
		class ShapeList
		{
			using ShapePtr = std::unique_ptr<shape::Shape>;
			using Shapes = std::vector<ShapePtr>;

		public:
			ShapeList();
			~ShapeList();

			template <class S2>
			void Add(S2* shape);

			const Shapes& getShapes() const;

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
