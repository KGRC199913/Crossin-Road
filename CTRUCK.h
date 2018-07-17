#ifndef CTRUCK_H_
#define CTRUCK_H_
#include "CVEHICLE.h"

class CTRUCK :
	public CVEHICLE
{
public:
	CTRUCK();

	void draw_self();
	void draw_self_bw();
};

#endif CTRUCK_H_


