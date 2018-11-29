#pragma once
class EtatAgressif :public virtual Etat
{
public:
	EtatAgressif(int id) { this->id = id; };
	float probabilite_achat() { return 1.0; };
	int getEtatID() {
		return id;
	}
	virtual ~EtatAgressif() {};
private:
	int id;

};
