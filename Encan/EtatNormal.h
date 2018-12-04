#pragma once
class EtatNormal :public virtual Etat
{
public:
	EtatNormal(int id) { this->id = id; }
	float probabilite_achat() { return 0.8f; }
	int getEtatID() {
		return id;
	}
	virtual ~EtatNormal() {}
private:
	int id;

};
