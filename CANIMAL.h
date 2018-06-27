#ifndef CANIMAL_H_
#define CANIMAL_H_
#include "MasterHeader.h"
#include "GUI.h"

class CANIMAL
{
protected:
	int _x, _y;
	int _type; // 0 = bird, 1 = dino;
public:
	CANIMAL() = default;

	int getType() const;

	void setCoord(int x, int y);
	void Move(int blockX);
	COORD getCoord() const;

	virtual void Tell() {};
	virtual void draw_self() = 0;
	virtual void delete_self() = 0;
};

#endif CANIMAL_H_





