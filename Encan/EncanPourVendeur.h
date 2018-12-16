#pragma once

#include "ObjetGenerique.h"
#include <mutex>

class EncanPourVendeur
{
public:
	EncanPourVendeur() {}
	virtual ~EncanPourVendeur() {}
	virtual void pushObjet(ObjetGenerique* o) = 0;
	virtual void removeObjet(ObjetGenerique* o) = 0;
	virtual bool estVendu(ObjetGenerique* obj) = 0;
	virtual std::mutex* getMutex() const = 0;

};
