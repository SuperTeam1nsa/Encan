#include "pch.h"
#include "ObjetGenerique.h"


ObjetGenerique::ObjetGenerique(CaracAnt carac_ant, std::shared_ptr<ObjetEncan> obj)
{
	this->myCarac = {
		ANTIQUITE, carac_ant.valeur, carac_ant.nomVendeur,
		carac_ant.description, carac_ant.etat, carac_ant.periode,
		-1, -1, INCONNU, "",
		-1, UNKNOWN, -1, obj
	};
}

ObjetGenerique::ObjetGenerique(CaracArt carac_art, std::shared_ptr<ObjetEncan> obj)
{
	this->myCarac = {
		ART, carac_art.valeur, carac_art.nomVendeur,
		"", NEUF, INCONNUE,
		carac_art.renomee, carac_art.volume, carac_art.type, carac_art.description,
		-1, UNKNOWN, -1, obj
	};
}

ObjetGenerique::ObjetGenerique(CaracSer carac_ser, std::shared_ptr<ObjetEncan> obj)
{
	this->myCarac = {
		SERVICE, carac_ser.frais + carac_ser.tarif, carac_ser.nomVendeur,
		"", NEUF, INCONNUE,
		-1, -1, INCONNU, "",
		-1, carac_ser.type, carac_ser.xp, obj
	};
}

ObjetGenerique::~ObjetGenerique()
{
}
