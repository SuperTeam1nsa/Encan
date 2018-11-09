#pragma once
#include "Acheteurs.h"
#include "Vendeurs.h"
#include "Interet.h"
class FactoryAV
{
public:
	//ou en template aussi les acheteurs= NON #foncteurs et not need anyway
	static auto createAcheteurs();
	template <class T>
	static Vendeurs<T>* createVendeurs();
};
