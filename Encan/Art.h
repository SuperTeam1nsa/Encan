#pragma once
#include <string>

class Art
{
public:
	enum Type
	{
		LIVRE, PEINTURE, SCULPTURE, INCONNU
	};
	~Art() {};

	int getRenomee() const { return myCarac.renomee; }
	int getValeur() const { return myCarac.valeur; }
	int getVolume() const { return myCarac.volume; }
	Type getType() const { return myCarac.type; }
	std::string getDescription() const { return myCarac.description; }
	std::shared_ptr<ObjetEncan> getAdapter() {
		return adapter;
	}

private:
	Art(int renomee, int valeur, int volume, Type type, std::string description)
	{
		myCarac = { renomee, valeur, volume, type, description };

		adapter = std::make_shared<ObjetEncan>();
	};
	std::shared_ptr<ObjetEncan> adapter;

	Art(Type type) : Art(1, 100, 10, type, "Inconnu") {}
	Art() : Art(1, 100, 10, INCONNU, "Inconnu") {}

	friend class FactoryObjetEncan;

	struct CaracArt
	{
		int renomee;
		int valeur;
		int volume;
		Type type;
		std::string description;
	};
	
	CaracArt myCarac;
};
