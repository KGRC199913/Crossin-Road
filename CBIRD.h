#ifndef CBIRD_H_
#define CBIRD_H_
#include "CANIMAL.h"

class CBIRD :
	public CANIMAL
{
public:
	CBIRD();

	void draw_self();
	void delete_self();
	void draw_self_bw();
	void delete_self_bw();
};


#endif CBIRD_H_

