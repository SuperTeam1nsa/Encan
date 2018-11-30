#include "pch.h"
#include "Encan.h"
#include "Acheteurs.h"
#include <mutex>
std::mutex mutex;
void Acheteurs::acheter() {
	std::lock_guard<std::mutex> lock(mutex);
	bool presente_un_interet = false;
	for (auto& i : (Encan::getInstance()).get()->getListeObjet())
	{
		presente_un_interet = interessant(*i);
		mef.getNewState(currentEtat, presente_un_interet);
		if (presente_un_interet)
			return;//end of fonction :p 
		//if ((*interessant)(object))//etc
	}
}
