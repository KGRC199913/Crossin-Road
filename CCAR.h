#ifndef CCAR_H_
#define CCAR_H_
#include "CVEHICLE.h"

class CCAR :
	public CVEHICLE
{
public:
	CCAR();

	void draw_self();
	void delete_self();
	void draw_self_bw();
	void delete_self_bw();
};

#endif CCAR_H_



