#include <iostream>

#include "Engine.h"

int main()
{
	engine::Engine engine;

	if (engine.Setup())
	{
		engine.Run();
	}

}