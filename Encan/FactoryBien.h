#pragma once
#include <string>
#include "Antiquite.h"

class FactoryBien
{
public:
	FactoryBien()
	{
	}

	~FactoryBien()
	{
	}

	static Antiquite* createAntiquite(std::string id);
};
