#ifndef CVEHICLE_H_
#define CVEHICLE_H_

class CVEHICLE
{
	int _x, _y;
public:
	CVEHICLE() = default;
	
	void Move(int blockX, int blockY);

	virtual void draw_self() {};
	virtual void delete_self() {};
};


#endif CVEHICLE_H_

