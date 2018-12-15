#include "pch.h"
#include "EncanPourVendeur.h"


EncanPourVendeur::EncanPourVendeur()
{
}


EncanPourVendeur::~EncanPourVendeur()
{
}

void EncanPourVendeur::vendre(ObjetGenerique objet)
{
	Encan::getInstance()->pushObjet(objet);
}
