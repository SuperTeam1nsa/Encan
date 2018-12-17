#include "pch.h"
#include <time.h>
#include <thread>
#include "Service.h"
#include "Antiquite.h"
#include "Art.h"
#include "FactoryAcheteurs.h"
#include "FactoryVendeurs.h"

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	//ou while(true) si on veut une boucle infinie
	for (int i = 0; i < 100; i++)
	{
		std::thread(&Vendeurs<Art>::vendre, FactoryVendeurs::createVendeurs<Art>()).detach();
		std::thread(&Vendeurs<Service>::vendre, FactoryVendeurs::createVendeurs<Service>()).detach();
		std::thread(&Vendeurs<Antiquite>::vendre, FactoryVendeurs::createVendeurs<Antiquite>()).detach();

		std::thread(&Acheteurs::acheter, FactoryAcheteurs::createAcheteurs()).detach();
		std::thread(&Acheteurs::acheter, FactoryAcheteurs::createAcheteurs()).detach();
		std::thread(&Acheteurs::acheter, FactoryAcheteurs::createAcheteurs()).detach();

		//wait un delay pour la boucle 00
		//avant respawn, les ventes devraient se faire environ dans ce délai pour éviter un nombre de 
		//vendeurs/ acheteurs déséquilibré ( qui ferait tendre le plus long vers +00)
		std::this_thread::sleep_for(std::chrono::seconds(10));
	}

	//temps de check que les threads sont finis (on aurait utiliser join() sur des threads nommés)
	std::this_thread::sleep_for(std::chrono::seconds(30));
	delete Encan::getInstance(); //ou shared_ptr sur l'instance de l'Encan mais perte de performances  
}


//	void (Vendeurs<Art>::*ptr)(int) = &Vendeurs<Art>::vendre;
//		Vendeurs<Art>* a = FactoryAV::createVendeurs<Art>();

//Vendeurs<Art> az(*a);
//(az.*ptr)(nullptr);
//void(*b)(void*t) = vendre;
//std::thread(&Vendeurs<Art>::vendre).detach()
//		std::thread(ptr, a).detach();

//rq: pointeur simple car delete this en interne
//le deuxième pointeur est le this vers l'objet qui appelle
//3 = paramètre ou std::bind pour faire propre
//std::thread(&Vendeurs<Art>::vendre, 3 , FactoryAV::createVendeurs<Art>()).detach();


//Vendeurs<Art> temp(Art::callFactory(), Art::getNomDuProgrammeursAimantCeTypeDObjet());
//Vendeurs<Art> temp1(*FactoryAV::createVendeurs<Art>());*/
