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

	int getRenomee() const { return renomee; }
	int getValeur() const { return valeur; }
	int getVolume() const { return volume; }
	Type getType() const { return type; }
	std::string getDescription() const { return description; }

private:
	Art(int renomee, int valeur, int volume, Type type, std::string description)
	{
		setRenommee(renomee);
		setValeur(valeur);
		setVolume(volume);
		setType(type);
		setDrescription(description);
	};

	Art(Type type) : Art(1, 100, 10, type, "Inconnu") {}
	Art() : Art(1, 100, 10, INCONNU, "Inconnu") {}

	void setRenommee(int renomee) { this->renomee = renomee; }
	void setValeur(int valeur) { this->valeur = valeur; }
	void setVolume(int volume) { this->volume = volume; }
	void setType(Type type) { this->type = type; }
	void setDrescription(std::string descriptiion) { this->description = descriptiion; }

	int renomee;
	int valeur;
	int volume;
	Type type;
	std::string description;
};
