#ifndef CTRUCK_H_
#define CTRUCK_H_
#include "CVEHICLE.h"

class CTRUCK :
	public CVEHICLE
{
public:
	CTRUCK();
	~CTRUCK();

	void draw_self() {};
	void delete_self() {};
};

#endif CTRUCK_H_


