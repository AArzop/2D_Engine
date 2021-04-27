#pragma once

#include "../../../Management/Load/ILoader.h"

namespace engine::gameplay::component
{
	class RendererComponentLoader : public management::load::IComponentLoader
	{
	public:
		void Instanciate(gameplay::Entity& entity, std::string json) override;
	};
}