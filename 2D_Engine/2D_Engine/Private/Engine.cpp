#include "../Public/Engine.h"
#include "Management/Save/ISaveVisitor.h"

#include <SFML/System.hpp>
#include <SFML/Window/Event.hpp>

#include "Management/Save/SaveVisitor.h"
#include "Management/Load/MapLoader.h"


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

		GameplayManager.Start();

		sf::Clock clock;
		while (Running)
		{
			DeltaTime = clock.restart().asSeconds();

			InputManager.Clear();

			GraphicsManager.PollEvent();

			GameplayManager.Update();

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

	void Engine::SaveMap(const std::string& filename)
	{
		management::save::SaveVisitor saveVisitor(filename);
		Accept(&saveVisitor);
		saveVisitor.End();
	}

	void Engine::LoadFile(const std::string& filename)
	{
		management::load::MapLoader mapLoader;
		mapLoader.LoadMap(filename, GraphicsManager, GameplayManager);
	}
}