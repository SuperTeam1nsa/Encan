#include "pch.h"
#include "FactoryAcheteurs.h"
#include "Interet.h"
#include "Encan.h"

unsigned long FactoryAcheteurs::idAcheteur = 0;

Acheteurs* FactoryAcheteurs::createAcheteurs()
{
	Acheteurs* tab[5] = {
		new Acheteurs(NORMAL, std::bind(Interet(), ART, 500, std::placeholders::_1),
					  "Joconde " + std::to_string(idAcheteur), Encan::getInstance()),
		new Acheteurs(AGRESSIF, std::bind(Interet(), SERVICE, 1000, std::placeholders::_1),
					  "Sylvie " + std::to_string(idAcheteur), Encan::getInstance()),
		new Acheteurs(NORMAL, std::bind(Interet(), ANTIQUITE, 1500, std::placeholders::_1),
					  "Cleopatre " + std::to_string(idAcheteur), Encan::getInstance()),
		new Acheteurs(CONCENTRE, std::bind(Interet(), ANTIQUITE, 100, std::placeholders::_1),
					  "Aphrodite " + std::to_string(idAcheteur), Encan::getInstance()),
		new Acheteurs(NORMAL, std::bind(Interet(), ART, 250, std::placeholders::_1),
					  "Mona Lisa " + std::to_string(idAcheteur), Encan::getInstance())
	};
	idAcheteur++;
	return tab[static_cast<int>(5 * (rand() - 1) / RAND_MAX)];
}
