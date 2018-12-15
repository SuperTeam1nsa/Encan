#pragma once
class EtatNormal : virtual public Etat
{
public:
	explicit EtatNormal(int id) { this->id = id; }
	float probabiliteAchat() override { return 0.8f; }

	int getEtatId() override
	{
		return id;
	}

	virtual ~EtatNormal()
	{
	}

private:
	int id;
};
