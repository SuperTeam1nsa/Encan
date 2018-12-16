#include "pch.h"
#include "Encan.h"
#include "Acheteurs.h"

void Acheteurs::acheter()
{
	//std::lock_guard<std::mutex> lock(mutex);

	//=> un seul thread essaiera d'acheter à la fois
	//entrée en zone critique #utilisation de l'encan
	//on locke le mutex de l'encan #seul nous allons y avoir accès : pas d'autres acheteurs ni vendeurs #ni vendeurs
	//car ajout d'une valeur à la liste des objets pendant qu'on la lit : mal 
	//acheteurs car on va modifier le prix de l'objet selectionne avec les enchères
	//parallèlle : 2 writers
	bool presente_un_interet;
	bool achatRealise = false;
	bool enchere;
	bool pasDHumeur = false;
	int tours = 0;
	ObjetGenerique* achat = nullptr;
	printf("\n Un nouvel Acheteur est arrive: %s", nom.c_str());
	while (tours < 5 && !achatRealise) //5 enchères max
	{
		presente_un_interet = false;
		pasDHumeur = false;
		enchere = false;
		Encan::getInstance()->getMutex()->lock();
		for (auto& i : (Encan::getInstance())->getListeObjet())
		{
			presente_un_interet = interessant(*i);
			currentEtat = MEF::getInstance().getNewState(currentEtat, presente_un_interet);
			if (presente_un_interet)
			{
				//si l'acheteur a envie d'acheter
				if (currentEtat->probabiliteAchat() > rand() / RAND_MAX)
				{
					achat = i;
					enchere = true;
					achatRealise = (Encan::getInstance())->encherir(achat, achat->getObjEnc().get()->getPrixActuel() + 20, nom);
					if (achatRealise)
						break;
					//rq: getPrixActuel actualise aussi dans objEnchere ;) //# doit
				}
				else
					pasDHumeur = true;
			}
		}
		tours++;
		//sortie de la zone critique
		Encan::getInstance()->getMutex()->unlock();
		//IO en dehors de la zone critique #long
		if (enchere)
			printf(" \n \t \t \t \t %s fait une enchere sur l'objet de %s ", nom.c_str(), achat->getNomVendeur().c_str());
		if (pasDHumeur)
			printf("\n \t \t \t \t %s serait interresse mais elle n'est pas d'humeur a acheter quelque chose, etat : %s",
				nom.c_str(), currentEtat->description().c_str());
		std::this_thread::sleep_for(std::chrono::milliseconds(500));

	}
	if (achatRealise)
		printf("\n \t \t \t \t \t %s a achete l'objet de %s et s'en va !", nom.c_str(), achat->getNomVendeur().c_str());
	else
		printf("\n \t \t \t \t \t %s n'a rien achete mais s'en va !", nom.c_str());
	//l'acheteur meurt
	delete this;
}
