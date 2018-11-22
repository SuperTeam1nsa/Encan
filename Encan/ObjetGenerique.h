#pragma once
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
	//à compléter affichage des structs notamment
	std::string getInfoArt() { return  myCarac.typeObjet == Description::ART ? (myCarac.descriptionArt + " valeur : " + std::to_string(myCarac.valeurArt)) : ""; }
	std::string getInfoAntiquite() { return myCarac.typeObjet == Description::ANTIQUITE ? (myCarac.description + " valeur : " + std::to_string(myCarac.valeur)) : ""; }
	std::string getInfoService() { return myCarac.typeObjet == Description::SERVICE ? ("tarifs : " + std::to_string(myCarac.tarif) + " xp : " + std::to_string(myCarac.xp)) : ""; }
	ObjetGenerique(CaracAnt myCarac);
	ObjetGenerique(CaracArt myCarac);
	ObjetGenerique(CaracSer myCarac);
	~ObjetGenerique();

private:
	struct CaracG
	{
		Description typeObjet;

		std::string description;
		Etat etat;
		Periode periode;
		int valeur;

		int renomee;
		int valeurArt;
		int volume;
		TypeArt type;
		std::string descriptionArt;

		int frais;
		int tarif;
		TypeSer type;
		int xp;
	};

	CaracG myCarac;

public:
	CaracG getCaracG() const { return myCarac; }
};
