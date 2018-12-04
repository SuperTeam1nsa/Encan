#pragma once
//#include "ObjetGenerique.h"
#include <list>
#include "Art.h"
#include "Antiquite.h"
#include "Service.h"
#include "Affichage_Info.h"
#include <thread>
#include <chrono>
#include <mutex>


class Encan
{
public:
	~Encan() {}
	static std::shared_ptr<Encan> getInstance()
	{
		if (instance == nullptr)
		{
			instance = std::make_shared<Encan>();
		}
		return instance;
	}
	/*void start() {
		Affichage_Info<Art> affArt;
		Affichage_Info<Antiquite> affAntiquite;
		Affichage_Info<Service> affService;
		int const NB_VENDEURS_INI = 5;
		int const NB_ACHETEURS_INI = 5;
		for (int i = 0; i < NB_VENDEURS_INI; i++)
			listeVendeurs.push_back(FactoryAV::createVendeurs());
		for (int i = 0; i < NB_ACHETEURS_INI; i++)
			listeAcheteurs.push_back(FactoryAV::createAcheteurs());

		affArt(listeObjets);
		affAntiquite(listeObjets);
		affService(listeObjets);
	}*/
	void pushObjet(std::shared_ptr<ObjetGenerique> o)
	{
		listeObjets.push_back(o);
	}
	auto getListeObjet()
	{
		return listeObjets;
	}
	void affiche_information() {
		for (auto i : listeObjets)
			std::cout << i.get()->getInfo();
	}
	bool encherir(ObjetGenerique* obj, int prix, std::string nomAcheteur)
	{
		//, std::string nomVendeur contenu dans l'objet
		obj->getObjEnc()->addEnchere(obj, nomAcheteur);
		//obj->getCaracG().objEnc.get()->;
		return true;
	}

	static int getTemps() { return temps; }

	static void passerTemps();
	static std::mutex mutex;
private:
	//static int const nbObjetsMax = 10;

	std::list<std::shared_ptr<ObjetGenerique>> listeObjets;
	//std::list<std::shared_ptr<Acheteurs>> listeAcheteurs;
	//std::list<std::shared_ptr<Vendeurs>> listeVendeurs;


	Encan();
	//dans un premier temps en shared_ptr mais si perte de performance importante en pointeur nu 
	//ou bien Meyer's Singleton
	static std::shared_ptr <Encan> instance;

	static int temps;
};
