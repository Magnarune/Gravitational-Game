#pragma once
#include "olcPixelGameEngine.h"
#include "Objects.h"

class Gravitation_Calculator
{
public:
	Gravitation_Calculator();
	~Gravitation_Calculator();
	void Calcuate_Gravity(float dt);
	olc::vf2d Object_distanceXY(Object A, Object B);
	void Update_Positions(float dt);
	
	void Galactic_Merger();



	float Gravitational_Constant = 0.5;
	
};

