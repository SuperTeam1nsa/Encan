#include "pch.h"
#include "FactoryArt.h"

Art* Art::callFactory(std::string id)
{
	return FactoryArt::createArt(id);
}
