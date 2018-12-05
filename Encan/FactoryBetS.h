#pragma once
#include "Antiquite.h"
#include "Art.h"
#include "Service.h"

class FactoryBetS
{
public:
	FactoryBetS()
	{
	}

	~FactoryBetS()
	{
	}
	//static std::shared_ptr<ObjetGenerique> createBouS();
	static Art* createArt();
	static Antiquite* createAntiquite();
	static Service* createService();
};
