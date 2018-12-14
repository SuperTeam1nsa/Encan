#include "pch.h"
#include "EncanPourAcheteur.h"


EncanPourAcheteur::EncanPourAcheteur()
{
}


EncanPourAcheteur::~EncanPourAcheteur()
{
}

void EncanPourAcheteur::encherir(Acheteurs acheteur, ObjetGenerique* objet)
{
	Encan::encherir(objet, 10, acheteur.getNom());
}