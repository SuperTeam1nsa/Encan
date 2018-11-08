#pragma once
#include "Acheteurs.h"
#include "Vendeurs.h"
class FactoryAV
{
public:
	//ou en template aussi les acheteurs
	template <class T>
	static Acheteurs<T>* createAcheteurs();
	template <class T>
	static Vendeurs<T>* createVendeurs();
};
