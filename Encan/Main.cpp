﻿// Encan.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <random>
#include <time.h>
#include <iostream>
#include <thread>
#include "Art.h"
#include "Antiquite.h"
#include "Service.h"
#include "Acheteurs.h"
#include "Vendeurs.h"
#include "FactoryAV.h"
#include "Encan.h"


int main()
{
	srand(time(NULL));

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
		//attention pas de ptrs inteligents car sinon on tue l'objet à la fin de la ligne
		//pas de souci de destruction car il y aura un delete this dans vendeurs #très propre tout ça LOL++
		//#la version avec les pointeurs intelligents reviendrait à en passer un à l'objet => full stupid xD
		//ok donc une fonction de create vendeur sera appellé souvent qqch comme check() 
		//mutex only vis à vis des ressources patagées #encan
		std::thread(FactoryAV::createVendeurs<Art>()->vendre);
		std::thread(FactoryAV::createVendeursAvecAdaptateur()->vendre);
		std::thread(FactoryAV::createAcheteurs()->acheter);
		//wait un delay pour la boucle oo
	}

	//temps de check que les threads sont finis (on aurait utiliser join() sur des threads nommés)
	std::this_thread::sleep_for(std::chrono::seconds(10));
	//delete Encan::getInstance(); //ou shared_ptr sur l'instance de l'Encan mais perte de performances :\ 



}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Conseils pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
