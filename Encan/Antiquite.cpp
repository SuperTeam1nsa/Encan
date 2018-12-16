#include "pch.h"
#include "FactoryBien.h"

Antiquite* Antiquite::callFactory(std::string id)
{
	return FactoryBien::createAntiquite(id);
}
