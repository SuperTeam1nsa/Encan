#pragma once
#include <string>

class ObjetGenerique
{
public:
	enum Etat
	{
		NEUF, USE, BRISE
	};
	enum Periode
	{
		PREHISTOIRE, ANTIQUITE, MOYEN_AGE, TEMPS_MODERNES, EPOQUE_CONTEMPORAINE, INCONNUE
	};
	struct CaracAnt
	{
		std::string description;
		Etat etat;
		Periode periode;
		int valeur;
	};

	enum TypeArt
	{
		LIVRE, PEINTURE, SCULPTURE, INCONNU
	};
	struct CaracArt
	{
		int renomee;
		int valeur;
		int volume;
		TypeArt type;
		std::string description;
	};

	enum TypeSer
	{
		LIVRAISON, VOYAGE, MENAGE, CUISINE, COURS, INCONNU
	};
	struct CaracSer
	{
		int frais;
		int tarif;
		TypeSer type;
		int xp;
	};

	ObjetGenerique(CaracAnt myCarac);
	ObjetGenerique(CaracArt myCarac);
	ObjetGenerique(CaracSer myCarac);
	~ObjetGenerique();

private:
	struct CaracG
	{
		std::string description;
		Etat etat;
		Periode periode;
		int valeur;

		int renomee;
		int valeur;
		int volume;
		TypeArt type;
		std::string description;

		int frais;
		int tarif;
		TypeSer type;
		int xp;
	};

	CaracG myCarac;
};

