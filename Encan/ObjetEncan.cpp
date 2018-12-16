#include "pch.h"
#include "ObjetEncan.h"
#include "Encan.h"

ObjetEncan::ObjetEncan(int prixIni, int prixMin, int minNbEnchere, int maxNbEnchere)
{
	this->prixIni = prixIni;
	prixActuel = prixIni;
	this->prixMin = prixMin;
	this->minNbEnchere = minNbEnchere;
	this->maxNbEnchere = maxNbEnchere;
	tempsInitial = Encan::getTemps();
}
