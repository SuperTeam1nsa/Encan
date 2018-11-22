#pragma once
#include "ObjetGenerique.h"
#include <list>
#include "Art.h"
#include "Antiquite.h"
#include "Service.h"
#include "Affichage_Info.h"

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
		affArt(listeObjets);
		affAntiquite(listeObjets);
		affService(listeObjets);
	}


private:
	//static int const nbObjetsMax = 10;
	std::list<std::shared_ptr<ObjetGenerique>> listeObjets;
	//std::list<std::shared_ptr<Acheteurs>> listeAcheteurs;
	//std::list<std::shared_ptr<Vendeurs>> listeVendeurs;
	Affichage_Info<Art> affArt;
	Affichage_Info<Antiquite> affAntiquite;
	Affichage_Info<Service> affService;


	Encan() {}
	static std::shared_ptr <Encan> instance;
};
