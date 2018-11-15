#pragma once
#include "ObjetGenerique.h"
#include <list>
#include "Acheteurs.h"
#include "Vendeurs.h"
#include "Art.h"
#include "Antiquite.h"
#include "Service.h"
#include "FactoryAV.h"
class Encan
{
public:
	~Encan() {}
	std::shared_ptr<Encan> getInstance()
	{
		if (instance == nullptr)
		{
			instance = std::make_shared<Encan>();
		}
		return instance;
	}
	void start() {

		FactoryAV::createVendeurs<Art>();
	}
	void pushObjet(std::shared_ptr<ObjetGenerique> o)
	{
		listeObjets.push_back(o);
	}
	auto getListeObjet(std::shared_ptr <ObjetGenerique> o)
	{
		return listeObjets;
	}


private:
	//static int const nbObjetsMax = 10;
	std::list<std::shared_ptr<ObjetGenerique>> listeObjets;
	std::list<std::shared_ptr<Acheteurs>> listeAcheteurs;
	std::list<std::shared_ptr<Vendeurs<Art>>> listeVendeursArt;
	std::list<std::shared_ptr<Vendeurs<Antiquite>>> listeVendeursAntiquite;
	std::list<std::shared_ptr<Vendeurs<Service>>> listeVendeursService;



	Encan() {}
	std::shared_ptr <Encan> instance;
};
