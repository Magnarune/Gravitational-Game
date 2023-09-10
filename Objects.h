#pragma once
#include "olcPixelGameEngine.h"
#include "Object.h" 
class Objects
{
public:
	Objects();
	~Objects();
	int Object_id = 0;

	std::vector<Object> List_of_Objects;


	void CreateObject(olc::vf2d Position, std::string Name, float Mass, olc::Pixel Color);
	void DestroyObject(std::string Name);




};

