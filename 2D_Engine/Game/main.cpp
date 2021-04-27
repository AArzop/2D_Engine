#include <iostream>

#include "Public/Engine.h"

int main()
{
	engine::Engine engine;

	if (engine.Setup())
	{
		engine.LoadFile("E:/Map1.txt");
		engine.Run();
		//engine.SaveMap("E:/Map2.txt");
	}

}