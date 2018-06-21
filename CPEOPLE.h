#ifndef CPEOPLE_H_
#define CPEOPLE_H_
#include "MasterHeader.h"
#include "CVEHICLE.h"
#include "CANIMAL.h"

class CPEOPLE final
{
	int _x, _y;
	bool _Dead;
	unsigned int _level;
public:
	CPEOPLE();
	unsigned int& Level();
	void Up(int block = 1);
	void Left(int block = 1);
	void Right(int block = 1);
	void Down(int block = 1);
	bool isImpact(const CVEHICLE*&);
	bool isImpact(const CANIMAL*&);
	bool isFinish();
	bool isDead();

	void draw_self();
	void delete_self();

	explicit operator void*();
};

#endif CPEOPLE_H_

