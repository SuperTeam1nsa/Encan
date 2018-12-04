﻿#pragma once
#include <string>
#include "Encan.h"

//ADAPTER
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

	// juste en exemple
	std::string getInfo() {
		return getInfoArt() + getInfoAntiquite() + getInfoService();
	}
	std::string getInfoArt() { return  myCarac.typeObjet == Description::ART ? (myCarac.descriptionArt + " valeur : " + std::to_string(myCarac.prix)) : ""; }
	std::string getInfoAntiquite() { return myCarac.typeObjet == Description::ANTIQUITE ? (myCarac.description + " valeur : " + std::to_string(myCarac.prix)) : ""; }
	std::string getInfoService() { return myCarac.typeObjet == Description::SERVICE ? ("tarifs : " + std::to_string(myCarac.prix) + " xp : " + std::to_string(myCarac.xp)) : ""; }
	ObjetGenerique(CaracAnt myCarac, std::shared_ptr<ObjetEncan> obj);
	ObjetGenerique(CaracArt myCarac, std::shared_ptr<ObjetEncan> obj);
	ObjetGenerique(CaracSer myCarac, std::shared_ptr<ObjetEncan> obj);
	~ObjetGenerique();

private:
	struct CaracG
	{
		Description typeObjet;
		int prix;

		std::string description;
		Etat etat;
		Periode periode;

		int renomee;
		int volume;
		TypeArt type;
		std::string descriptionArt;

		int frais;
		TypeSer type;
		int xp;
		std::shared_ptr<ObjetEncan> objEnc;
	};

	CaracG myCarac;

public:
	CaracG getCaracG() const { return myCarac; }
	std::shared_ptr<ObjetEncan> getObjEnc() const { return myCarac.objEnc; }
};
