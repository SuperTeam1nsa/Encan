#pragma once
#include <iostream>
#include "ObjetGenerique.h"

class Affichage_Info
{
public:
	Affichage_Info() {}
	~Affichage_Info() {};
	template <class T>
	void operator()(std::list<std::shared_ptr<ObjetGenerique>>& obj) {
		for (auto& i : obj)
			std::cout << T.getInfo(i) << std::endl;
	}
};
