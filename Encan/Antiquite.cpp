#include "pch.h"
#include "FactoryBetS.h"

Antiquite* Antiquite::callFactory(std::string id)
{
	return FactoryBetS::createAntiquite(id);
}
