#pragma once
#include <string>
#include "ObjetEncan.h"
#include "ObjetGenerique.h"

class Art
{
private:
	Art(int renomee, int valeur, int volume, ObjetGenerique::TypeArt type, std::string description, std::shared_ptr<ObjetEncan> obj)
	{
		myCarac = { renomee, valeur, volume, type, description };
		objEnc = obj;
	};
	std::shared_ptr<ObjetEncan> objEnc;

	//Art(ObjetGenerique::TypeArt type, ObjetEncan* obj) : Art(1, 100, 10, type, "Inconnu", obj) {}
	//Art() : Art(1, 100, 10, ObjetGenerique::TypeArt::INCONNU, "Inconnu",new ObjetEncan() {}

	friend class FactoryBetS;

	ObjetGenerique::CaracArt myCarac;
public:
	~Art() { };

	int getRenomee() const { return myCarac.renomee; }
	int getValeur() const { return myCarac.valeur; }
	int getVolume() const { return myCarac.volume; }
	ObjetGenerique::TypeArt getType() const { return myCarac.type; }
	std::string getDescription() const { return myCarac.description; }
	std::shared_ptr<ObjetGenerique> getObjectGenerique() { return std::make_shared<ObjetGenerique>(myCarac, objEnc); }
	static std::unique_ptr<Art> callFactory();
	//funny fonction pour débuggage savoir le type d'objet que contient le vendeur grâce à son nom
	static std::string getNomDuProgrammeursAimantCeTypeDObjet() { return "Rémi l'artiste"; }
};
