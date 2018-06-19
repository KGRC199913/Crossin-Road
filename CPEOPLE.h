#ifndef CPEOPLE_H_
#define CPEOPLE_H_
#include "MasterHeader.h"
#include "CANIMAL.h"
#include "CVEHICLE.h"

class CPEOPLE
{
	int _x, _y;
	bool _Dead;
public:
	CPEOPLE();

	void Up(int block = 1);
	void Left(int block = 1);
	void Right(int block = 1);
	void Down(int block = 1);
	bool isImpact(const CVEHICLE*&);
	bool isImpact(const CANIMAL*&);
	bool isFinish();
	bool isDead();
};

#endif CPEOPLE_H_


