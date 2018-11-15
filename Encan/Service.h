#pragma once
class Service
{
public:
	~Service() { delete objEncan; }

	int getFrais() const { return myCarac.frais; }
	int getTarif() const { return myCarac.tarif; }
	ObjetGenerique::TypeSer getType() const { return myCarac.type; }
	int getXp() const { return myCarac.xp; }

private:
	Service(int frais, int tarif, ObjetGenerique::TypeSer type, int xp, ObjetEncan* obj)
	{
		myCarac = { frais, tarif, type, xp };
	}
	Service(ObjetGenerique::TypeSer type) : Service(10, 100, type, 50) {}
	Service() : Service(10, 100, ObjetGenerique::TypeSer::INCONNU, 50) {}
	friend class FactoryBetS;
	ObjetEncan* objEncan;
	ObjetGenerique::CaracSer myCarac;
};
