//******************************************************************* 
//                                                                    
//  Program:     Homework 1, Invoice.                                            
//                                                                     
//  Author:      Sam Abumoghli
//  Email:       sam@moghli.com
//                                                                    
//                                                                    
//  Description: Invoice generator for an electronics store, that calculates                 
//  final price after discounts and taxes.                                                               
//  Date:        01/30/2016
//                                                                    
//*******************************************************************


#include <iostream>
using namespace std;
int main()
{

//Set output to 2 decimal places (from notebook)
cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(2);
//Done.


//Variables below
string first_name, last_name; //First and last name of customer
int number_of_items;  //Number of items is always a whole number
double item_price, original_price, discount, final_price, discount_value, tax_value, price_after_tax; //Variables
const double taxes = 0.065; //Declaring taxes to 6.5% or 0.065. Taxes declared as a constant double
//All variables are declared


//Input and instructions below
cout << "Warning: Hit 'RETURN' after each entry \n";
cout << "Enter first and last name:  \n";
cin >> first_name;
cin >> last_name;
cout << "Enter number of items:\n";
cin >> number_of_items;
cout << "Enter item price: \n";
cin >> item_price;
cout << "Enter discount %, if any: \n";
cin >> discount;  
//Input ends here


//Calculations below
original_price = number_of_items * item_price; //Total price of items before discounts and taxes
discount_value = original_price * (discount / 100); // Finds discount value 
final_price = original_price - discount_value; //Final price with discount but before taxes
tax_value = final_price * taxes;  //Calculates taxes
price_after_tax = final_price - tax_value; // Final price after discount and taxes
//Calculations end here


//Output below
cout << "_____________________________________ \n";
cout << "Customer Name:		" << first_name << " " << last_name << endl;
cout << "Item Price:		$" << item_price << "\n";
cout << "Quantity:  		#" << number_of_items << "\n";
cout << "Discount:		%" << discount << endl;
cout << "Original Price:         $" << original_price << endl;
cout << "Discount Amount:        $" << discount_value << endl;	
cout << "====================================== \n";
cout << "Subtotal:               $" << final_price << endl;
cout << "Taxes:                  $" << tax_value << endl;
cout << "Total Due:              $" << price_after_tax << endl;
cout << "====================================== \n";
cout << "Thank you! Have a great day!" << endl;
//Output ends here


return 0;
}
