#pragma once
#include "ObjetGenerique.h"

class Encan
{
public:
	~Encan() {}
	Encan getInstance() 
	{ 
		if (instance == nullptr) 
		{
			*instance = Encan();
		}
		return *instance;
	}

private:
	static int const nbObjetsMax=10;
	ObjetGenerique* listeObjets[nbObjetsMax];

	Encan() {}
	Encan* instance;
};