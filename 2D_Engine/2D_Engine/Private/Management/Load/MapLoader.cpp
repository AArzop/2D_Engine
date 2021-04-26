#include "MapLoader.h"

#include "ILoader.h"
#include "../ManagementConstant.h"
#include "../../Constant/Constant.h"
#include "../../Graphics/ShapeListInstance.h"
#include "../../Graphics/ShapeList.h"
#include "../../Graphics/Shape/Shape.h"



#include <fstream>
#include <iostream>
#include <map>
#include <string.h>
#include <string>

namespace engine::management::load
{
	bool MapLoader::LoadMap(std::string filePath, graphics::Manager& graphicsManager, gameplay::Manager& gameplayManager)
	{
		std::ifstream file;
		file.open(filePath, std::ifstream::in);
		if (!file.is_open())
		{
			std::cerr << "Unknown source: " << filePath << ", Can't load map" << std::endl;
			file.close();
			return false;
		}

		if (!LoadGraphicsManager(file, graphicsManager))
		{
			graphicsManager.Clear();
			return false;
		}

		if (!LoadGameplayManager(file, gameplayManager))
		{
			graphicsManager.Clear();
			gameplayManager.Clear();
			return false;
		}

		return true;
	}

	bool MapLoader::LoadGraphicsManager(std::ifstream& file, graphics::Manager& graphicsManager)
	{
		bool returnValue = true;
		std::map<std::string, IShapeLoader*> shapeLoaders;
		graphicsManager.FillShapeLoaders(shapeLoaders); // Must free loaders

		char line[1024];
		std::shared_ptr<engine::graphics::ShapeListInstance> shapeListInstance = nullptr;
		do
		{
			file.getline(line, 1024);
			if (strcmp(line, Token::SectionDelimiterToken) == 0)
			{
				break;
			}

			std::string strLine = line;
			uint8 delimiterPos = strLine.find_first_of(Token::InlineDelimiterToken);
			std::string objectName = strLine.substr(0, delimiterPos);
			std::string param = strLine.substr(delimiterPos + 1);

			if (objectName == Token::ShapeListInstanceToken)
			{
				uint64 saveId = _atoi64(param.c_str());
				shapeListInstance = graphicsManager.CreateShapeListInstance(saveId);
			}
			else
			{
				bool isLoaderFound = false;
				for (auto& pair : shapeLoaders)
				{
					if (objectName == pair.first)
					{
						isLoaderFound = true;
						pair.second->Instanciate(shapeListInstance->ShapeList, param);
						break;
					}
				}

				if (!isLoaderFound)
				{
					std::cerr << "Loader " << objectName << " is not found" << std::endl;
					returnValue = false;
					break;
				}
			}
		} while (!file.eof());

		for (auto& pair : shapeLoaders)
		{
			delete pair.second;
		}

		return returnValue;
	}

	bool MapLoader::LoadGameplayManager(std::ifstream& file, gameplay::Manager& gameplayManager)
	{
		return false;
	}
}
