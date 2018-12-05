#include "pch.h"
#include "FactoryBetS.h"

std::unique_ptr<Antiquite> Antiquite::callFactory()
{
	return FactoryBetS::createAntiquite();
}
