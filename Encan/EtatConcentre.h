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

	std::string description() override { return "Etat Concentre"; }

	virtual ~EtatConcentre()
	{
	}

private:
	int id;
};
