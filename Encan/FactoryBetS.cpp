#include "pch.h"
#include "FactoryBetS.h"
#include "ObjetGenerique.h"
#include "Art.h"
#include "Antiquite.h"
#include "Service.h"
#include <random>

Art* FactoryBetS::createArt()
{
	Art* type[5] = {
		new Art(99, 100, 10, LIVRE, "La Bible", Art::getNomDuProgrammeursAimantCeTypeDObjet() + " 1",
							  std::make_shared<ObjetEncan>(20, 50, 3, 20)),
		new Art(80, 40, 40, SCULPTURE, "Le Penseur", Art::getNomDuProgrammeursAimantCeTypeDObjet() + " 2",
							  std::make_shared<ObjetEncan>(10, 20, 1, 10)),
		new Art(60, 200, 20, PEINTURE, "La Joconde", Art::getNomDuProgrammeursAimantCeTypeDObjet() + " 3",
							  std::make_shared<ObjetEncan>(50, 100, 5, 30)),
		new Art(50, 20, 100, SCULPTURE, "La Tour Eiffel",
							  Art::getNomDuProgrammeursAimantCeTypeDObjet() + " 4",
							  std::make_shared<ObjetEncan>(0, 10, 1, 5)),
		new Art(10, 50, 5, LIVRE, "Les Fleurs du Mal",
							  Art::getNomDuProgrammeursAimantCeTypeDObjet() + " 5",
							  std::make_shared<ObjetEncan>(10, 30, 2, 10))
	};
	return std::move(type[int(floor(5 * rand() / RAND_MAX))]);
}

Antiquite* FactoryBetS::createAntiquite()
{
	Antiquite* type[5] = {
		new Antiquite("Peinture Rupestre", NEUF, PREHISTOIRE, 20,
									Antiquite::getNomDuProgrammeursAimantCeTypeDObjet() + " 1",
									std::make_shared<ObjetEncan>(0, 10, 1, 5)),
		new Antiquite("Vase decoratif", BRISE, ROMAINE, 30,
									Antiquite::getNomDuProgrammeursAimantCeTypeDObjet() + " 2",
									std::make_shared<ObjetEncan>(10, 20, 1, 10)),
		new Antiquite("Armure de chevalier", USE, MOYEN_AGE, 100,
									Antiquite::getNomDuProgrammeursAimantCeTypeDObjet() + " 3",
									std::make_shared<ObjetEncan>(20, 50, 3, 20)),
		new Antiquite("Guillotine", USE, TEMPS_MODERNES, 80,
									Antiquite::getNomDuProgrammeursAimantCeTypeDObjet() + " 4",
									std::make_shared<ObjetEncan>(20, 40, 2, 10)),
		new Antiquite("Sabre de cavalerie", NEUF, EPOQUE_CONTEMPORAINE, 50,
									Antiquite::getNomDuProgrammeursAimantCeTypeDObjet() + " 5",
									std::make_shared<ObjetEncan>(20, 30, 1, 10))
	};
	return std::move(type[int(floor(5 * rand() / RAND_MAX))]);
}

Service* FactoryBetS::createService()
{
	Service* type[5] = {
		new Service(10, 50, LIVRAISON, 100, Service::getNomDuProgrammeursAimantCeTypeDObjet() + " 1",
								  std::make_shared<ObjetEncan>(20, 30, 1, 10)),
		new Service(20, 100, VOYAGE, 80, Service::getNomDuProgrammeursAimantCeTypeDObjet() + " 2",
								  std::make_shared<ObjetEncan>(50, 80, 3, 20)),
		new Service(30, 80, MENAGE, 60, Service::getNomDuProgrammeursAimantCeTypeDObjet() + " 3",
								  std::make_shared<ObjetEncan>(30, 50, 2, 15)),
		new Service(40, 40, CUISINE, 40, Service::getNomDuProgrammeursAimantCeTypeDObjet() + " 4",
								  std::make_shared<ObjetEncan>(30, 50, 2, 10)),
		new Service(50, 100, COURS, 20, Service::getNomDuProgrammeursAimantCeTypeDObjet() + " 5",
								  std::make_shared<ObjetEncan>(50, 80, 3, 20))
	};
	return std::move(type[int(floor(5 * rand() / RAND_MAX))]);
}

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
