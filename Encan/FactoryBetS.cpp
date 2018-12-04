﻿#include "pch.h"
#include "FactoryBetS.h"
#include "ObjetGenerique.h"
#include "Art.h"
#include "Antiquite.h"
#include "Service.h"
#include <random>

auto FactoryBetS::createArt()
{
	std::unique_ptr<Art> type[5] = {
		std::make_unique<Art>(99, 100, 10, ObjetGenerique::TypeArt::LIVRE, "La Bible", std::make_shared<ObjetEncan>(20, 50, 3, 20)),
		std::make_unique<Art>(80, 40, 40, ObjetGenerique::TypeArt::SCULPTURE, "Le Penseur", std::make_shared<ObjetEncan>(10, 20, 1, 10)),
		std::make_unique<Art>(60, 200, 20, ObjetGenerique::TypeArt::PEINTURE, "La Joconde", std::make_shared<ObjetEncan>(50, 100, 5, 30)),
		std::make_unique<Art>(50, 20, 100, ObjetGenerique::TypeArt::SCULPTURE, "La Tour Eiffel", std::make_shared<ObjetEncan>(0, 10, 1, 5)),
		std::make_unique<Art>(10, 50, 5, ObjetGenerique::TypeArt::LIVRE, "Les Fleurs du Mal", std::make_shared<ObjetEncan>(10, 30, 2, 10))
	};
	return std::move(type[int(floor(5 * rand() / RAND_MAX))]);
}

auto FactoryBetS::createAntiquite() {
	std::unique_ptr<Antiquite> type[5] = {
		std::make_unique<Antiquite>("Peinture Rupestre", ObjetGenerique::Etat::NEUF, ObjetGenerique::Periode::PREHISTOIRE, 20, std::make_shared<ObjetEncan>(0, 10, 1, 5)),
		std::make_unique<Antiquite>("Vase decoratif", ObjetGenerique::Etat::BRISE, ObjetGenerique::Periode::ANTIQUITE, 30, std::make_shared<ObjetEncan>(10, 20, 1, 10)),
		std::make_unique<Antiquite>("Armure de chevalier", ObjetGenerique::Etat::USE, ObjetGenerique::Periode::MOYEN_AGE, 100, std::make_shared<ObjetEncan>(20, 50, 3, 20)),
		std::make_unique<Antiquite>("Guillotine", ObjetGenerique::Etat::USE, ObjetGenerique::Periode::TEMPS_MODERNES, 80, std::make_shared<ObjetEncan>(20, 40, 2, 10)),
		std::make_unique<Antiquite>("Sabre de cavalerie", ObjetGenerique::Etat::NEUF, ObjetGenerique::Periode::EPOQUE_CONTEMPORAINE, 50, std::make_shared<ObjetEncan>(20, 30, 1, 10))
	};
	return std::move(type[int(floor(5 * rand() / RAND_MAX))]);
}

auto FactoryBetS::createService() {
	std::unique_ptr<Service> type[5] = {
		std::make_unique<Service>(10, 50, ObjetGenerique::TypeSer::LIVRAISON, 100, std::make_shared<ObjetEncan>(20, 30, 1, 10)),
		std::make_unique<Service>(20, 100, ObjetGenerique::TypeSer::VOYAGE, 80, std::make_shared<ObjetEncan>(50, 80, 3, 20)),
		std::make_unique<Service>(30, 80, ObjetGenerique::TypeSer::MENAGE, 60, std::make_shared<ObjetEncan>(30, 50, 2, 15)),
		std::make_unique<Service>(40, 40, ObjetGenerique::TypeSer::CUISINE, 40, std::make_shared<ObjetEncan>(30, 50, 2, 10)),
		std::make_unique<Service>(50, 100, ObjetGenerique::TypeSer::COURS, 20, std::make_shared<ObjetEncan>(50, 80, 3, 20))
	};
	return std::move(type[int(floor(5 * rand() / RAND_MAX))]);
}

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
	default: return (createService().get())->getObjectGenerique();;
	}
}
