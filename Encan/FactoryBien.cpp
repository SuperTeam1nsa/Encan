#include "pch.h"
#include "FactoryBien.h"

Antiquite* FactoryBien::createAntiquite(std::string id)
{
	Antiquite* tab[5] = {
		new Antiquite("Peinture Rupestre", NEUF, PREHISTOIRE, 20,
									Antiquite::getNomDuProgrammeursAimantCeTypeDObjet() + id,
									std::make_shared<ObjetEncan>(0, 10, 1, 5)),
		new Antiquite("Vase decoratif", BRISE, ROMAINE, 30,
									Antiquite::getNomDuProgrammeursAimantCeTypeDObjet() + id,
									std::make_shared<ObjetEncan>(10, 20, 1, 10)),
		new Antiquite("Armure de chevalier", USE, MOYEN_AGE, 100,
									Antiquite::getNomDuProgrammeursAimantCeTypeDObjet() + id,
									std::make_shared<ObjetEncan>(20, 50, 3, 20)),
		new Antiquite("Guillotine", USE, PREHISTOIRE, 80,
									Antiquite::getNomDuProgrammeursAimantCeTypeDObjet() + id,
									std::make_shared<ObjetEncan>(20, 40, 2, 10)),
		new Antiquite("Sabre de cavalerie", NEUF, ROMAINE, 50,
									Antiquite::getNomDuProgrammeursAimantCeTypeDObjet() + id,
									std::make_shared<ObjetEncan>(20, 30, 1, 10))
	};
	return tab[int(floor(5 * rand() / RAND_MAX))];
}
