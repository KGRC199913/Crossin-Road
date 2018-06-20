#ifndef CVEHICLE_H_
#define CVEHICLE_H_

class CVEHICLE
{
	int _x, _y;
public:
	CVEHICLE();
	
	void Move(int blockX, int blockY);

	virtual void draw_self() = 0;
	virtual void delete_self() = 0;
};


#endif CVEHICLE_H_

