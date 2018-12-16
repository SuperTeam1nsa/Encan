#include "pch.h"
#include "FactoryService.h"

Service* FactoryService::createService(std::string id)
{
	Service* tab[5] = {
		new Service(10, 50, LIVRAISON, 100, Service::getNomDuProgrammeursAimantCeTypeDObjet() + id,
								  std::make_shared<ObjetEncan>(20, 30, 1, 10)),
		new Service(20, 100, VOYAGE, 80, Service::getNomDuProgrammeursAimantCeTypeDObjet() + id,
								  std::make_shared<ObjetEncan>(50, 80, 3, 20)),
		new Service(30, 80, MENAGE, 60, Service::getNomDuProgrammeursAimantCeTypeDObjet() + id,
								  std::make_shared<ObjetEncan>(30, 50, 2, 15)),
		new Service(40, 40, CUISINE, 40, Service::getNomDuProgrammeursAimantCeTypeDObjet() + id,
								  std::make_shared<ObjetEncan>(30, 50, 2, 10)),
		new Service(50, 100, COURS, 20, Service::getNomDuProgrammeursAimantCeTypeDObjet() + id,
								  std::make_shared<ObjetEncan>(50, 80, 3, 20))
	};
	return tab[int(floor(5 * rand() / RAND_MAX))];
}
