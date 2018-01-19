//VISION PROTOTYPE/SKELETON
//####################################

//#include required include statements
#include <iostream>
//#include <GripPipeline.cpp>
//#include <GripPipeline.h>

//all referances to the white object in the input will be refered to as simply "Object", for simplicity's sake
//GLOBAL DECLERATIONS
//########################################################################################
int dummy_turn_left = 0; //Simulates turning left

int dummy_turn_right = 0; //Simulates turning right

int dummy_drive_forwards = 0; //Simulates driving forward

bool dummy_laser_sensor = false; //Simulates the successful pickup of a block

int object_y_min_prev = 0; //creates a copy of the max of Y from the previous frame

int object_centre[2] = { 0, 0 }; //object_centre[0] = x value, objectcentre[1] = y value

int object_min_x = 0; //the 0 in this decleration represents how many rows UP the FIRST white pixel is! 

int object_max_x = 0; //the 0 in this decleration represents how many rows UP the LAST white pixel is! 

int object_min_y = 0; //the 0 in this decleration represents how many Columns (from left to right) the first white pixel is! 

int object_max_y = 0; //the 0 in this decleration represents how many Columns (from left to right) the last white pixel is! 

void FindObjectCentre()
{
	//DECLERATIONS + FINDING WHITE IN INPUT IMAGE!!!
	object_min_x = 0;
		FindObjectMinX();

	object_max_x = 0;
		FindObjectMaxX();

	object_min_y = 0;
		FindObjectMinY();

	object_max_y = 0;
		FindObjectMaxY();

	//int object_max_y = First white pixel with the highest Y value

	//IMPORTANT IF NO PIXEL IS FOUND THE VALUE WILL REMAIN AT 0


	//Bool IsObjectPresent = true; //True if there are no white pixels from the input.

	if((object_max_x = 0) || (object_max_y = 0)) 
	{
		//this will trigger if there are no white pixels
		FindObjectCentre();
	}
		else
		{
			//CENTRE OF Object FOUND

			object_centre[0] = (object_max_x + object_min_x) / 2; //X value calculated

			object_centre[1] = (object_max_y + object_min_y) / 2; //Y value calculated

															 //NON IMPORTANT THINGS HERE
			std::cout << "X value of the centre: " << object_centre[0] << std::endl;

			std::cout << "Y value of the centre: " << object_centre[1] << std::endl; //too see if program has run

																					//Switch to driving phase

			SteerToObject();
		}
}

void SteerToObject()
{
	while (object_centre[0] > 75) //moves left until approximately at the centre
	{
		dummy_turn_left = 1;

		FindObjectCentre();
	}

	dummy_turn_left = 0; //stops turning left

	while (object_centre[0] < 65) //moves right until approximately at the centre
	{
		dummy_turn_right = 1;

		FindObjectCentre();
	}

	dummy_turn_right = 0; //Stops turning right

	if ((object_centre[0] > 75) || (object_centre[0] < 65))			//to ensure the robot did not drive to far to the right or left!
	{
		FindObjectCentre();
	}
	else
	{
		PickUpObject();
	}
}

void PickUpObject()
{
	//The ROBOT LOWERS ITS FORKS TO PICK UP CUBE AND TRAVELS TO PICK THE BLOCK UP
	object_y_min_prev = object_min_y; //creates a copy of the max of Y from the previous frame
	while ((object_min_y > 10) && (object_y_min_prev > 10))
	{
		object_y_min_prev = object_min_y;
		dummy_drive_forwards = 1; 
		//Turning the motor on and off is just an digital example representing the analog process of slowing down the robot! 
		FindObjectMinX(); //checks where the lowest pixel of white is.
	}

 //At this point the block SHOULD be almost in the loading bay, this while statement while jiggle the block into place 

	while (dummy_laser_sensor == false)
	{
		dummy_drive_forwards = 0;
		//This is a very archaeic way of loading the block into the fork's rollers, we will find a better way  
		dummy_drive_forwards = 1;
	}
	dummy_drive_forwards = 0;
	std::cout << "It has finished" << std::endl;
}


//IMPORTANT IDEA
//===================
//USING THE PIGEON WE SHOULD BE ABLE TO CALCULATE WHERE WE HAVE TRAVELED TO PICK UP THE BLOCK
//AND THEREFORE BACKTRACK WHERE WE HAD BEEN UNTIL WE SEE ANOTHER BLOCK AND THEREFORE WE CAN 
//USE THIS SCRIPT AGAIN!


//FUNCTIONS FINDING THE OBJECT'S MIN AND MAX VALUES
void FindObjectMinX()
{
	//int ObjectMinX = First white pixel with the lowest X value
}



void FindObjectMaxX()
{
	//int ObjectMaxX = First white pixel with the highest X value
}


void FindObjectMinY()
{
	//int ObjectMinY = First white pixel with the lowest Y value
}


void FindObjectMaxY()
{
	//int ObjectMaxY = First white pixel with the highest Y value
}



void main() //main
{
	FindObjectCentre();

}
