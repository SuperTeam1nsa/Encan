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

Encan::Encan()
{
	mtx = new std::mutex();
	std::thread(&Temps::passerTemps).detach();
	//daemon.detach();
}
