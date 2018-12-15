#include "pch.h"
#include "FactoryBetS.h"

Art* Art::callFactory()
{
	return FactoryBetS::createArt();
}
