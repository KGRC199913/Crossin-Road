#include "CPEOPLE.h"



CPEOPLE::CPEOPLE()
{
	_x = 0;
	_y = 0;
	_Dead = false;
	_level = 1;
}

void CPEOPLE::setCoord(int x, int y)
{
	_x = x;
	_y = y;
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
	if (_y - block > TOP_EDGE)
		_y -= block;
	else
		if (_y - block == TOP_EDGE) {
			FINISH_FLAG = true;
		}
}

void CPEOPLE::Left(int block)
{
	if (_x - block >= LEFT_EDGE)
		_x -= block;
	else; // pass
}

void CPEOPLE::Right(int block)
{
	if (_x + block <= RIGHT_EDGE)
		_x += block;
	else; // pass
}

void CPEOPLE::Down(int block)
{
	if (_y + block < LOW_EDGE)
		_y += block;
	else; // pass
}

bool CPEOPLE::isImpact(const CVEHICLE *& obj)
{
	auto equal = [](COORD lhs, COORD rhs) {
		return (lhs.X == rhs.X) && (lhs.Y == rhs.Y);
	};

	COORD hitboxP;
	hitboxP.X = _x;
	hitboxP.Y = _y;
	COORD hitboxP_head;
	hitboxP_head.X = _x;
	hitboxP_head.Y = _y + 1;

	COORD hitboxVec = obj->getCoord();
	COORD hitboxVec1 = hitboxVec;
	hitboxVec1.X += 1;
	COORD hitboxVec2 = hitboxVec;
	hitboxVec2.X += 2;

	if (equal(hitboxP, hitboxVec) || equal(hitboxP, hitboxVec1) || equal(hitboxP, hitboxVec2)) {
		return true;
	}
	if (equal(hitboxP_head, hitboxVec) || equal(hitboxP_head, hitboxVec1) || equal(hitboxP_head, hitboxVec2)) {
		return true;
	}
}

bool CPEOPLE::isImpact(const CANIMAL *& obj)
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
	GUI::gotoXY(_x, _y);
	std::cout << char(BOTTOM_HALF_BLOCK_ASCII);
	GUI::gotoXY(_x, _y + 1);
	std::cout << char(A_WITH_DIAERESIS);
}

void CPEOPLE::delete_self()
{
	GUI::gotoXY(_x, _y);
	std::cout << char(SPACE_ASCII);
	GUI::gotoXY(_x, _y + 1);
	std::cout << char(SPACE_ASCII);
}

CPEOPLE::operator void*()
{
	return reinterpret_cast<void*>(this);
}
