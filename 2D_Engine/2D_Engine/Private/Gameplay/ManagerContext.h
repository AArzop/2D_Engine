#pragma once

namespace engine
{
	namespace graphics
	{
		class Manager;
	}

	namespace gameplay
	{
		struct ManagerContext
		{
			::engine::graphics::Manager& GraphicsManager;
		};
	}
}