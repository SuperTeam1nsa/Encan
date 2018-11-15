#pragma once
#include "Antiquite.h"
#include "Art.h"
#include "Service.h"

class FactoryBetS
{
public:
	FactoryBetS() {};
	~FactoryBetS() {};

	static Antiquite* createAntiquite() { return new Antiquite(); };

	static Art* createArt() { return new Art(); };

	static Service* createService() { return new Service(); };
};
