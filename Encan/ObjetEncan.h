#pragma once
#include <list>
#include "ObjetEnchere.h"

enum Description
{
	ART,
	ANTIQUITE,
	SERVICE
};

//contenu dans les objets
class ObjetEncan
{
public:
	ObjetEncan(int prixIni, int prixMin, int minNbEnchere, int maxNbEnchere);

	void addEnchere(ObjetEnchere* obj)
	{
		prixActuel = obj->getPrix();
		encheres.push_back(obj);
	}

	// T* obj) { objet = obj; };
	~ObjetEncan()
	{
		for (auto i : encheres)
			delete i;
		encheres.clear();
	}

	int getPrixActuel() const { return prixActuel; }
	float getTempsIni() const { return tempsInitial; }
	int getMinNbEnchere() const { return minNbEnchere; }
	int getPrixMin() const { return prixMin; }
	int getNbEnchere() const { return encheres.size(); }
	//T* getObjet() { return objet; }
	//:
	//T* objet; //art, antiquite, services etc
private:
	int prixIni;
	int prixMin;
	int prixActuel;
	int minNbEnchere;
	int maxNbEnchere;
	float tempsInitial;
	std::list<ObjetEnchere*> encheres;
};
