#pragma once
#include <list>
#include <iostream>
#include "EncanPourAcheteur.h"
#include "EncanPourVendeur.h"


class Encan :public EncanPourAcheteur, public EncanPourVendeur
{
public:
	~Encan()
	{
		for (auto i : listeObjets)
			delete i;
		delete mtx;
	}

	static Encan* getInstance();
	void pushObjet(ObjetGenerique* o) override
	{
		listeObjets.push_back(o);
	}
	void removeObjet(ObjetGenerique* o) override
	{
		listeObjets.remove(o);
	}

	bool estVendu(ObjetGenerique* obj) override
	{
		// chercher dans la liste la non-présence de l'objet (variante: avec un id)
		for (auto i : listeObjets)
			if (i == obj)
				return false;
		return true;
	}

	std::list<ObjetGenerique*> getListeObjet() const override
	{
		return listeObjets;
	}

	void afficheInformation()
	{
		for (auto i : listeObjets)
			std::cout << i->getInfo();
	}

	bool encherir(ObjetGenerique* objet_generique, int prix, std::string nomAcheteur) const override;


	std::mutex* getMutex() const override
	{
		return mtx;
	}
private:

	std::list<ObjetGenerique*> listeObjets;
	//std::list<std::shared_ptr<Acheteurs>> listeAcheteurs;
	//std::list<std::shared_ptr<Vendeurs>> listeVendeurs;

	std::mutex* mtx;
	Encan();
	static Encan* instance;
	static float temps;
};
