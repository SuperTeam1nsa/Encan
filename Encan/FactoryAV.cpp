#include "FactoryAV.h"
#include <random>
#include <math.h>

Acheteurs* FactoryAV::createAcheteurs() {

	int alea = round((4 * rand() / RAND_MAX) + 1);
	switch (alea)
	{
	case 1:
		return new Acheteurs(500, TypeAcheteur::AGRESSIF);
		break;
	case 2:
		return new Acheteurs(1000, TypeAcheteur::PATIENT);
		break;
	case 3:
		return new Acheteurs(1500, TypeAcheteur::LENT);
		break;
	case 4:
		return new Acheteurs(100, TypeAcheteur::RAPIDE);
		break;
	case 5:
		return new Acheteurs(250, TypeAcheteur::MODERE);
		break;
	default:
		printf("Erreur dans la génération du nombre aléatoire");
		break;
	}
}
template<class T>
Vendeurs<T>* FactoryAV::createVendeurs()
{
	int alea = round((2 * rand() / RAND_MAX) + 1);
	switch (alea)
	{
	case 1:
		return new Vendeurs<Art>(FactoryObjetEncan::createArt());
		break;
	case 2:
		return new Vendeurs<Antiquite>(FactoryObjetEncan::createService());
		break;
	case 3:
		return new Vendeurs<Antiquite>(FactoryObjetEncan::createService());
		break;
	}
}
