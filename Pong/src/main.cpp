#include "Manager/GameManager.hpp"

#include <iostream>
#include <memory.h>

void main(int argc, char** argv)
{
	std::shared_ptr<Pong::GameManager> manager = std::make_shared<Pong::GameManager>();

	manager->Init();

	manager->Run();
}