#pragma once
#include "Art.h"
#include "ObjetGenerique.h"
#include <random>

class FactoryArt
{
public:
	FactoryArt() {}
	~FactoryArt() {}

	static Art* createArt(std::string id);
};

