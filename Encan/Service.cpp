#include "pch.h"
#include "FactoryBetS.h"
std::unique_ptr<Service> Service::callFactory() {
	return FactoryBetS::createService();
}
