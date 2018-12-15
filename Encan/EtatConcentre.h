#pragma once
#include "EtatAgressif.h"
#include "EtatNormal.h"

class EtatConcentre : public EtatAgressif, public EtatNormal
{
public:
	explicit EtatConcentre(int id) : EtatAgressif(id), EtatNormal(id) { this->id = id; }

	float probabiliteAchat() override
	{
		return (EtatAgressif::probabiliteAchat() + EtatNormal::probabiliteAchat()) / 2;
	};

	int getEtatId() override
	{
		return id;
	}

	virtual ~EtatConcentre()
	{
	}

private:
	int id;
};
