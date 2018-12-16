#pragma once
//foncteur évolué /#cycle de vie à gérér => semi foncteur ^^ 
//#présence d'un constructeur
#include "ObjetGenerique.h"
//struct
class Interet
{
public:


	//RQ: si encheres pas constantes on aurait rajouter un paramètre valeur_enchères pour avoir la valeur de
	//l'enchere (en place_holder) 
	bool operator()(Description description, int budget, ObjetGenerique& a) const //ObjetEncan
	{
		/*int val;
		switch (description)
		{
		case ART:
			val = a.getCaracG().valeurArt;
		case ANTIQUITE:
			val = a.getCaracG().valeur;
		case SERVICE:
			val = a.getCaracG().tarif;
		}*/
		//if (a.getCaracG().objEnc.get()->getPrixActuel()<= budget)

		//interesse = (prix / val) * 0.9 < ((RAND_MAX + rand()) / (2*RAND_MAX));*/

		//encheres constantes de 20
		return (description == a.getCaracG().typeObjet) && (a.getCaracG().objEnc.get()->getPrixActuel() <= budget - 20);
		//return description == a.getDescription() || prix <= a.getPrice();
	}
};
