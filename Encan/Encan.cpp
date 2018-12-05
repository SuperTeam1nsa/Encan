#include "pch.h"
#include "Encan.h"

void Encan::passerTemps()
{
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
		temps++;
	}
}
