#ifndef CCAR_H_
#define CCAR_H_
#include "CVEHICLE.h"

class CCAR :
	public CVEHICLE
{
public:
	CCAR() = default;

	void draw_self();
	void delete_self();
};

#endif CCAR_H_



