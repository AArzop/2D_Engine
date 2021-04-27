#include "RendererComponentLoader.h"

#include "../../Entity.h"
#include "../Renderer.h"
#include "rapidjson/document.h"

namespace engine::gameplay::component
{
	void RendererComponentLoader::Instanciate(gameplay::Entity& entity, std::string json)
	{
		rapidjson::Document d;
		d.Parse(json.c_str());

		entity.AddComponent<Renderer>();
		component::Renderer* renderer = entity.GetComponent<component::Renderer>();
		if (renderer)
		{
			renderer->LinkTo(d["SaveId"].GetUint64());
		}
	}
}