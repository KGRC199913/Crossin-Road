#ifndef CCAR_H_
#define CCAR_H_
#include "CVEHICLE.h"

class CCAR :
	public CVEHICLE
{
public:
	CCAR();

	void draw_self();
	void draw_self_bw();
	void delete_self();
};

#endif CCAR_H_



