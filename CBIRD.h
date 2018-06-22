#ifndef CBIRD_H_
#define CBIRD_H_
#include "CANIMAL.h"

class CBIRD :
	public CANIMAL
{
public:
	CBIRD() = default;

	void draw_self();
	void delete_self();
};


#endif CBIRD_H_

