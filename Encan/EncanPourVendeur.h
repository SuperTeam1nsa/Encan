#pragma once

#include "ObjetGenerique.h"
#include "Vendeurs.h"
#include "Encan.h"

class EncanPourVendeur
{
public:
	EncanPourVendeur();
	~EncanPourVendeur();

	static void vendre(ObjetGenerique objet);
};

