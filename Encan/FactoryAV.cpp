#include "pch.h"
#include "Acheteurs.h"
#include "Vendeurs.h"
#include "Interet.h"
#include "FactoryAV.h"
#include "FactoryBetS.h"
#include <random>
#include <functional>


Acheteurs* FactoryAV::createAcheteurs()
{
	Acheteurs* type[5] = {
		new Acheteurs(500, AGRESSIF, std::bind(Interet(), ART, 200, std::placeholders::_1), "Luisa"),
		new Acheteurs(1000, AGRESSIF, std::bind(Interet(), SERVICE, 200, std::placeholders::_1), "Madeleine"),
		new Acheteurs(1500, AGRESSIF, std::bind(Interet(), ART, 200, std::placeholders::_1), "Esperanza"),
		new Acheteurs(100, AGRESSIF, std::bind(Interet(), ART, 200, std::placeholders::_1), "Marie"),
		new Acheteurs(250, AGRESSIF, std::bind(Interet(), ART, 200, std::placeholders::_1), "Judith")
	};
	return type[static_cast<int>(5 * rand() - 1 / RAND_MAX)];
	/*
	std::unique_ptr<Acheteurs> type[5] = {
		 std::make_unique<Acheteurs>(500, EtatAcheteur::AGRESSIF, std::bind(Interet(),Description::ART, 200,std::placeholders::_1),"Luisa"),
		 std::make_unique<Acheteurs>(1000, EtatAcheteur::AGRESSIF, std::bind(Interet(),Description::SERVICE, 200,std::placeholders::_1),"Madeleine"),
std::make_unique<Acheteurs>(1500, EtatAcheteur::AGRESSIF, std::bind(Interet(),Description::ART, 200,std::placeholders::_1),"Esperanza"),
std::make_unique<Acheteurs>(100, EtatAcheteur::AGRESSIF, std::bind(Interet(),Description::ART, 200,std::placeholders::_1),"Marie"),
std::make_unique<Acheteurs>(250, EtatAcheteur::AGRESSIF, std::bind(Interet(),Description::ART, 200,std::placeholders::_1),"Judith"),
	};
	return std::move(type[static_cast<int>(5 * rand() - 1 / RAND_MAX)]);//(b-a)*[0-1] +a
	*/
	/*
	//ou auto a=std::unique_ptr<Acheteur>(new Acheteur()); #si on veut new ^^ make_unique condense
	//Acheteurs<Interet>* type[5];
	std::unique_ptr<Acheteurs<Interet>> type[5] = {
	std::make_unique<Acheteurs<Interet>>(500, EtatAcheteur::AGRESSIF, Interet(Description::ART, 200)),
	std::make_unique<Acheteurs<Interet>>(1000, EtatAcheteur::PATIENT),
	std::make_unique<Acheteurs<Interet>>(1500, EtatAcheteur::LENT, Interet(Description::SERVICE, 100)),
	std::make_unique<Acheteurs<Interet>>(100, EtatAcheteur::RAPIDE, Interet(Description::ART, 50)) ,
	std::make_unique<Acheteurs<Interet>>(250, EtatAcheteur::MODERE, Interet(Description::SERVICE, 300)) };
		//std::bind(Interet(),Description::ART, 200); //() car c'est pour l'operateur () on aurait aussi pu utiliser une fonction au lieu d'un foncteur ici
	//mieux ici : foncteurs av: garde son etat en memoire, chiant cst new
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

	//return new Acheteurs(500, new Interet(Description::ART, 300), EtatAcheteur::AGRESSIF);
	//return new Acheteurs(500, std::ref(*(new Interet(Description::ART, 300))), EtatAcheteur::AGRESSIF);
	//return new Acheteurs(500, (new Interet(Description::ART, 300))->operator(), EtatAcheteur::AGRESSIF);
	//return new Acheteurs<Art>(500, TypeAcheteur::AGRESSIF);
}

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

template <class T>
Vendeurs<T>* FactoryAV::createVendeurs()
{
	return new Vendeurs<T>(T::callFactory(T::getNomDuProgrammeursAimantCeTypeDObjet()));
	//ou des cast pout T, callFactory appel FactoryBetS::create...
}
