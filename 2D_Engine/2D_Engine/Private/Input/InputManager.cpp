#include "InputManager.h"

namespace engine
{
	namespace input
	{
		bool Manager::IsKeyPressed(const sf::Keyboard::Key key) const
		{
			return sf::Keyboard::isKeyPressed(key);
		}

		bool Manager::IsKeyJustPressed(const sf::Keyboard::Key key) const
		{
			return JustPressedKey.find(key) != JustPressedKey.end();
		}

		bool Manager::IsKeyJustReleased(const sf::Keyboard::Key key) const
		{
			return JustReleasedKey.find(key) != JustReleasedKey.end();
		}

		void Manager::Clear()
		{
			JustPressedKey.clear();
			JustReleasedKey.clear();
		}

		void Manager::PressedKey(const sf::Keyboard::Key key)
		{
			JustPressedKey.insert(key);
		}

		void Manager::ReleaseKey(const sf::Keyboard::Key key)
		{
			JustReleasedKey.insert(key);
		}
	}
}
