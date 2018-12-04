#pragma once
#include "Antiquite.h"
#include "Art.h"
#include "Service.h"

class FactoryBetS
{
public:
	FactoryBetS() {}
	~FactoryBetS() {}
	static std::shared_ptr<ObjetGenerique> createBouS();
	static std::unique_ptr<Art> createArt();
	static std::unique_ptr<Antiquite> createAntiquite();
	static std::unique_ptr<Service> createService();
};
