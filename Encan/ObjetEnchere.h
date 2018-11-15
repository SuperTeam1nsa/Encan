#pragma once
#include "ObjetGenerique.h"
class ObjetEnchere
{
public:
	ObjetEnchere(std::string nomAcheteur, std::string nomVendeur, ObjetGenerique obj) {
		this->nomAcheteur = nomAcheteur;
		this->nomVendeur = nomVendeur;
		this->obj = obj;
	}
	~ObjetEnchere() {}
private:
	std::string nomAcheteur;
	std::string nomVendeur;
	ObjetGenerique obj;
};
