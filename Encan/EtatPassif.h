#pragma once
#include "Etat.h"
class EtatPassif :public Etat
{
public:
	EtatPassif(int id) { this->id = id; };
	float probabilite_achat() { return 0.6; };
	int getEtatID() {
		return id;
	}
	virtual ~EtatPassif() {};
private:
	int id;

};
