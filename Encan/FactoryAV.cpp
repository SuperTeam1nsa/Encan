#include "pch.h"
#include "Interet.h"
#include "FactoryAV.h"
#include <random>
#include <functional>
#include "ObjetEncan.h"

unsigned long FactoryAV::idAcheteur = 0;
unsigned long FactoryAV::idVendeur = 0;
Acheteurs* FactoryAV::createAcheteurs()
{
	Acheteurs* tab[5] = {
		new Acheteurs(NORMAL, std::bind(Interet(), ART, 500, std::placeholders::_1), "Joconde " + std::to_string(idAcheteur),Encan::getInstance()),
		new Acheteurs(AGRESSIF, std::bind(Interet(), SERVICE, 1000, std::placeholders::_1), "Sylvie " + std::to_string(idAcheteur),Encan::getInstance()),
		new Acheteurs(NORMAL, std::bind(Interet(), ANTIQUITE, 1500, std::placeholders::_1), "Cleopatre " + std::to_string(idAcheteur),Encan::getInstance()),
		new Acheteurs(CONCENTRE, std::bind(Interet(), ANTIQUITE, 100, std::placeholders::_1), "Aphrodite " + std::to_string(idAcheteur),Encan::getInstance()),
		new Acheteurs(NORMAL, std::bind(Interet(), ART, 250, std::placeholders::_1), "Mona Lisa " + std::to_string(idAcheteur),Encan::getInstance())
	};
	idAcheteur++;
	return tab[static_cast<int>(5 * (rand() - 1) / RAND_MAX)];
}

/*

//=> use bind ! prérempli les args de la fonction ! => un template de moins ex:
/*
https://en.cppreference.com/w/cpp/utility/functional/function
struct PrintNum {
void operator()(int i) const
{
	std::cout << i << '\n';
}
};
	// store the result of a call to std::bind
	std::function<void()> f_display_31337 = std::bind(printNum(), 31337);
	f_display_31337();
	*/

	/*
	VendeursAvecAdaptateur* FactoryAV::createVendeursAvecAdaptateur() //Vendeurs<T>*
	{
		return new VendeursAvecAdaptateur(FactoryBetS::createBouS(), "No name");
	}*/
	/*int alea = round((2 * rand() / RAND_MAX) + 1);
	//choisi un nom au hasard pour notre venderu
	switch (alea)
	{
	case 1:
		return new Vendeurs<T>(T.callFactory(), "Martin");
		break;
	case 2:
		return new Vendeurs<T>(T.callFactory(), "Pierre");
		break;
	case 3:
		return new Vendeurs<T>(T.callFactory(), "Jean");
		break;
	}*/
