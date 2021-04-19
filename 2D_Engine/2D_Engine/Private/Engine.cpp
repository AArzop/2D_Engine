#include "../Public/Engine.h"
#include "Management/Save/ISaveVisitor.h"

#include <SFML/System.hpp>
#include <SFML/Window/Event.hpp>

#include "Management/Save/SaveVisitor.h"


namespace engine
{
	Engine::Engine() : GraphicsManager{ *this }, GameplayManager{ GraphicsManager }, InputManager{}, Running(false)
	{}

	bool Engine::Setup()
	{
		if (!GraphicsManager.Setup())
			return false;

		if (!GameplayManager.Setup())
			return false;

		return true;
	}

	void Engine::Run()
	{
		if (Running)
			return;

		Running = true;

		sf::Clock clock;
		while (Running)
		{
			DeltaTime = clock.restart().asSeconds();

			InputManager.Clear();

			GraphicsManager.PollEvent();

			GraphicsManager.Draw();
		}
	}

	void Engine::Stop()
	{
		if (!Running)
			return;

		Running = false;
	}

	float Engine::GetDeltaTime() const
	{
		return DeltaTime;
	}
	
	void Engine::HandleEvent(const sf::Event& event)
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			Stop();
			break;

		case sf::Event::KeyPressed:
			InputManager.PressedKey(event.key.code);
			break;

		case sf::Event::KeyReleased:
			InputManager.ReleaseKey(event.key.code);
			break;

		default:
			break;
		}
	}

	void Engine::Accept(management::save::ISaveVisitor* const visitor)
	{
		visitor->Visit(this);

		GraphicsManager.Accept(visitor);

		GameplayManager.Accept(visitor);
	}

	void Engine::SaveMap()
	{
		management::save::SaveVisitor saveVisitor("E:/TestSave.txt");
		Accept(&saveVisitor);
		saveVisitor.End();
	}
}