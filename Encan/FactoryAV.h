#pragma once
#include "Acheteurs.h"
#include "Vendeurs.h"
#include "Encan.h"

class FactoryAV
{
public:
	//ou en template aussi les acheteurs= NON #foncteurs et not need anyway
	static Acheteurs* createAcheteurs();
	//car thread + delete this
/*	template <class T>
	static Vendeurs<T>* createVendeurs();*/

	template <class T>
	static Vendeurs<T>* createVendeurs()
	{
		return new Vendeurs<T>(T::callFactory(" " + std::to_string(++idVendeur)), T::getNomDuProgrammeursAimantCeTypeDObjet(), Encan::getInstance());
		//ou des cast pout T, callFactory appel FactoryBetS::create...
	}
private:
	static unsigned long idVendeur;
	static unsigned long idAcheteur;
	//static VendeursAvecAdaptateur* createVendeursAvecAdaptateur();
	//static std::shared_ptr<Vendeurs<T>> createVendeurs();
	//static std::shared_ptr<VendeursAvecAdaptateur> createVendeursAvecAdaptateur();
};
//rq sur inline, et template en static :
/*
 https://stackoverflow.com/questions/488959/how-do-you-create-a-static-template-member-function-that-performs-actions-on-a-t
Short Answer

Define the function in the header, preferably inside the class definition.
Long answer

Defining the template function inside the .cpp means it won't get #included into any translation units: it will only be available to the translation unit it's defined in.

Hence RemoveVectorDuplicates must be defined in the header, as this is the only way the compiler can text-substitute the template arguments, hence instantiating the template, producing an usable class.
There are two workarounds for this inconvenience

First, you can remove the #include "foo.h" from the .cpp and add another one, in the end of the header:

#include "foo.cpp"

This lets you organize your files consistently, but doesn't provide the usual advantages of separate compilation (smaller dependencies, faster and rarer compiles).

Second, you can just define the template function in the .cpp and explicitly instantiate it for all the types it'll be ever used with.

For example, this can go in the end of the .cpp to make the function usable with ints:

template void Foo::RemoveVectorDuplicates(std::vector<int>*);

However, this assumes you only use templates to save some typing, rather than to provide true genericity.
*/
