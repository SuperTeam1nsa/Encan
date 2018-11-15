#pragma once
#include <string>
#include "ObjetEncan.h"
class Art
{
public:
	~Art() { delete objEnc; };

	int getRenomee() const { return myCarac.renomee; }
	int getValeur() const { return myCarac.valeur; }
	int getVolume() const { return myCarac.volume; }
	ObjetGenerique::TypeArt getType() const { return myCarac.type; }
	std::string getDescription() const { return myCarac.description; }

private:
	Art(int renomee, int valeur, int volume, ObjetGenerique::TypeArt type, std::string description, ObjetEncan* obj)
	{
		myCarac = { renomee, valeur, volume, type, description };
		objEnc = obj;
	};
	ObjetEncan* objEnc;

	Art(ObjetGenerique::TypeArt type, ObjetEncan* obj) : Art(1, 100, 10, type, "Inconnu", obj) {}
	//Art() : Art(1, 100, 10, ObjetGenerique::TypeArt::INCONNU, "Inconnu",new ObjetEncan() {}

	friend class FactoryBetS;


	ObjetGenerique::CaracArt myCarac;
};
