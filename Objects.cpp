#include "Objects.h"
Objects::Objects() {
}
Objects::~Objects() {
}

void Objects::CreateObject(olc::vf2d Position, std::string Name , float mass = 1.f, olc::Pixel Color = olc::WHITE) {
	Object NewObject;
	NewObject.Position = Position;
	NewObject.Mass = mass;
	NewObject.Color = Color;
	NewObject.Velocity = { 0.0, 0.0 };
	NewObject.Acceleration = { 0.0,0.0 };
	NewObject.size = 5.f;
	if (Name == "Circle") {
		NewObject.Shape = NewObject.Circle;
	}
	List_of_Objects.push_back(NewObject);
	Object_id += 1;
}