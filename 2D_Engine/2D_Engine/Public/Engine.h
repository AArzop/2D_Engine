#pragma once

#include "../Private/EventHandler.h"

#include "../Private/Graphics/GraphicManager.h"
#include "../Private/Input/InputManager.h"
#include "../Private/Gameplay/GameplayManager.h"
#include "../Private/Management/Save/ISaveVisitable.h"


namespace engine
{
	class Engine : public EventHandler, public management::save::ISaveVisitable
	{
	public:

		Engine();

		bool Setup();

		void Run();

		void Stop();

		float GetDeltaTime() const;

		virtual void HandleEvent(const sf::Event& event) override;

		void Accept(management::save::ISaveVisitor* const visitor) override;

		void SaveMap();

	private:
		graphics::Manager graphicsManager;
		input::Manager inputManager;
		gameplay::Manager gameplayManager;

		bool running;
		float deltaTime;
	};
}