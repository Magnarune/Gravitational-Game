#include "Gravitation_Calculator.h"
#include "Main_Engine.h"
Gravitation_Calculator::Gravitation_Calculator() {}
Gravitation_Calculator::~Gravitation_Calculator() {}

void Gravitation_Calculator::Calcuate_Gravity(float dt) {
	auto& engine = Gravity::Current();

	for (int i = 0; i < engine.Object_Manager->List_of_Objects.size(); i++)
	{		
		auto& object = engine.Object_Manager->List_of_Objects[i];
		if (object.deathflag == true)
		{
			engine.Object_Manager->List_of_Objects.erase(engine.Object_Manager->List_of_Objects.begin() + i);
			break;
		}
		bool Boom = false;
		for (int j = 0; j < engine.Object_Manager->List_of_Objects.size(); j++)
		{
			if (i != j) {

				auto& other = engine.Object_Manager->List_of_Objects[j];
				if (other.deathflag == true)
				{
					engine.Object_Manager->List_of_Objects.erase(engine.Object_Manager->List_of_Objects.begin() + j);
					break;
				}
				olc::vf2d distance = Object_distanceXY(object, other);

				float R = distance.x * distance.x + distance.y * distance.y;
				if (R >= (object.size + object.Mass)) {
					object.Acceleration.x -= Gravitational_Constant * other.Mass * distance.x / R;
					object.Acceleration.y -= Gravitational_Constant * other.Mass * distance.y / R;
					object.Velocity.x += object.Acceleration.x * dt;
					object.Velocity.y += object.Acceleration.y * dt;
				}
				else
				{
					if (object.Mass >= other.Mass) {
						object.Mass += other.Mass;
						other.deathflag = true;
					}
				}


			}
		}
	}

}





void Gravitation_Calculator::Update_Positions(float dt) {
	auto& engine = Gravity::Current();
	for (int i = 0; i < engine.Object_Manager->List_of_Objects.size(); i++)
	{
		engine.Object_Manager->List_of_Objects[i].Position.x += engine.Object_Manager->List_of_Objects[i].Velocity.x * dt;
		engine.Object_Manager->List_of_Objects[i].Position.y += engine.Object_Manager->List_of_Objects[i].Velocity.y * dt;
	}
}

olc::vf2d Gravitation_Calculator::Object_distanceXY(Object A, Object B) {//Ax-Bx
	olc::vf2d Distance;
	Distance.x = A.Position.x - B.Position.x;
	Distance.y = A.Position.y - B.Position.y;
	return Distance;
}
