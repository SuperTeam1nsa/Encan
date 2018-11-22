#include "pch.h"
#include "ObjetGenerique.h"

ObjetGenerique::ObjetGenerique(CaracAnt myCarac)
{
	this->myCarac = { Description::ANTIQUITE, myCarac.description, myCarac.etat, myCarac.periode, myCarac.valeur,
	-1, -1, -1, TypeArt::INCONNU, "",
	-1, -1, TypeSer::INCONNU, -1 };
}

ObjetGenerique::ObjetGenerique(CaracArt myCarac)
{
	this->myCarac = { Description::ART, "", Etat::NEUF, Periode::INCONNUE, -1,
	myCarac.renomee, myCarac.valeur, myCarac.volume, myCarac.type, myCarac.description,
	-1, -1, TypeSer::INCONNU, -1 };
}

ObjetGenerique::ObjetGenerique(CaracSer myCarac)
{
	this->myCarac = { Description::SERVICE, "", Etat::NEUF, Periode::INCONNUE, -1,
	-1, -1, -1, TypeArt::INCONNU, "",
	myCarac.frais, myCarac.tarif, myCarac.type, myCarac.xp };
}

ObjetGenerique::~ObjetGenerique()
{
}
