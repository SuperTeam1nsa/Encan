#pragma once
#include "EncanPourVendeur.h"
#include "Temps.h"
template <class T>
class Vendeurs
{
public:
	explicit Vendeurs(T* objet, std::string nom, EncanPourVendeur* enc)
	{
		this->objet = objet;
		objetEnEnchere = false;
		this->nom = nom;
		encanV = enc;
	}

	~Vendeurs()
	{
	}

	void mettreAuxEncheres()
	{
		while (!objetEnEnchere)
		{
			encanV->getMutex()->lock();
			encanV->pushObjet(objet->getObjectGenerique());
			objetEnEnchere = true;
			encanV->getMutex()->unlock();
			std::this_thread::sleep_for(std::chrono::milliseconds(20));
		}
		bool vendu = false;
		float temps_ini = Temps::getTemps();
		while (!vendu && (Temps::getTemps() - temps_ini) < 7)
		{

			printf("\n \t Le vendeur %s attend la vente", objet->getObjectGenerique()->getNomVendeur().c_str());
			//l'accès en lecture ne doit pas être fait en même temps qu'une modification sur la liste
			encanV->getMutex()->lock();
			vendu = encanV->estVendu(objet->getObjectGenerique());
			encanV->getMutex()->unlock();
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		}

		printf("\n \t \t Le vendeur %s s'en va !", objet->getObjectGenerique()->getNomVendeur().c_str());
		bool ok = false;
		while (!ok)
		{
			encanV->getMutex()->lock();
			encanV->removeObjet(objet->getObjectGenerique());
			delete objet;
			ok = true;
			encanV->getMutex()->unlock();
		}
		//le vendeur se suicide
		delete this;

	}

	void vendre()
	{
		printf("\n Nouveau vendeur: %s ", objet->getObjectGenerique()->getNomVendeur().c_str());
		mettreAuxEncheres();

	}

	std::string getNom() const { return nom; }
private:
	T* objet;
	bool objetEnEnchere;
	std::string nom;
	EncanPourVendeur* encanV;
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
