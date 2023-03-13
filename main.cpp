#define OLC_PGE_APPLICATION
#include <iostream>

#include "olcPixelGameEngine.h"
#include "masspoint.hpp"
#include "spring.hpp"

class JELLY : public olc::PixelGameEngine
{
public:

	JELLY() {
		sAppName = "Jelly";
	}

	olc::vf2d pointPos = { 200.0, 200.0 };

	MassPoint* point = nullptr;

	olc::vf2d springPos1 = { 240.0, 260.0 };
	olc::vf2d springPos2 = { 270.0, 260.0 };
	olc::vf2d springPos3 = { 300.0, 260.0 };


	olc::vf2d springPos1 = { 240.0, 260.0 };
	olc::vf2d springPos2 = { 270.0, 260.0 };
	olc::vf2d springPos3 = { 300.0, 260.0 };


	bool OnUserCreate() override
	{
		point = new MassPoint(this, pointPos, 1.0, 1.0, 3.0);

		Spring *springs[4];

		springs[0] = new Spring(this, springPos1, 0.98, 8.0, 0.1, 0);
		springs[1] = new Spring(this, springPos2, 0.98, 8.0, 0.1, 1);
		springs[3] = new Spring(this, springPos3, 0.98, 8.0, 0.1, 2);

		void sprUpdate(*Spring) {
			for (int i = 0; i < 4; i++) {
				springs[i]->FINALupdate();
			}
		}
		return true;
	}

	bool OnUserUpdate(float deltaTime) override
	{
		Clear(olc::Pixel(80, 100, 180));

		//MassPoint& point = point;

		//double gravity = -9.8 * (double)point->mass;
		//point->force = gravity; //( * spring force)
		//point->velocity = (point->force / point->mass) * deltaTime;

		sprUpdate(&Spring);

		sprUpdate(&Spring);

		point->update(deltaTime);
		return true;
	}
};


int main()
{
	JELLY game;
	const int width = 1400;
	const int height = 950;
	const int pixelScale = 1;

	if (!game.Construct(width, height, pixelScale, pixelScale)) return EXIT_FAILURE;

	game.Start();

	return EXIT_SUCCESS;
}