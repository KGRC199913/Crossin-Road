#ifndef CVEHICLE_H_
#define CVEHICLE_H_
#include "MasterHeader.h"
#include "GUI.h"

class CVEHICLE
{
protected:
	int _x, _y;
public:
	CVEHICLE() = default;

	void setCoord(int x, int y);
	void Move(int blockX, int blockY);

	virtual void draw_self() {};
	virtual void delete_self() {};
};


#endif CVEHICLE_H_

