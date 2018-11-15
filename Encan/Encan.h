#pragma once
#include "ObjetGenerique.h"
#include <vector>
class Encan
{
public:
	~Encan() {}
	Encan getInstance()
	{
		if (instance == nullptr)
		{
			instance = new Encan();
		}
		return *instance;
	}
	void pushObjet(ObjetGenerique*o)
	{
		listeObjets.push_back(o);
	}
	auto getListeObjet(ObjetGenerique*o)
	{
		return listeObjets;
	}


private:
	//static int const nbObjetsMax = 10;
	std::vector<ObjetGenerique*> listeObjets;

	Encan() {}
	Encan* instance;
};
