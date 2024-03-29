﻿#include "pch.h"
#include <time.h>
#include <thread>
#include "FactoryAV.h"
#include "FactoryArt.h"
#include "FactoryAntiquite.h"
#include "FactoryService.h"
#include "Art.h"

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	//int const NB_VENDEURS_INI = 5;
	//int const NB_ACHETEURS_INI = 5;
	//no threads
	/*for (int i = 0; i < NB_VENDEURS_INI; i++)
		listeVendeurs.push_back(FactoryAV::createVendeurs());
	for (int i = 0; i < NB_ACHETEURS_INI; i++)
		listeAcheteurs.push_back(FactoryAV::createAcheteurs());*/

		//threads: 
		// pas un while(1) pour commencer :p 
	for (int i = 0; i < 100; i++)
	{


		std::thread(&Vendeurs<Art>::vendre, FactoryAV::createVendeurs<Art>()).detach();
		std::thread(&Vendeurs<Service>::vendre, FactoryAV::createVendeurs<Service>()).detach();
		std::thread(&Vendeurs<Antiquite>::vendre, FactoryAV::createVendeurs<Antiquite>()).detach();

		std::thread(&Acheteurs::acheter, FactoryAV::createAcheteurs()).detach();
		/*std::thread(&Acheteurs::acheter, FactoryAV::createAcheteurs()).detach();
		std::thread(&Acheteurs::acheter, FactoryAV::createAcheteurs()).detach();*/
		//si dans la classe :std::thread spawn() {return std::thread([this] { this->test(); });}

		//std::thread(Vendeurs<Art>::vendre, a).detach();
		//std::thread(FactoryAV::createVendeursAvecAdaptateur()->vendre);

		//std::thread(FactoryAV::createAcheteurs()->acheter);
		//wait un delay pour la boucle 00
		//pour eq: 2s avant respawn, les ventes devraient se faire environ dans ce délai pour éviter un nombre de 
		//vendeurs/ acheteurs déséquilibré ( qui ferait tendre le plus long vers +00)
		std::this_thread::sleep_for(std::chrono::seconds(10));
	}

	//temps de check que les threads sont finis (on aurait utiliser join() sur des threads nommés)

	//delete Encan::getInstance(); //ou shared_ptr sur l'instance de l'Encan mais perte de performances  
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

/*//attention pas de ptrs inteligents car sinon on tue l'objet à la fin de la ligne
		//pas de souci de destruction car il y aura un delete this dans vendeurs #très propre tout ça LOL++
		//#la version avec les pointeurs intelligents reviendrait à en passer un à l'objet => full stupid xD
		//ok donc une fonction de create vendeur sera appellé souvent qqch comme check()
		//mutex only vis à vis des ressources patagées #encan
		//std::thread(std::bind((FactoryAV::createVendeurs<Art>())->vendre, std::placeholders::_1)).detach();

	//	void (Vendeurs<Art>::*ptr)() = &Vendeurs<Art>::vendre;
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
