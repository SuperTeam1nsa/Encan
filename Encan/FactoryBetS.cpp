#include "pch.h"
#include "FactoryBetS.h"
#include "ObjetGenerique.h"
#include "Art.h"
#include "Antiquite.h"
#include "Service.h"
#include <random>







/*
std::shared_ptr<ObjetGenerique> FactoryBetS::createBouS()
{
	//pas de fuite mémoire car ptr intelligents
	switch (int(3 * rand() / RAND_MAX))
	{
	case 0:
		return (createService().get())->getObjectGenerique();
		break;
	case 1:
		return (createAntiquite().get())->getObjectGenerique();
		break;
	case 2:
		return (createService().get())->getObjectGenerique();
		break;
	default: return (createService().get())->getObjectGenerique();
	}
}
*/
