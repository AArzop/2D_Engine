#pragma once

#include <set>
#include <SFML/Window/Keyboard.hpp>

namespace engine
{
	namespace input
	{

		class Manager
		{
		public:
			bool IsKeyPressed(const sf::Keyboard::Key key) const;
			bool IsKeyJustPressed(const sf::Keyboard::Key key) const;
			bool IsKeyJustReleased(const sf::Keyboard::Key key) const;

			void Clear();

			void PressedKey(const sf::Keyboard::Key key);
			void ReleaseKey(const sf::Keyboard::Key key);

		private:
			std::set<sf::Keyboard::Key> JustPressedKey;
			std::set<sf::Keyboard::Key> JustReleasedKey;
		};
	}
}

