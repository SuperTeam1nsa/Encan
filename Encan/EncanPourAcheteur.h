#pragma once
#include "ObjetGenerique.h"
#include <mutex>

class EncanPourAcheteur
{
public:
	EncanPourAcheteur() {}
	virtual ~EncanPourAcheteur() {}

	virtual bool encherir(ObjetGenerique* objet_generique, int prix, std::string nomAcheteur) const = 0;
	virtual std::list<ObjetGenerique*> getListeObjet() const = 0;
	virtual std::mutex* getMutex() const = 0;
	virtual void removeObjet(ObjetGenerique* o) = 0;
};
