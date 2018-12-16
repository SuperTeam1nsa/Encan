#include "pch.h"
#include "FactoryAntiquite.h"

Antiquite* Antiquite::callFactory(std::string id)
{
	return FactoryAntiquite::createAntiquite(id);
}
