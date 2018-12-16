#pragma once
#include "ObjetGenerique.h"
#include "Antiquite.h"
#include <random>

class FactoryAntiquite
{
public:
	FactoryAntiquite() {}
	~FactoryAntiquite() {}

	static Antiquite* createAntiquite(std::string id);
};


