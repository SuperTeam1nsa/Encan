#pragma once
class Service
{
public:
	~Service() {}
	enum Type
	{
		LIVRAISON, VOYAGE, MENAGE, CUISINE, COURS, INCONNU
	};

	int getFrais() const { return myCarac.frais; }
	int getTarif() const { return myCarac.tarif; }
	Type getType() const { return myCarac.type; }
	int getXp() const { return myCarac.xp; }

private:
	Service(int frais, int tarif, Type type, int xp)
	{
		myCarac = { frais, tarif, type, xp };
	}
	Service(Type type) : Service(10, 100, type, 50) {}
	Service() : Service(10, 100, INCONNU, 50) {}

	
	struct CaracSer
	{
		int frais;
		int tarif;
		Type type;
		int xp;
	};

	CaracSer myCarac;
};
