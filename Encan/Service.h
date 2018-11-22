#pragma once
class Service
{
public:
	~Service() { }

	int getFrais() const { return myCarac.frais; }
	int getTarif() const { return myCarac.tarif; }
	ObjetGenerique::TypeSer getType() const { return myCarac.type; }
	int getXp() const { return myCarac.xp; }
	std::shared_ptr<ObjetGenerique> getObjectGenerique() { return std::make_shared<ObjetGenerique>(myCarac, objEnc); }
	static std::unique_ptr<Service> callFactory();
	static std::string getNomCategorie() { return "Service"; }
	static std::string getNomDuProgrammeursAimantCeTypeDObjet() { return "Bah on est que 2...."; }
private:
	Service(int frais, int tarif, ObjetGenerique::TypeSer type, int xp, std::shared_ptr<ObjetEncan> obj)
	{
		myCarac = { frais, tarif, type, xp };
	}
	//Service(ObjetGenerique::TypeSer type) : Service(10, 100, type, 50) {}
	//Service() : Service(10, 100, ObjetGenerique::TypeSer::INCONNU, 50) {}
	friend class FactoryBetS;
	std::shared_ptr<ObjetEncan> objEnc;
	ObjetGenerique::CaracSer myCarac;
};
