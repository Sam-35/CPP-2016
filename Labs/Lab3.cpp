//******************************************************************* 
//                                                                    
//  Program:     Lab 3, Wages.                                            
//                                                                     
//  Author:      Sam Abumoghli
//  Email:       sam@moghli.com
//                                                                    
//                                                                    
//  Description: Determines which wage plan is better based on the amount of weekly sales.                                                            
//  Date:        02/06/2016
//                                                                    
//*******************************************************************

#include <iostream>
#include <cstdlib>

using namespace std;
int main()
{
//Output to 2 decimal places
cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(2);

double weekly_sales, plan1, plan2, com_a_final, com_b_final;
const double COMMISSION_A = .10, COMMISSION_B = .15, HOURLY_RATE = 5.50;

//Input and output
cout << "Enter the weekly sales amount; " << endl;
cin >> weekly_sales;

//Calculations Plan A
com_a_final = weekly_sales * COMMISSION_A;
plan1 = HOURLY_RATE * 40 + com_a_final;

//Calculations Plan B
com_b_final = weekly_sales * COMMISSION_B;
plan2 = com_b_final;


cout << "Amount of sales:  $"  << weekly_sales << endl;
cout << "Wage Plan A:	  $" << plan1 << endl;
cout << "Wage Plan B:      $" << plan2 << endl;

if (plan2 > plan1)
	{
	cout << "Plan 2 is better!" << endl;
	}
	else
	{
	cout << "Plan 1 is better!" << endl;
	}
	
	
return 0;
}
