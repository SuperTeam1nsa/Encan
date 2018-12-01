#include "pch.h"
#include "Encan.h"
#include "Acheteurs.h"
#include <mutex>
std::mutex mutex;
void Acheteurs::acheter() {
	//std::lock_guard<std::mutex> lock(mutex);


	//entrée en zone critique #utilisation de l'encan
	mutex.lock();
	bool presente_un_interet = false;
	bool va_acheter = false;
	ObjetGenerique* achat;
	for (auto& i : (Encan::getInstance()).get()->getListeObjet())
	{
		presente_un_interet = interessant(*i);
		currentEtat = MEF::getInstance().getNewState(currentEtat, presente_un_interet);
		if (presente_un_interet)
		{
			//si l'acheteur a envie d'acheter
			if (currentEtat->probabilite_achat() > rand() / RAND_MAX)
			{
				achat = i.get();
				va_acheter = true;
				break;
			}
		}
	}
	if (va_acheter)
	{
		(Encan::getInstance()).get().encherir();
	}

	//sortie de la zone critique
	mutex.unlock();
}
