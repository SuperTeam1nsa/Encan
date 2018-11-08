#pragma once
#include <string>
#include "Antiquite.h"
#include "Art.h"
#include "Service.h"

class FactoryObjetEncan
{
public:
	FactoryObjetEncan();
	~FactoryObjetEncan();

    static Antiquite createAntiquite();
    
    static Art createArt();
    
    static Service createService();
};

