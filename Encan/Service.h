#pragma once
#include "ObjetGenerique.h"
class Service
{
public:
	~Service() { }

	std::shared_ptr<ObjetGenerique> getObjectGenerique() { return std::make_shared<ObjetGenerique>(myCarac, objEnc); }
	static std::unique_ptr<Service> callFactory();
	static std::string getNomDuProgrammeursAimantCeTypeDObjet() { return "Bah on est que 2...."; }
private:

	friend class FactoryBetS;
	std::shared_ptr<ObjetEncan> objEnc;
	ObjetGenerique::CaracSer myCarac;
	Service(int frais, int tarif, ObjetGenerique::TypeSer type, int xp, std::shared_ptr<ObjetEncan> obj)
	{
		myCarac = { frais, tarif, type, xp };
		objEnc = obj;
	}
};
