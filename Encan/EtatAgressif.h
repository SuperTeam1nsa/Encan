#pragma once
class EtatAgressif : virtual public Etat
{
public:
	explicit EtatAgressif(int id) { this->id = id; };
	float probabiliteAchat() override { return 1.0; };

	int getEtatId() override
	{
		return id;
	}
	std::string description() override { return "Etat Agressif"; }
	virtual ~EtatAgressif()
	{
	};
private:
	int id;
};
