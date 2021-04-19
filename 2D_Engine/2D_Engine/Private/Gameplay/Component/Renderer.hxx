#pragma once

#include "Renderer.h"
#include "../../Graphics/ShapeListInstance.h"

namespace engine
{
	namespace gameplay
	{
		namespace component
		{
			template<typename S>
			inline void Renderer::AddNewShape(S* shape)
			{
				ShapeListInst.lock()->ShapeList.Add<S>(shape);
			}
		}
	}
}