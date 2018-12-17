#pragma once
#include <string>
#include "Art.h"

class FactoryArt
{
public:
	FactoryArt()
	{
	}

	~FactoryArt()
	{
	}

	static Art* createArt(std::string id);
};
