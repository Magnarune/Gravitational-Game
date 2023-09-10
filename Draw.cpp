#include "Draw.h"
#include "Main_Engine.h"
Draws::Draws() {}
Draws::~Draws() {}


void Draws::DrawObjects()
{
	auto& Main = Gravity::Current();	
	for (int i = 0; i < Main.Object_Manager->List_of_Objects.size(); i++)
	{
			auto& object = Main.Object_Manager->List_of_Objects[i];
		if (Main.Object_Manager->List_of_Objects[i].Shape == 0)
		{

			Main.tv.DrawCircle(object.Position, object.size + object.Mass * 0.01, object.Color);

		}


		Main.DrawString({ 0, i * 10 }, std::to_string(object.Velocity.x), olc::BLUE, 1);
		
		Main.DrawString({ 70, i * 10 }, std::to_string(object.Acceleration.x), olc::RED, 1);
		object.Acceleration = { 0.f,0.f };
	}


}
