#ifndef CPEOPLE_H_
#define CPEOPLE_H_
#include "MasterHeader.h"
#include "CVEHICLE.h"
#include "CANIMAL.h"

class CVEHICLE;
class CANIMAL;

class CPEOPLE final
{
	int _x, _y;
	bool _Dead;
	unsigned int _level;
public:
	CPEOPLE();

	void setCoord(int x, int y);

	void reset();
	void LevelUp();
	unsigned int& Level();
	void Up(int block = 1);
	void Left(int block = 1);
	void Right(int block = 1);
	void Down(int block = 1);
	bool isImpact(const CVEHICLE*);
	bool isImpact(const CANIMAL*);
	bool isFinish();
	bool isDead();

	void draw_self();
	void draw_dead_self();
	void draw_win_dance();
	void delete_self();

	explicit operator void*();
};

#endif CPEOPLE_H_


