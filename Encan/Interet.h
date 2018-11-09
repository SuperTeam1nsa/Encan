#pragma once
//foncteur évolué /#cycle de vie à gérér => semi foncteur ^^ 
//#présence d'un constructeur
class Interet
{
	Description description;  //ou avec des strings
	int prix;
public:
	Interet(Description d, int price) :prix(price), description(d) {};
	bool operator()(ObjetEncan a)
	{
		//return description == a.getDescription() || prix <= a.getPrice();
	}

};
