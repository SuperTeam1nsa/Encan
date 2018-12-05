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
	bool va_acheter;
	int time = 0;
	ObjetGenerique* achat = nullptr;

	while (time < 5000) //10 tours
	{
		presente_un_interet = false;
		va_acheter = false;
		Encan::getMutex()->lock();
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
					va_acheter = true;
					break;
				}
			}
		}
		if (va_acheter)
		{
			bool a = (Encan::getInstance())->encherir(achat, achat->getObjEnc().get()->getPrixActuel(), nom);
			//rq: getPrixActuel actualise aussi dans objEnchere ;) //# doit 
			//...
		}
		//sortie de la zone critique
		Encan::getMutex()->unlock();
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		time += 500;
	}
	//l'acheteur meurt
	delete this;
}
