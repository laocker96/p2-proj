#pragma once
#include "strumento.h"

class Fiato: virtual public Strumento{

protected:
	enum Material {silver, brass, plastic};
	enum Mouthpiece {woodwind_mouthpiece, brass_mouthpiece};
	Material material;
	Tune instrumentTune;
	Mouthpiece mouthpiece;
	
public:
	Fiato(Material, Strumento::Tune, Mouthpiece,  double, const std::string&, bool = false);
	Strumento::Tune tune() const;
};
