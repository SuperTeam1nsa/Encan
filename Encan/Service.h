#pragma once
class Service
{
public:
	~Service() {}
	enum Type
	{
		LIVRAISON, VOYAGE, MENAGE, CUISINE, COURS, INCONNU
	};

	int getFrais() const { return frais; }
	int getTarif() const { return tarif; }
	Type getType() const { return type; }
	int getXp() const { return xp; }

private:
	Service(int frais, int tarif, Type type, int xp)
	{
		setFrais(frais);
		setTarif(tarif);
		setType(type);
		setXp(xp);
	}
	Service(Type type) : Service(10, 100, type, 50) {}
	Service() : Service(10, 100, INCONNU, 50) {}

	int frais;
	int tarif;
	Type type;
	int xp;


	void setFrais(int frais) { this->frais = frais; }
	void setTarif(int tarif) { this->tarif = tarif; }
	void setType(Type type) { this->type = type; }
	void setXp(int xp) { this->xp = xp; }
};
