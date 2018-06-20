#ifndef CANIMAL_H_
#define CANIMAL_H_

class CANIMAL
{
	int _x, _y;
public:
	CANIMAL();

	void Move(int blockX, int blockY);
	int Tell();
	virtual void draw_self() = 0;
	virtual void delete_self() = 0;
};

#endif CANIMAL_H_





