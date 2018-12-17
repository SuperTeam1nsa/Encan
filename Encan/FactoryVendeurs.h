#pragma once
#include "Vendeurs.h"
#include "Encan.h"

class FactoryVendeurs
{
public:
	FactoryVendeurs();
	~FactoryVendeurs();

	template <class T>
	static Vendeurs<T>* createVendeurs()
	{
		return new Vendeurs<T>(T::callFactory(" " + std::to_string(++idVendeur)),
			T::getNomDuProgrammeursAimantCeTypeDObjet(), Encan::getInstance());
	}

private:
	static unsigned long idVendeur;
};
