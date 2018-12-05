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
	}

	static Encan* getInstance()
	{
		if (instance == nullptr)
		{
			instance = new Encan();
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
	void pushObjet(ObjetGenerique* o)
	{
		listeObjets.push_back(o);
	}

	bool estVendu(ObjetGenerique* obj)
	{
		//TODO: chercher dans la liste la présence de l'objet (moins dégeulasse : avec un id)
		for (auto i : listeObjets)
			if (i == obj)
				return true;
		return false;
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
		//, std::string nomVendeur contenu dans l'objet
		objet_generique->getObjEnc()->addEnchere(new ObjetEnchere(nomAcheteur, objet_generique->getNomVendeur(),
			prix));
		//obj->getCaracG().objEnc.get()->;
		return true;
	}

	static int getTemps() { return temps; }

	static void passerTemps();
	static std::mutex* getMutex()
	{
		if (mtx == nullptr)
			mtx = new std::mutex();
		return mtx;
	}
private:
	//static int const nbObjetsMax = 10;

	std::list<ObjetGenerique*> listeObjets;
	//std::list<std::shared_ptr<Acheteurs>> listeAcheteurs;
	//std::list<std::shared_ptr<Vendeurs>> listeVendeurs;

	static std::mutex* mtx;
	Encan() {
		temps = 0;
		std::thread daemon(passerTemps);
		daemon.detach();
	}
	//dans un premier temps en shared_ptr mais si perte de performance importante en pointeur nu 
	//ou bien Meyer's Singleton
	static Encan* instance;

	static int temps;
};
