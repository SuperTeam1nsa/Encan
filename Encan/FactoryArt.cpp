#include "pch.h"
#include "FactoryArt.h"

Art* FactoryArt::createArt(std::string id)
{
	Art* tab[5] = {
		new Art(99, 100, 10, LIVRE, "La Bible", Art::getNomDuProgrammeursAimantCeTypeDObjet() + id,
							  std::make_shared<ObjetEncan>(20, 50, 3, 20)),
		new Art(80, 40, 40, SCULPTURE, "Le Penseur", Art::getNomDuProgrammeursAimantCeTypeDObjet() + id,
							  std::make_shared<ObjetEncan>(10, 20, 3, 10)),
		new Art(60, 200, 20, PEINTURE, "La Joconde", Art::getNomDuProgrammeursAimantCeTypeDObjet() + id,
							  std::make_shared<ObjetEncan>(50, 100, 4, 30)),
		new Art(50, 20, 100, SCULPTURE, "La Tour Eiffel",
							  Art::getNomDuProgrammeursAimantCeTypeDObjet() + id,
							  std::make_shared<ObjetEncan>(0, 10, 4, 5)),
		new Art(10, 50, 5, LIVRE, "Les Fleurs du Mal",
							  Art::getNomDuProgrammeursAimantCeTypeDObjet() + id,
							  std::make_shared<ObjetEncan>(10, 30, 2, 10))
	};
	return tab[int(floor(5 * rand() / RAND_MAX))];
}
