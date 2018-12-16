#pragma once
#include <list>
#include "ObjetGenerique.h"
#include <iostream>
#include <thread>
#include <mutex>


class Encan
{
public:
	~Encan()
	{
		for (auto i : listeObjets)
			delete i;
		delete mtx;
	}

	static Encan* getInstance();

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
	void pushObjet(ObjetGenerique* o)
	{
		listeObjets.push_back(o);
	}
	void removeObjet(ObjetGenerique* o)
	{
		listeObjets.remove(o);
	}

	bool estVendu(ObjetGenerique* obj)
	{
		// chercher dans la liste la non-présence de l'objet (moins dégeulasse : avec un id)
		for (auto i : listeObjets)
			if (i == obj)
				return false;
		return true;
	}

	auto getListeObjet() const
	{
		return listeObjets;
	}

	void afficheInformation()
	{
		for (auto i : listeObjets)
			std::cout << i->getInfo();
	}

	bool encherir(ObjetGenerique* objet_generique, int prix, std::string nomAcheteur) const
	{
		// std::string nomVendeur contenu dans l'objet
		ObjetEncan* aux = objet_generique->getObjEnc().get();
		aux->addEnchere(new ObjetEnchere(nomAcheteur, objet_generique->getNomVendeur(),
			prix));
		if (aux->getPrixActuel() > aux->getPrixMin() && aux->getNbEnchere() > aux->getMinNbEnchere()
			&& (getTemps() - aux->getTempsIni()) > 2)
			return true;
		return false;
	}

	static float getTemps() { return temps; }

	static void passerTemps();
	std::mutex* getMutex() const
	{
		return mtx;
	}
private:
	//static int const nbObjetsMax = 10;

	std::list<ObjetGenerique*> listeObjets;
	//std::list<std::shared_ptr<Acheteurs>> listeAcheteurs;
	//std::list<std::shared_ptr<Vendeurs>> listeVendeurs;

	std::mutex* mtx;
	Encan() {
		mtx = new std::mutex();
		std::thread(&Encan::passerTemps).detach();
		//daemon.detach();
	}
	//dans un premier temps en shared_ptr mais si perte de performance importante en pointeur nu 
	//ou bien Meyer's Singleton
	static Encan* instance;
	static float temps;
};
