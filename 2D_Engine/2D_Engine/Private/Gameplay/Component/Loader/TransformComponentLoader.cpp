#include "TransformComponentLoader.h"

#include "../../Entity.h"
#include "../Transform.h"
#include "rapidjson/document.h"

namespace engine::gameplay::component
{
	void TransformComponentLoader::Instanciate(gameplay::Entity& entity, std::string json)
	{
		Transform* transform = entity.GetComponent<Transform>();
		if (transform)
		{
			rapidjson::Document d;
			d.Parse(json.c_str());

			auto arrPos = d["Position"].GetArray();
			auto arrScale = d["Scale"].GetArray();

			transform->SetPosition(sf::Vector2f(arrPos[0].GetFloat(), arrPos[1].GetFloat()));
			transform->SetRotation(d["Rotation"].GetFloat());
			transform->SetScale(sf::Vector2f(arrScale[0].GetFloat(), arrScale[1].GetFloat()));
		}
	}
}