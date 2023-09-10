#include "Main_Engine.h"

Gravity* Gravity::self = nullptr;
Gravity::Gravity() {
	sAppName = "Simple PGE RTS GAME";
	self = this;
}
Gravity::~Gravity() {
	self = nullptr;
}

bool Gravity::OnUserCreate() {
	{
		tv = olc::TileTransformedView({ ScreenWidth(),ScreenHeight() }, { 4,4 });
		tv.SetWorldOffset(Camera);
		Object_Manager = new Objects();
		Draw_Manager = new Draws();
		Gravity_Manager = new Gravitation_Calculator();
		Object_Manager->CreateObject({ 150,150 }, "Circle" , 500.f, olc::RED);
		return true;
	}
}

bool Gravity::OnUserUpdate(float dt) {
	tv.SetWorldOffset(Camera);
	Clear(olc::BLACK);
	olc::vf2d CenterofScreen = tv.ScaleToWorld(olc::vf2d(float(ScreenWidth()) / 2.0f, float(ScreenHeight()) / 2.0f));
	if (GetMouse(0).bPressed) {
		Object_Manager->CreateObject(tv.ScreenToWorld(GetMousePos()), "Circle", 100.f, olc::WHITE);
	}
	
	Gravity_Manager->Calcuate_Gravity(dt);
	Gravity_Manager->Update_Positions(dt);
	Draw_Manager->DrawObjects();
	


	if (GetMouse(2).bPressed) tv.StartPan(GetMousePos());
	if (GetMouse(2).bHeld) tv.UpdatePan(GetMousePos());
	if (GetMouse(2).bReleased) tv.EndPan(GetMousePos());
	if (GetMouseWheel() > 0) tv.ZoomAtScreenPos(2.0f, GetMousePos());
	if (GetMouseWheel() < 0) tv.ZoomAtScreenPos(0.5f, GetMousePos());
	Camera = tv.GetWorldOffset();



	return true;
}