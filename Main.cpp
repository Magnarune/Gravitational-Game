#define OLC_PGE_APPLICATION
#define OLC_PGEX_TRANSFORMEDVIEW
#include "Main_Engine.h"

int main()
{//1024, 960 , 1 ,1 // 512, 480, 2, 2 //256 , 240 , 4 ,4

	Gravity demo;
	if (demo.Construct(256, 240, 4, 4))
		demo.Start();

	return 0;
}