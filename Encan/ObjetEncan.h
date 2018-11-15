#pragma once
#include <list>
#include "ObjetEnchere.h"
enum Description
{
	ART, ANTIQUITE, SERVICE
};

//contenu dans les objets
class ObjetEncan
{
public:
	ObjetEncan(int prixIni, int prixMin, int minNbEnchere, int maxNbEnchere) {
		this->prixIni = prixIni;
		this->prixMin = prixMin;
		this->minNbEnchere = minNbEnchere;
		this->maxNbEnchere = maxNbEnchere;

	}
	void addEnchere(ObjetEnchere obj) {
		encheres.push_back(obj);
	}
	// T* obj) { objet = obj; };
	~ObjetEncan() {
		encheres.clear();
	}
	//T* getObjet() { return objet; }
//:
	//T* objet; //art, antiquite, services etc
private:
	int prixIni;
	int prixMin;
	int minNbEnchere;
	int maxNbEnchere;
	std::list<ObjetEnchere> encheres;
};
