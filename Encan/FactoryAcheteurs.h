#pragma once
#include "Acheteurs.h"

class FactoryAcheteurs
{
public:
	FactoryAcheteurs() {}
	~FactoryAcheteurs() {}
	static Acheteurs* createAcheteurs();
private:
	static unsigned long idAcheteur;
};
