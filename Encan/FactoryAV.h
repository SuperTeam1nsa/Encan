#pragma once
#include "Acheteurs.h"
#include "Vendeurs.h"
class FactoryAV
{
public:
	//ou en template aussi les acheteurs
	static Acheteurs* createAcheteurs();
	template <class T>
	static Vendeurs<T>* createVendeurs();
};
