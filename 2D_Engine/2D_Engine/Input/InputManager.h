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
			bool isKeyPressed(const sf::Keyboard::Key key) const;
			bool isKeyJustPressed(const sf::Keyboard::Key key) const;
			bool isKeyJustReleased(const sf::Keyboard::Key key) const;

			void Clear();

			void PressedKey(const sf::Keyboard::Key key);
			void ReleaseKey(const sf::Keyboard::Key key);

		private:
			std::set<sf::Keyboard::Key> justPressedKey;
			std::set<sf::Keyboard::Key> justReleasedKey;
		};
	}
}

