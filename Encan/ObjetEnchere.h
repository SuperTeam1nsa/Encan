#pragma once
#include "ObjetGenerique.h"
class ObjetEnchere
{
public:
	ObjetEnchere(std::string nomAcheteur, std::string nomVendeur, ObjetGenerique obj, int prix) {
		this->nomAcheteur = nomAcheteur;
		this->nomVendeur = nomVendeur;
		this->obj = obj;
		this->prix = prix;
	}
	~ObjetEnchere() {}
private:
	std::string nomAcheteur;
	std::string nomVendeur;
	ObjetGenerique obj;
	int prix;
};
