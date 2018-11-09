#include "FactoryAV.h"
#include "pch.h"
#include <random>
#include <math.h>

enum Description
{
	ART, ANTIQUITE, SERVICE
};


auto FactoryAV::createAcheteurs() {
	Acheteurs<Interet>* type[5] = {
	new Acheteurs<Interet>(500, EtatAcheteur::AGRESSIF, Interet(Description::ART, 200)),
	new Acheteurs<Interet>(1000, EtatAcheteur::PATIENT),
	new Acheteurs<Interet>(1500, EtatAcheteur::LENT, Interet(Description::SERVICE, 100)),
	new Acheteurs<Interet>(100, EtatAcheteur::RAPIDE, Interet(Description::ART, 50)) ,
	new Acheteurs<Interet>(250, EtatAcheteur::MODERE, Interet(Description::SERVICE, 300)) };
	return type[static_cast<int>(round(4 * rand() / RAND_MAX))];//(b-a)*[0-1] +a

		//return new Acheteurs(500, new Interet(Description::ART, 300), EtatAcheteur::AGRESSIF);
		//return new Acheteurs(500, std::ref(*(new Interet(Description::ART, 300))), EtatAcheteur::AGRESSIF);
		//return new Acheteurs(500, (new Interet(Description::ART, 300))->operator(), EtatAcheteur::AGRESSIF);
		//return new Acheteurs<Art>(500, TypeAcheteur::AGRESSIF);
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
		return new Vendeurs<Antiquite>(FactoryObjetEncan::createAntiquite());
		break;
	case 3:
		return new Vendeurs<Service>(FactoryObjetEncan::createService());
		break;
	}
}
