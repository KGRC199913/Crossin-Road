#include "CPEOPLE.h"

bool FINISH_FLAG;

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
	COORD objCoord = obj->getCoord();
	if (_y == objCoord.Y) {
		if ((_x >= objCoord.X) && (_x <= (objCoord.X + 2))) {
			_Dead = true;
			return true;
		}
	}
	return false;
}

bool CPEOPLE::isImpact(const CANIMAL *& obj)
{
	COORD objCoord = obj->getCoord();

	if (obj->getType() == 0) {
		if (_y == objCoord.Y) {
			if ((_x >= objCoord.X) && (_x <= (objCoord.X + 2))) {
				_Dead = true;
				return true;
			}
		}
		return false;
	}

	if ((_y == objCoord.Y) || _y == (objCoord.Y - 1)) {
		if ((_x >= objCoord.X) && (_x <= (objCoord.X + 3))) {
			_Dead = true;
			return true;
		}
	}
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
