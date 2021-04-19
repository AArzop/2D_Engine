#include "../Public/Engine.h"
#include "Management/Save/ISaveVisitor.h"

#include <SFML/System.hpp>
#include <SFML/Window/Event.hpp>

#include "Management/Save/SaveVisitor.h"


namespace engine
{
	Engine::Engine() : graphicsManager{ *this }, gameplayManager{ graphicsManager }, inputManager{}, running(false)
	{}

	bool Engine::Setup()
	{
		if (!graphicsManager.Setup())
			return false;

		if (!gameplayManager.Setup())
			return false;

		return true;
	}

	void Engine::Run()
	{
		if (running)
			return;

		running = true;

		sf::Clock clock;
		while (running)
		{
			deltaTime = clock.restart().asSeconds();

			inputManager.Clear();

			graphicsManager.PollEvent();

			graphicsManager.Draw();
		}
	}

	void Engine::Stop()
	{
		if (!running)
			return;

		running = false;
	}

	float Engine::GetDeltaTime() const
	{
		return deltaTime;
	}
	
	void Engine::HandleEvent(const sf::Event& event)
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			Stop();
			break;

		case sf::Event::KeyPressed:
			inputManager.PressedKey(event.key.code);
			break;

		case sf::Event::KeyReleased:
			inputManager.ReleaseKey(event.key.code);
			break;

		default:
			break;
		}
	}

	void Engine::Accept(management::save::ISaveVisitor* const visitor)
	{
		visitor->Visit(this);

		graphicsManager.Accept(visitor);

		gameplayManager.Accept(visitor);
	}

	void Engine::SaveMap()
	{
		management::save::SaveVisitor saveVisitor("E:/TestSave.txt");
		Accept(&saveVisitor);
		saveVisitor.End();
	}
}