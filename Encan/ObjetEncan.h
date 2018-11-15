#pragma once
enum Description
{
	ART, ANTIQUITE, SERVICE
};
template <class T>
class ObjetEncan
{
public:
	ObjetEncan(T* obj) { objet = obj; };
	~ObjetEncan() {};
	T* getObjet() { return objet; }
private:
	T* objet; //art, antiquite, services etc

};
