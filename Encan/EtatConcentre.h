#pragma once
#include "EtatAgressif.h"
#include "EtatNormal.h"
class EtatConcentre :virtual public EtatAgressif, virtual public EtatNormal
{
public:
	EtatConcentre(int id) :EtatAgressif(id), EtatNormal(id) { this->id = id; }
	float probabilite_achat() { return (EtatAgressif::probabilite_achat() + EtatNormal::probabilite_achat()) / 2; };
	int getEtatID() {
		return id;
	}
	virtual ~EtatConcentre() {}
private:
	int id;

};
