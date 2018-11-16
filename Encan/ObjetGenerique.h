#pragma once
#include <string>

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
	std::string getInfoArt() { return myCarac.descriptionArt == "" ? (myCarac.descriptionArt + " valeur : " + std::to_string(myCarac.valeurArt)) : ""; }
	std::string getInfoAntiquite() { return myCarac.description == "" ? (myCarac.description + " valeur : " + std::to_string(myCarac.valeur)) : ""; }
	std::string getInfoService() { return myCarac.xp == -1 ? ("tarifs : " + std::to_string(myCarac.tarif) + " xp : " + std::to_string(myCarac.xp)) : ""; }
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
};
