#pragma once

#include "EventHandler.h"

#include "Graphics/GraphicManager.h"
#include "Input/InputManager.h"
#include "Gameplay/GameplayManager.h"

namespace engine
{
	

	class Engine : public EventHandler
	{
	public:

		Engine();

		bool Setup();

		void Run();

		void Stop();

		float GetDeltaTime() const;

		virtual void HandleEvent(const sf::Event& event) override;

	private:
		graphics::Manager graphicsManager;
		input::Manager inputManager;
		gameplay::Manager gameplayManager;

		bool running;
		float deltaTime;
	};
}