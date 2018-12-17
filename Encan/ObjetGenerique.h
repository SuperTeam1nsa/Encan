﻿#pragma once
#include <string>
#include "ObjetEncan.h"

enum StructEtat
{
	NEUF,
	USE,
	BRISE
};

enum Periode
{
	PREHISTOIRE,
	ROMAINE,
	MOYEN_AGE,
	INCONNUE
};

struct CaracAnt
{
	std::string description;
	StructEtat etat;
	Periode periode;
	int valeur;
	std::string nomVendeur;
};

enum TypeArt
{
	LIVRE,
	PEINTURE,
	SCULPTURE,
	INCONNU
};

struct CaracArt
{
	int renomee;
	int valeur;
	int volume;
	TypeArt type;
	std::string description;
	std::string nomVendeur;
};

enum TypeSer
{
	LIVRAISON,
	VOYAGE,
	MENAGE,
	CUISINE,
	COURS,
	UNKNOWN
};

struct CaracSer
{
	int frais;
	int tarif;
	TypeSer type;
	int xp;
	std::string nomVendeur;
};

//ADAPTER
class ObjetGenerique
{
public:

	ObjetGenerique(CaracAnt myCarac, std::shared_ptr<ObjetEncan> obj);
	ObjetGenerique(CaracArt myCarac, std::shared_ptr<ObjetEncan> obj);
	ObjetGenerique(CaracSer myCarac, std::shared_ptr<ObjetEncan> obj);
	~ObjetGenerique();

private:
	struct CaracG
	{
		Description typeObjet;
		int prix;
		std::string nomVendeur;

		std::string description;
		StructEtat etat;
		Periode periode;

		int renomee;
		int volume;
		TypeArt type;
		std::string descriptionArt;

		int frais;
		TypeSer type_ser;
		int xp;
		std::shared_ptr<ObjetEncan> objEnc;
	};

	CaracG myCarac;

public:
	CaracG getCaracG() const { return myCarac; }

	std::string getNomVendeur() const
	{
		return myCarac.nomVendeur;
	}

	std::shared_ptr<ObjetEncan> getObjEnc() const { return myCarac.objEnc; }

	std::ostream& operator<<(std::ostream& o) const
	{
		return o << getInfo(true);
	}
	std::string getInfo() const
	{
		return getInfoArt() + getInfoAntiquite() + getInfoService();
	}
	std::string getInfo(bool avecSautDeLigne) const
	{
		if (avecSautDeLigne)
			return "\n " + getInfoArt() + getInfoAntiquite() + getInfoService();
		return getInfo();
	}

	std::string getInfoArt() const
	{
		return myCarac.typeObjet == ART ? ("Art : " + myCarac.descriptionArt + " valeur : " + std::to_string(myCarac.prix)) : "";
	}

	std::string getInfoAntiquite() const
	{
		return myCarac.typeObjet == ANTIQUITE
			? ("Antiquite : " + myCarac.description + " valeur : " + std::to_string(myCarac.prix))
			: "";
	}

	std::string getInfoService() const
	{
		return myCarac.typeObjet == SERVICE
			? ("Service : tarifs : " + std::to_string(myCarac.prix) + " xp : " + std::to_string(myCarac.xp))
			: "";
	}
};
