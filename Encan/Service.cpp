#include "pch.h"
#include "FactoryBetS.h"

Service* Service::callFactory()
{
	return FactoryBetS::createService();
}
