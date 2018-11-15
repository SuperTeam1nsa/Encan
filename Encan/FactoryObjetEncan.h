#pragma once
#include "Antiquite.h"
#include "Art.h"
#include "Service.h"

class FactoryObjetEncan
{
public:
	FactoryObjetEncan() {};
	~FactoryObjetEncan() {};

	static Antiquite* createAntiquite() { return new Antiquite(); };

	static Art* createArt() { return new Art(); };

	static Service* createService() { return new Service(); };
};
