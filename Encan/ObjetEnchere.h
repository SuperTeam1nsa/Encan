#pragma once

class ObjetEnchere
{
public:
	//contenu dans un objet générique pas besoin de spécifier à quel objet font réf ces enchères
	ObjetEnchere(std::string nomAcheteur, std::string nomVendeur, int prix)
	{
		this->nomAcheteur = nomAcheteur;
		this->nomVendeur = nomVendeur;
		this->prix = prix;
	}

	~ObjetEnchere()
	{
	}

private:
	std::string nomAcheteur;
	std::string nomVendeur;
	int prix;
};
