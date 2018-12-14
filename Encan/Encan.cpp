#include "pch.h"
#include "Encan.h"
int Encan::temps = 0;
Encan* Encan::instance = nullptr;

Encan* Encan::getInstance()
{
	if (instance == nullptr)
	{
		instance = new Encan();
	}
	return instance;
}
void Encan::passerTemps()
{
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
		temps++;
	}
}
