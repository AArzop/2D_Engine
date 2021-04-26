#pragma once

#include "../../Graphics/GraphicManager.h"
#include "../../Gameplay/GameplayManager.h"

namespace engine
{
	namespace management
	{
		namespace load
		{
			class MapLoader
			{
			public:

				bool LoadMap(std::string filePath, graphics::Manager& graphicsManager, gameplay::Manager& gameplayManager);

			private:

				bool LoadGraphicsManager(std::ifstream& file, graphics::Manager& graphicsManager);
				bool LoadGameplayManager(std::ifstream& file, gameplay::Manager& gameplayManager);


			};
		}
	}
}