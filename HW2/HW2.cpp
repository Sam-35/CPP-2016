//******************************************************************* 
//                                                                    
//  Program:     Homework 2,                                            
//                                                                     
//  Author:      Sam Abumoghli
//  Email:       sam@moghli.com
//                                                                    
//                                                                    
//  Description: This program determines whether a point is located on the Origin, x-axis, y-axis
//               or if its located in one of the four Quadrants on a graph (I, II, III, IV).
//               It also find the distance between the points entered by the user and the Origin.                  
//  Date:        02/10/2016
//                                                                    
//*******************************************************************

//Includes from the book and notes.
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;
int main()
{
	//Shifted after main function as noted on Blackboard from previous assignment. 
	//Set output to 1 decimal places (from notebook)
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(1);
	
	//Initializing Variables 
	double pointX, pointY, distance_origin; //Points X and Y, distance from origin
	char user_choice; // Initialized as character (Y or N)
	
	
	//Do-While loop begins below.
	do 
	{
		cout << "Enter a point (Values for X and Y)" << endl; //Prompting user to enter the variables X and Y
		cin >> pointX >> pointY; //Inputting point X and point Y as separate variables.
		
		// 1
		if (pointX == 0)
		{
			if (pointY == 0)
			 cout << "The point is on the Origin" << endl;
			 else
			 cout << " The point is on the y-axis" << endl;
		}
		// 2 
		else if (pointX > 0)
		{
			if (pointY == 0)
			cout << "The point is on the x-axis" << endl;
			else if (pointY > 0)
			cout << "Point is in quadrant I" << " (" << pointX << "," << pointY << ")" << endl;
			else
			cout << "Point is in quadrant IV" << " (" << pointX << "," << pointY << ")" << endl;
		}
		// 3
		else 
		{
			if (pointY == 0)
			cout << "The point is on the x-axis" << endl;
			else if (pointY > 0)
			cout << "Point is in quadrant II" << " (" << pointX << "," << pointY << ")" << endl;
			else
			cout << "Point is in quadrant III" << " (" << pointX << "," << pointY << ")" << endl;
		}
	
	//Identifying the location of X and Y points ends here.
	cout.precision(3); //Changing output to 3 decimal places from now on as requested.
	
	//Calculating distance from the origin (0,0) using the Pythagorean Formula 
	distance_origin = sqrt(pointX * pointX + pointY * pointY); //Using math function sqrt  
	//by including the math lib <cmath>
	
	cout << "Distance from the Origin (0,0) is:  " << distance_origin << endl;
		
	cout << "Continue (y/n)?" << endl; //Asking the user wehther they want to continue or terminiate the prog.
	cin >> user_choice; //User inputs choice 
	if (user_choice == 'n')//Used '' because user_choice is initialized as char 
		{
		cout << "Have a good day!" << endl;
		break;} //Loop breaks if user inputs 'n' 

		}
	while(true);
	
	
return 0;
}
