#pragma once
#include <thread>

class Temps
{
public:
	Temps() {}
	~Temps() {}
	static float getTemps() { return temps; }

	static void passerTemps()
	{
		while (true)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
			temps += 0.2f;
		}
	}
private:
	static float temps;
};
