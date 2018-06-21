#include "CPEOPLE.h"



CPEOPLE::CPEOPLE()
{
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
