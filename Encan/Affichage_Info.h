#pragma once
#include <iostream>
#include "ObjetGenerique.h"
template <class T>
class Affichage_Info
{
public:
	Affichage_Info() {}
	~Affichage_Info() {};
	operator()(std::list<std::shared_ptr<ObjetGenerique>()>& obj) {
		for (auto& i : obj)
			std::cout << T.getInfo(i) << std::endl;
	}
};
