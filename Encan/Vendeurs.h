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
	}

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
		float temps_ini = Encan::getTemps();
		while (!vendu && (Encan::getTemps() - temps_ini) < 2)
		{
			//printf("\n Temps ini: %f et temps actuel : %f ", temps_ini, Encan::getTemps());
			printf("\t Le vendeur %s attend la vente \n", objet->getObjectGenerique()->getNomVendeur().c_str());
			//template de méthode, l'accès en lecture ne doit pas être fait en même temps qu'une modification sur la liste
			Encan::getInstance()->getMutex()->lock();
			vendu = Encan::getInstance()->estVendu(objet->getObjectGenerique());
			Encan::getInstance()->getMutex()->unlock();
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		}
		//printf("\n \n OUT ! \n ");
		printf("\t \t Le vendeur %s s'en va ! :( \n", objet->getObjectGenerique()->getNomVendeur().c_str());
		bool ok = false;
		while (!ok)
		{
			Encan::getInstance()->getMutex()->lock();
			//si l'objet n'a pas été vendu
			if (!Encan::getInstance()->estVendu(objet->getObjectGenerique()))
			{
				Encan::getInstance()->removeObjet(objet->getObjectGenerique());
				delete objet;
			}
			ok = true;
			Encan::getInstance()->getMutex()->unlock();
		}
		//le vendeur se suicide
		delete this;

	}

	void vendre()
	{
		printf("Nouveau vendeur: %s \n", objet->getObjectGenerique()->getNomVendeur().c_str());
		mettreAuxEncheres();

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
