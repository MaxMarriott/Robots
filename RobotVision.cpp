=0oo//#include required things
#include <iostream>
#include <GripPipeline.cpp>
#include <GripPipeline.h>

//all referances to the white object in the input will be refered to as simply "Object", for simplicity's sake

void main()
{
	int DummyTurnLeft = 0; //Simulates turning left

	int DummyTurnRight = 0; //Simulates turning right

	int DummyDriveForwards = 0; //Simulates driving forward

	bool DummyLaserSensor; //Simulates the successful pickup of a block
	
	int ObjectMinPrev = 0; //creates a copy of the max of Y from the previous frame

	findObjectCentre();
} //Declares variables for the program.

void findObjectCentre()
{
	//DECLERATIONS + FINDING WHITE IN INPUT IMAGE!!!
		int ObjectMinX = 0;
		ObjectMinX(0);

		int ObjectMaxX = 0;

		objectMaxX(0);

		int ObjectMinY = 0;

		ObjectMinY(0);

		int ObjectMaxY = 0;

		objectMaxY(0);

		//int ObjectMaxY = First white pixel with the highest Y value

		//IMPORTANT IF NO PIXEL IS FOUND THE VALUE WILL REMAIN AT 0

		int ObjectCentre[2]; //ObjectCentre[0] = x value, ObjectCentre[1] = y value


		//Bool IsObjectPresent = true; //True if there are no white pixels from the input.

		If ((ObjectMaxX = 0) || (ObjectMaxY = 0))		{
			FindObjectCentre();
		}
		else
		{
			//CENTRE OF Object FOUND

				ObjectCentre[0] = (ObjectMaxX + ObjectMinX) / 2; //X value calculated

				ObjectCentre[1] = (ObjectMaxY + ObjectMinY) / 2; //Y value calculated

				//NON IMPORTANT THINGS HERE
					std::cout << "X value of the centre: " << ObjectCentre[0] << std::endl;

					std::cout << "Y value of the centre: " << ObjectCentre[1] << std::endl; //too see if program has run

				//Switch to driving phase

					steerToObject();
		}
}

void steerToObject()
{
	While(int ObjectCentre[0] > 75) //moves left until approximately at the centre
	{
		DummyTurnLeft = 1;

		FindObjectCentre();
	}

	DummyTurnLeft = 0; //stops turning left

	While(ObjectCentre[0] < 65) //moves right until approximately at the centre
	{
		DummyTurnRight = 1;

		FindObjectCentre();	}

	DummyTurnRight = 0; //Stops turning right

	if ((ObjectCentre[0] > 75) || (ObjectCentre[0] < 65))			//to ensure the robot did not drive to far to the right or left!
	{
		FindObjectCentre();
	}
	else
	{
		PickUpObject();
	}
}

void pickUpObject()
{

	ObjectMinYPrev = ObjectMinY; //creates a copy of the max of Y from the previous frame
	while ((ObjectMinY > 10) && (ObjectminYPrev > 10))
	{
		ObjectMinYPrev = ObjectMinY;
		DummyDriveForwards = 1;

	}

	Ready; //Pickup

	while (DummyLaserSensor == false)
	{
		DummyDriveForwards = 0;
		std::sleep_for(50); //sleep for 50 ms
		DummyDriveForwards = 1;
	}
	DummyDriveForwards = 0;
	cout << "It has finished" << endl;
}



//FUNCTIONS FINDING THE OBJECT'S MIN and Max Values
int findObjectMinX (int ObjectMinX)
{
	//int ObjectMinX = First white pixel with the lowest X value
}



int findObjectMaxX (int ObjectMaxX)
{
	//int ObjectMaxX = First white pixel with the highest X value
}


int findObjectMinY (int ObjectMinY)
{
	//int ObjectMinY = First white pixel with the lowest Y value
}


int findObjectMaxY (int ObjectMaxY)
{
	//int ObjectMaxY = First white pixel with the highest Y value
}
