#include "SaveVisitor.h"

#include "../../Gameplay/Component/Component.h"
#include "../../Gameplay/Component/Transform.h"

namespace engine
{
	namespace management
	{
		namespace save
		{
			SaveVisitor::SaveVisitor(const std::string& path)
			{
				Output.open(path);
			}

			void SaveVisitor::End()
			{
				Output.close();
			}

			void SaveVisitor::Visit(engine::Engine* const engine)
			{}

#pragma region gameplay

			void SaveVisitor::Visit(engine::gameplay::Manager* const gameplayManager)
			{}

			void SaveVisitor::Visit(engine::gameplay::Entity* const entity)
			{
				Output << "New Entity" << std::endl;
			}

			void SaveVisitor::Visit(engine::gameplay::component::Component* const component)
			{
				Output << component->GetComponentName() << "-" << component->GetSerializeData() << std::endl;
			}

#pragma endregion

			void SaveVisitor::Visit(ISaveVisitable* const visitable)
			{}
		}
	}
}