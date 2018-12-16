#pragma once
class EtatPassif : public Etat
{
public:
	explicit EtatPassif(int id) { this->id = id; };
	float probabiliteAchat() override { return 0; };

	int getEtatId() override
	{
		return id;
	}
	std::string description() override { return "Etat Passif"; }
	virtual ~EtatPassif()
	{
	};
private:
	int id;
};
