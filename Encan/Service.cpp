#include "pch.h"
#include "FactoryService.h"

Service* Service::callFactory(std::string id)
{
	return FactoryService::createService(id);
}
