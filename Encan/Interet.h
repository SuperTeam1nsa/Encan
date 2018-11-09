#pragma once
//foncteur évolué /#cycle de vie à gérér => semi foncteur ^^ 
//#présence d'un constructeur
struct Interet
{
private:
	int description;  //ou avec des strings
	int prix;
public:
	Interet(int d, int price) :prix(price), description(d) {};
	bool operator()(int a)//ObjetEncan
	{
		return true;
		//return description == a.getDescription() || prix <= a.getPrice();
	}

};
