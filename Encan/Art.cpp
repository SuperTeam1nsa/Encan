#include "pch.h"
#include "FactoryBetS.h"

std::unique_ptr<Art> Art::callFactory()
{
	return FactoryBetS::createArt();
}
