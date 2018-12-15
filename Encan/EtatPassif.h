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

	virtual ~EtatPassif()
	{
	};
private:
	int id;
};
