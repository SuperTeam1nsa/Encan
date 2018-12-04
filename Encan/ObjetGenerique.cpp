#include "pch.h"
#include "ObjetGenerique.h"


ObjetGenerique::ObjetGenerique(CaracAnt carac_ant, std::shared_ptr<ObjetEncan> obj)
{
	this->myCarac = { Description::ANTIQUITE,  carac_ant.valeur,carac_ant.nomVendeur,
	carac_ant.description, carac_ant.etat, carac_ant.periode,
	-1, -1, TypeArt::INCONNU, "",
	-1, TypeSer::UNKNOWN, -1, obj };
}

ObjetGenerique::ObjetGenerique(CaracArt carac_art, std::shared_ptr<ObjetEncan> obj)
{
	this->myCarac = { Description::ART, carac_art.valeur,carac_art.nomVendeur,
	"", StructEtat::NEUF, Periode::INCONNUE,
	carac_art.renomee, carac_art.volume, carac_art.type, carac_art.description,
	-1, TypeSer::UNKNOWN , -1,obj };
}

ObjetGenerique::ObjetGenerique(CaracSer carac_ser, std::shared_ptr<ObjetEncan> obj)
{
	this->myCarac = { Description::SERVICE, carac_ser.frais + carac_ser.tarif,carac_ser.nomVendeur,
	"", StructEtat::NEUF, Periode::INCONNUE,
	-1, -1, TypeArt::INCONNU, "",
	-1, carac_ser.type, carac_ser.xp,obj };
}

ObjetGenerique::~ObjetGenerique()
{
}
