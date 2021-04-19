#pragma once

namespace sf { class Event; }

namespace engine
{
	class EventHandler
	{
	public:
		virtual void HandleEvent(const sf::Event& event) = 0;
	};
}