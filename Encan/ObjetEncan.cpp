#include "pch.h"
#include "ObjetEncan.h"
#include "Temps.h"

ObjetEncan::ObjetEncan(int prixIni, int prixMin, int minNbEnchere, int maxNbEnchere)
{
	this->prixIni = prixIni;
	prixActuel = prixIni;
	this->prixMin = prixMin;
	this->minNbEnchere = minNbEnchere;
	this->maxNbEnchere = maxNbEnchere;
	tempsInitial = Temps::getTemps();
}
