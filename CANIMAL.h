#ifndef CANIMAL_H_
#define CANIMAL_H_

class CANIMAL
{
	int _x, _y;
public:
	CANIMAL() = default;

	void Move(int blockX, int blockY);
	int Tell();
	virtual void draw_self() {};
	virtual void delete_self() {};
};

#endif CANIMAL_H_





