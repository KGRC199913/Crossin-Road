#ifndef CDINOSAUR_H_
#define CDINOSAUR_H_
#include "CANIMAL.h"

class CDINOSAUR :
	public CANIMAL
{
public:
	CDINOSAUR();

	void draw_self();
	void draw_self_bw();
	void delete_self();
};

#endif CDINOSAUR_H_



