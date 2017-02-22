#pragma once
#include "Actor.h"

class Player :
	public CActor
{
public:
	Player();
	Player(DblBuffer*, FPSMgr2*, InputMgr*);
	~Player();
	
	void move();
	void draw();
};

