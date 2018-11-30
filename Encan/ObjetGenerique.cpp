#include "pch.h"
#include "ObjetGenerique.h"


ObjetGenerique::ObjetGenerique(CaracAnt myCarac, std::shared_ptr<ObjetEncan> obj)
{
	this->myCarac = { Description::ANTIQUITE,  myCarac.valeur, 
	myCarac.description, myCarac.etat, myCarac.periode,
	-1, -1, TypeArt::INCONNU, "",
	-1, TypeSer::INCONNU, -1, obj };
}

ObjetGenerique::ObjetGenerique(CaracArt myCarac, std::shared_ptr<ObjetEncan> obj)
{
	this->myCarac = { Description::ART, myCarac.valeur, 
	"", Etat::NEUF, Periode::INCONNUE,
	myCarac.renomee, myCarac.volume, myCarac.type, myCarac.description,
	-1, TypeSer::INCONNU, -1,obj };
}

ObjetGenerique::ObjetGenerique(CaracSer myCarac, std::shared_ptr<ObjetEncan> obj)
{
	this->myCarac = { Description::SERVICE, myCarac.frais + myCarac.tarif, 
	"", Etat::NEUF, Periode::INCONNUE,
	-1, -1, TypeArt::INCONNU, "",
	-1, myCarac.type, myCarac.xp,obj };
}

ObjetGenerique::~ObjetGenerique()
{
}
