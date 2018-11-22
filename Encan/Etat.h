#pragma once
enum EtatAcheteur { AGRESSIF, NORMAL, PASSIF };
class Etat
{
public:
	Etat() {}
	virtual Etat* getNewEtat() = 0;
	virtual ~Etat() {}
	virtual int getEtatID() = 0;
};
