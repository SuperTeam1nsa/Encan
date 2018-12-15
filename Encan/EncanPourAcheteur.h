#pragma once
#include "ObjetGenerique.h"
#include "Acheteurs.h"
#include "Encan.h"

class EncanPourAcheteur
{
public:
	EncanPourAcheteur();
	~EncanPourAcheteur();

	static void encherir(Acheteurs& acheteur, ObjetGenerique& objet);
};

