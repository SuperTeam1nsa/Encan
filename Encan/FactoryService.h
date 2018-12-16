#pragma once
#include "ObjetGenerique.h"
#include "Service.h"
#include <random>

class FactoryService
{
public:
	FactoryService() {}
	~FactoryService() {}

	static Service* createService(std::string id);
};

