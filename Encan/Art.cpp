#include "pch.h"
#include "FactoryBetS.h"

Art* Art::callFactory(std::string id)
{
	return FactoryBetS::createArt(id);
}
