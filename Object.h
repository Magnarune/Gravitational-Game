#pragma once
#include "olcPixelGameEngine.h"
class Object
{
public:
	Object();
	~Object();
	bool deathflag;
	float Mass=10;
	olc::vf2d Position;
	olc::vf2d Velocity;
	olc::vf2d Acceleration;
	float size;
	olc::Pixel Color;
	enum {
		Circle,
		Square,
		Ship
	}Shape;
};

