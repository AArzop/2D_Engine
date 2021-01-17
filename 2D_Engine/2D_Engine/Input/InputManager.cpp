#include "InputManager.h"

namespace engine
{
	namespace input
	{
		bool Manager::isKeyPressed(const sf::Keyboard::Key key) const
		{
			return sf::Keyboard::isKeyPressed(key);
		}

		bool Manager::isKeyJustPressed(const sf::Keyboard::Key key) const
		{
			return justPressedKey.find(key) != justPressedKey.end();
		}

		bool Manager::isKeyJustReleased(const sf::Keyboard::Key key) const
		{
			return justReleasedKey.find(key) != justReleasedKey.end();
		}

		void Manager::Clear()
		{
			justPressedKey.clear();
			justReleasedKey.clear();
		}

		void Manager::PressedKey(const sf::Keyboard::Key key)
		{
			justPressedKey.insert(key);
		}

		void Manager::ReleaseKey(const sf::Keyboard::Key key)
		{
			justReleasedKey.insert(key);
		}
	}
}
