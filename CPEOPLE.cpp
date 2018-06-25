#include "CPEOPLE.h"



CPEOPLE::CPEOPLE()
{
	_x = 0;
	_y = 0;
	_Dead = false;
	_level = 1;
}

void CPEOPLE::reset()
{
	_x = 0;
	_y = 0;
	_Dead = false;
	_level = 1;
}

void CPEOPLE::LevelUp()
{
	++_level;
}

unsigned int & CPEOPLE::Level()
{
	return _level;
}

void CPEOPLE::Up(int block)
{
	_y += block;
}

void CPEOPLE::Left(int block)
{
	_x -= block;
}

void CPEOPLE::Right(int block)
{
	_x += block;
}

void CPEOPLE::Down(int block)
{
	_y -= block;
}

bool CPEOPLE::isImpact(const CVEHICLE *&)
{
	return false;
}

bool CPEOPLE::isImpact(const CANIMAL *&)
{
	return false;
}

bool CPEOPLE::isFinish()
{
	return false;
}

bool CPEOPLE::isDead()
{
	return false;
}

void CPEOPLE::draw_self()
{
}

void CPEOPLE::delete_self()
{
}

CPEOPLE::operator void*()
{
	return reinterpret_cast<void*>(this);
}
