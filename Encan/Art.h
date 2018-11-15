#pragma once
#include <string>

class Art
{
public:
	~Art() {};

	int getRenomee() const { return myCarac.renomee; }
	int getValeur() const { return myCarac.valeur; }
	int getVolume() const { return myCarac.volume; }
	ObjetGenerique::TypeArt getType() const { return myCarac.type; }
	std::string getDescription() const { return myCarac.description; }
	std::shared_ptr<ObjetEncan> getAdapter() {
		return adapter;
	}

private:
	Art(int renomee, int valeur, int volume, ObjetGenerique::TypeArt type, std::string description)
	{
		myCarac = { renomee, valeur, volume, type, description };

		adapter = std::make_shared<ObjetEncan>();
	};
	std::shared_ptr<ObjetEncan> adapter;

	Art(ObjetGenerique::TypeArt type) : Art(1, 100, 10, type, "Inconnu") {}
	Art() : Art(1, 100, 10, ObjetGenerique::TypeArt::INCONNU, "Inconnu") {}

	friend class FactoryObjetEncan;

	
	ObjetGenerique::CaracArt myCarac;
};
