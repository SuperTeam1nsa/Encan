#pragma once
#include "Encan.h"

template <class T>
class Vendeurs
{
public:
	Vendeurs(std::shared_ptr<T> objet)
	{
		this->objet = objet;
		objet_en_enchere = false;
	}

	~Vendeurs()
	{
	};

	void mettreAuxEnchères()
	{
		while (!objet_en_enchere)
		{
			Encan::getMutex()->lock();
			mettreAuxEnchères();
			objet_en_enchere = true;
			Encan::getMutex()->unlock();
			std::this_thread::sleep_for(std::chrono::milliseconds(20));
		}
		bool vendu = false;
		while (!vendu)
		{
			//template de méthode, l'accès en lecture ne doit pas être fait en même temps qu'une modification sur la liste
			Encan::getMutex()->lock();
			vendu = Encan::getInstance()->estVendu(objet.get()->getObjectGenerique().get());
			Encan::getMutex()->unlock();
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}
		//faire sa vie de thread
	}

	void vendre()
	{
		if (!objet_en_enchere)
			mettreAuxEnchères();
		//faire sa vie de thread
		//voir mutex dans acheteurs.cpp
	}

	//std::string getNom() { return nom; }
private:
	std::shared_ptr<T> objet;
	bool objet_en_enchere;
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
