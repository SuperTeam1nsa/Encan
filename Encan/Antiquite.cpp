#include "pch.h"
#include "FactoryBetS.h"

Antiquite* Antiquite::callFactory()
{
	return FactoryBetS::createAntiquite();
}
