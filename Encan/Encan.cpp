#include "pch.h"
#include "Encan.h"
#include "Temps.h"
float Encan::temps = 0;
Encan* Encan::instance = nullptr;

Encan* Encan::getInstance()
{
	if (instance == nullptr)
	{
		instance = new Encan();
	}
	return instance;
}

bool Encan::encherir(ObjetGenerique* objet_generique, int prix, std::string nomAcheteur) const
{
	// std::string nomVendeur contenu dans l'objet
	ObjetEncan* aux = objet_generique->getObjEnc().get();
	aux->addEnchere(new ObjetEnchere(nomAcheteur, objet_generique->getNomVendeur(),
		prix));
	if (aux->getPrixActuel() > aux->getPrixMin() && aux->getNbEnchere() > aux->getMinNbEnchere()
		&& (Temps::getTemps() - aux->getTempsIni()) > 2)
		return true;
	return false;
}

void Encan::afficheInformation()
{
	//activation des exceptions sur l'affichage
	std::cout.exceptions(std::cout.badbit);
	while (true)
	{
		std::cout << "\n Debut de l'affichage des objets de l'Encan: ";
		try
		{
			if (listeObjets.size() == 0)
				throw 0.0;
			for (auto i : listeObjets)
			{
				*i << std::cout;
			}
			throw std::string("Fin de l'affichage");
		}
		catch (std::ios_base::iostate except)
		{
			std::cout << std::to_string(except) << std::endl;
		}
		catch (std::string message)
		{
			std::cout << std::endl << message;
		}
		catch (...)
		{
			std::cout << std::endl << "Il n'y a presentement aucun objet a vendre dans l'encan !" << std::endl;
		}
		std::this_thread::sleep_for(std::chrono::seconds(5));
	}
}

Encan::Encan()
{
	mtx = new std::mutex();
	std::thread(&Temps::passerTemps).detach();
	std::thread(&Encan::afficheInformation, this).detach();
	//daemon.detach();
}
