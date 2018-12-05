#pragma once
#include "Acheteurs.h"

class FactoryAV
{
public:
	//ou en template aussi les acheteurs= NON #foncteurs et not need anyway
	static Acheteurs* createAcheteurs();
	//car thread + delete this
	template <class T>
	static Vendeurs<T>* createVendeurs();
	//static VendeursAvecAdaptateur* createVendeursAvecAdaptateur();
	//static std::shared_ptr<Vendeurs<T>> createVendeurs();
	//static std::shared_ptr<VendeursAvecAdaptateur> createVendeursAvecAdaptateur();
};
