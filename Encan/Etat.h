#pragma once
enum EtatAcheteur { AGRESSIF, CONCENTRE, NORMAL, PASSIF, NB };

class Etat
{
public:
	Etat()
	{
	}

	virtual float probabiliteAchat() = 0;
	virtual int getEtatId() = 0;
	virtual std::string description() = 0;
	virtual ~Etat()
	{
	}

	//	virtual Etat* getNewEtat(bool) = 0; //=dans la MEF
};
