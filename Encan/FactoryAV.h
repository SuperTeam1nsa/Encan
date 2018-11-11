#pragma once

class FactoryAV
{
public:
	//ou en template aussi les acheteurs= NON #foncteurs et not need anyway
	static auto createAcheteurs();
	template <class T>
	static auto createVendeurs();
};
