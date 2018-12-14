#include "pch.h"
#include "Vendeurs.h"

template <class T>
void Vendeurs<T>::mettreAuxEncheres()
{
	while (!objetEnEnchere)
	{
		Encan::getInstance()->getMutex()->lock();
		mettreAuxEncheres();
		objetEnEnchere = true;
		Encan::getInstance()->getMutex()->unlock();
		std::this_thread::sleep_for(std::chrono::milliseconds(20));
	}
	bool vendu = false;
	while (!vendu)
	{
		//template de méthode, l'accès en lecture ne doit pas être fait en même temps qu'une modification sur la liste
		Encan::getInstance()->getMutex()->lock();
		vendu = Encan::getInstance()->estVendu(objet->getObjectGenerique().get());
		Encan::getInstance()->getMutex()->unlock();
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
	//faire sa vie de thread
}

template <class T>
void Vendeurs<T>::vendre()
{
	if (!objetEnEnchere)
		mettreAuxEncheres();
	//faire sa vie de thread
	//voir mutex dans acheteurs.cpp

}
