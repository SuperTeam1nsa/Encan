#pragma once
enum EtatAcheteur { AGRESSIF, CONCENTRE, NORMAL, PASSIF };
class Etat
{
public:
	Etat() {}
	virtual float probabilite_achat() = 0;
	virtual int getEtatID() = 0;
	virtual ~Etat() {}
	//	virtual Etat* getNewEtat(bool) = 0; //=dans la MEF
};
