#include <iostream>

#include "Public/Engine.h"
#include "Private/EventHandler.h"

int main()
{
	engine::Engine engine;

	if (engine.Setup())
	{
		//engine.SaveMap();
		engine.LoadFile("");
		engine.Run();
	}

}