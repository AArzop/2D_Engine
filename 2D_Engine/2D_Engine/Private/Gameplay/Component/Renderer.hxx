#pragma once

#include "Renderer.h"
#include "../../Graphics/ShapeListInstance.h"
#include "../../Graphics/GraphicManager.h"

namespace engine
{
	namespace gameplay
	{
		namespace component
		{
			template<typename S>
			inline void Renderer::AddNewShape(S* shape)
			{
				if (ShapeListInst.expired())
				{
					ShapeListInst = GetGraphicsManager().CreateShapeListInstance();
				}

				ShapeListInst.lock()->ShapeList.Add<S>(shape);
			}
		}
	}
}