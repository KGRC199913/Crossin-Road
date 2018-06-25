#ifndef CANIMAL_H_
#define CANIMAL_H_
#include "MasterHeader.h"
#include "GUI.h"

class CANIMAL
{
protected:
	int _x, _y;
public:
	CANIMAL() = default;

	void setCoord(int x, int y);
	void Move(int blockX, int blockY);
	virtual void Tell() {};
	virtual void draw_self() {};
	virtual void delete_self() {};
};

#endif CANIMAL_H_





