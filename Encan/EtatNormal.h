#pragma once
#include "Etat.h"
class EtatNormal :public virtual Etat
{
public:
	EtatNormal(int id) { this->id = id; }
	float probabilite_achat() { return 0.8; }
	int getEtatID() {
		return id;
	}
	virtual ~EtatNormal() {}
private:
	int id;

};
