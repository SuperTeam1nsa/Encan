#pragma once
#include "Encan.h"

template <class T>
class Vendeurs
{
public:
	explicit Vendeurs(T* objet, std::string nom)
	{
		this->objet = objet;
		objetEnEnchere = false;
		this->nom = nom;
	}

	~Vendeurs()
	{
	};

	void mettreAuxEncheres()
	{
		while (!objetEnEnchere)
		{
			Encan::getInstance()->getMutex()->lock();
			Encan::getInstance()->pushObjet(objet->getObjectGenerique());
			objetEnEnchere = true;
			Encan::getInstance()->getMutex()->unlock();
			std::this_thread::sleep_for(std::chrono::milliseconds(20));
		}
		bool vendu = false;
		while (!vendu)
		{
			printf("attend la vente \n");
			//template de méthode, l'accès en lecture ne doit pas être fait en même temps qu'une modification sur la liste
			Encan::getInstance()->getMutex()->lock();
			vendu = Encan::getInstance()->estVendu(objet->getObjectGenerique());
			Encan::getInstance()->getMutex()->unlock();
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}
	}

	void vendre()
	{
		if (!objetEnEnchere)
		{
			printf("LLLLLLLLLLLLAAAAAAAAAAAAA \n");
			mettreAuxEncheres();
		}
		//faire sa vie de thread
		//voir mutex dans acheteurs.cpp

	}

	std::string getNom() const { return nom; }
private:
	T* objet;
	bool objetEnEnchere;
	std::string nom;
};


/*
class VendeursAvecAdaptateur
{
public:
	VendeursAvecAdaptateur(std::shared_ptr<ObjetGenerique> objet, std::string const& nom_vendeur) {
		this->objet = objet; nom = nom_vendeur;
		objet_en_enchere = false;
	}
	~VendeursAvecAdaptateur() {};
	void mettreAuxEnchères()
	{
		//T.getPrix(); = NON T est un type pas une instance ! //etc

	}
	void vendre() {
		while (!objet_en_enchere)
		{
			Encan::mutex.lock();
			mettreAuxEnchères();
			objet_en_enchere = true;
			Encan::mutex.unlock();
			std::this_thread::sleep_for(std::chrono::milliseconds(20));

		}
		bool vendu = false;
		while (!vendu)
		{
			//template de méthode, l'accès en lecture ne doit pas être fait en même temps qu'une modification sur la liste
			Encan::mutex.lock();
			vendu = Encan::estVendu(objet);
			Encan::mutex.unlock();
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}
		//faire sa vie de thread
	}
	std::string getNom() const { return nom; }
private:
	std::shared_ptr<ObjetGenerique> objet;
	std::string nom;
	bool objet_en_enchere;

}; */
