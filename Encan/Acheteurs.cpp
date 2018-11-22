#include "pch.h"
#include "Encan.h"
#include "Acheteurs.h"
#include <mutex>
std::mutex mutex;
void Acheteurs::acheter() {
	std::lock_guard<std::mutex> lock(mutex);
	for (auto& i : (Encan::getInstance()).get()->getListeObjet())
		if (interessant(*i))
			return;//end of fonction :p 
		//if ((*interessant)(object))//etc
}
