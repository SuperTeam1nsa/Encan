#include "pch.h"
#include "ObjetGenerique.h"


ObjetGenerique::ObjetGenerique(CaracAnt myCarac, std::shared_ptr<ObjetEncan> obj)
{
	this->myCarac = { Description::ANTIQUITE, myCarac.description, myCarac.etat, myCarac.periode, myCarac.valeur,
	-1, -1, -1, TypeArt::INCONNU, "",
	-1, -1, TypeSer::INCONNU, -1, obj };
}

ObjetGenerique::ObjetGenerique(CaracArt myCarac, std::shared_ptr<ObjetEncan> obj)
{
	this->myCarac = { Description::ART, "", Etat::NEUF, Periode::INCONNUE, -1,
	myCarac.renomee, myCarac.valeur, myCarac.volume, myCarac.type, myCarac.description,
	-1, -1, TypeSer::INCONNU, -1,obj };
}

ObjetGenerique::ObjetGenerique(CaracSer myCarac, std::shared_ptr<ObjetEncan> obj)
{
	this->myCarac = { Description::SERVICE, "", Etat::NEUF, Periode::INCONNUE, -1,
	-1, -1, -1, TypeArt::INCONNU, "",
	myCarac.frais, myCarac.tarif, myCarac.type, myCarac.xp,obj };
}

ObjetGenerique::~ObjetGenerique()
{
}
