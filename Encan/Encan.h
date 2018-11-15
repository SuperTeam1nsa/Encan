#pragma once
class Encan
{
public:
	~Encan() {}
	Encan getInstance() 
	{ 
		if (instance == nullptr) 
		{
			*instance = Encan();
		}
		return *instance;
	}

private:
	int nbObjetsMax;

	Encan() {}
	Encan* instance;
};