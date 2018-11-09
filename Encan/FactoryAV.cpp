#include "FactoryAV.h"
#include <random>
#include <math.h>

typedef enum Description
{
	ART, ANTIQUITE, SERVICE
};
#include"Interet.h"

Acheteurs* FactoryAV::createAcheteurs() {

	int alea = round((4 * rand() / RAND_MAX) + 1);
	switch (alea)
	{
	case 1:
		return new Acheteurs(500, new Interet(Description::ART, 300), EtatAcheteur::AGRESSIF);
		//return new Acheteurs(500, std::ref(*(new Interet(Description::ART, 300))), EtatAcheteur::AGRESSIF);
		//return new Acheteurs(500, (new Interet(Description::ART, 300))->operator(), EtatAcheteur::AGRESSIF);
		//return new Acheteurs<Art>(500, TypeAcheteur::AGRESSIF);
		break;
	case 2:
		return new Acheteurs(1000, new Interet(Description::ANTIQUITE, 300), EtatAcheteur::PATIENT);
		break;
	case 3:
		return new Acheteurs(1500, new Interet(Description::SERVICE, 100), EtatAcheteur::LENT);
		break;
	case 4:
		return new Acheteurs(100, new Interet(Description::ART, 50), EtatAcheteur::RAPIDE);
		break;
	case 5:
		return new Acheteurs(250, new Interet(Description::SERVICE, 300), EtatAcheteur::MODERE);
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
