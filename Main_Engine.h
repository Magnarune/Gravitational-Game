#pragma once
#include "olcPixelGameEngine.h"
#include "olcPGEX_TransformedView.h"
#include "Draw.h"
#include "Object.h"
#include "Objects.h"
#include "Gravitation_Calculator.h"
#include <assert.h>

class Gravity : public olc::PixelGameEngine
{
public:
	olc::TileTransformedView tv;
	static Gravity* self;
	Gravity(const Gravity&) = delete;
	Gravity& operator=(const Gravity&) = delete;
	static inline Gravity& Current() { assert(self != nullptr); return *self; }
	Gravity();
	virtual ~Gravity();
	olc::vf2d Camera = {0.f,0.f};
	Objects* Object_Manager;
	Draws* Draw_Manager;
	Gravitation_Calculator* Gravity_Manager;
	
public:

	bool OnUserCreate() override;

	bool OnUserUpdate(float fElapsedTime) override;
};
