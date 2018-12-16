#include "pch.h"
#include "FactoryBetS.h"

Service* Service::callFactory(std::string id)
{
	return FactoryBetS::createService(id);
}
