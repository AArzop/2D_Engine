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

		public:
			ShapeList();
			~ShapeList();

			template <class S>
			shape::Shape* Add(S* shape);

			const std::vector<ShapePtr>& GetShapes() const;

			// Override SaveVisitable interface
			void Accept(engine::management::save::ISaveVisitor* const visitor) override;

		private:
			std::vector<ShapePtr> Shapes;
		};
		
		template<class S>
		inline shape::Shape* ShapeList::Add(S* shape)
		{
			if (!dynamic_cast<shape::Shape*>(shape))
			{
				assert(true);
				return nullptr;
			}

			std::unique_ptr<S> s = std::make_unique<S>(*shape);
			this->Shapes.push_back(std::move(s));
			return this->Shapes[this->Shapes.size() - 1].get();
		}
	}
}
