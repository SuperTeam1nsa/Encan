#pragma once
#include "ObjetGenerique.h"

class Service
{
public:
	~Service()
	{
		delete objGen;
	}

	ObjetGenerique* getObjectGenerique() const { return objGen; }
	static Service* callFactory(std::string id);
	static std::string getNomDuProgrammeursAimantCeTypeDObjet() { return "Societe de Service Anonyme"; }
private:

	friend class FactoryService;
	CaracSer myCarac;
	ObjetGenerique* objGen;

	Service(int frais, int tarif, TypeSer type, int xp, std::string nom_vendeur, std::shared_ptr<ObjetEncan> obj)
	{
		myCarac = { frais, tarif, type, xp, nom_vendeur };
		objGen = new ObjetGenerique(myCarac, obj);
	}
};
