#ifndef CANIMAL_H_
#define CANIMAL_H_
#include "MasterHeader.h"
#include "GUI.h"

class CANIMAL
{
protected:
	short _x, _y;
	short _type; // 0 = bird, 1 = dino;
	CANIMAL() = default;
public:
	int getType() const;

	void setCoord(int x, int y);
	void Move(int blockX);
	COORD getCoord() const;

	virtual void draw_self() = 0;
	virtual void draw_self_bw() = 0;
};

#endif CANIMAL_H_





