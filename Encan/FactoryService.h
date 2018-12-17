#pragma once
#include <string>
#include "Service.h"

class FactoryService
{
public:
	FactoryService()
	{
	}

	~FactoryService()
	{
	}

	static Service* createService(std::string id);
};
