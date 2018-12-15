#pragma once
#include "ObjetGenerique.h"

class Service
{
public:
	~Service()
	{
	}

	ObjetGenerique* getObjectGenerique() const { return new ObjetGenerique(myCarac, objEnc); }
	static Service* callFactory();
	static std::string getNomDuProgrammeursAimantCeTypeDObjet() { return "Bah on est que 2...."; }
private:

	friend class FactoryBetS;
	std::shared_ptr<ObjetEncan> objEnc;
	CaracSer myCarac;

	Service(int frais, int tarif, TypeSer type, int xp, std::string nom_vendeur, std::shared_ptr<ObjetEncan> obj)
	{
		myCarac = { frais, tarif, type, xp, nom_vendeur };
		objEnc = obj;
	}
};
