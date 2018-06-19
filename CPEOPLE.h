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
	~CPEOPLE();

	void Up(int);
	void Left(int);
	void Right(int);
	void Down(int);
	bool isImpact(const CVEHICLE*&);
	bool isImpact(const CANIMAL*&);
	bool isFinish();
	bool isDead();
};

#endif CPEOPLE_H_


