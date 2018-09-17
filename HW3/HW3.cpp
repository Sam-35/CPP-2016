//******************************************************************* 
//                                                                    
//  Program:     Homework 3, Vowel & Whitespace counter.                                           
//                                                                     
//  Author:      Sam Abumoghli
//  Email:       sam@moghli.com
//                                                                    
//                                                                    
//  Description: This programs is designed to find and count the vowels and white-spaces in 
//				 the text entered by the user. The program stops inputting when the user uses "!".                  
//  Date:        02/16/2016
//                                                                    
//*******************************************************************

//Includes from the book and notes.
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

//Checks for vowels.
bool vowel_check(char ch) //Declares function of type bool
{
   if((ch == 'a' || ch == 'A')||(ch == 'e' || ch == 'E')||(ch == 'i' || ch == 'I')||(ch == 'o' || ch == 'O')||(ch == 'u'|| ch == 'U'))
   //Both small and capital variations of the letters will satisfy the condition.
   		return true;
   else
   		return false;  
}//Ends here

//Checks for white-spaces
bool whitespace_check(char ch) //Declares function of type bool
{
   if(ch == ' ') // Empty ' ' is a white-space.
   		return true;
   else
   		return false;  
}//Ends here


//Prints results
void print(int amount_vowels, int amount_whitespaces) //Declares function
{
	cout << "There are " << amount_vowels << " vowels in this text." << endl;
	cout << "There are "<< amount_whitespaces << " whitespaces in this text." << endl;
}//Ends here


//Main function starts below.
//Functions declares perviously are called in the main function.
int main()
{ //1 // Nesting statements
	while(true)
	{//2
		int vowels = 0; //variable vowels declared as type int
		int whitespaces = 0; //variable whitespaces declared as type int
		char ch; // ch declares as type char.
  
		cout << "Enter lines of characters terminated by !" << endl; //Prompting user for input.
  
		while(true)
  		{//3 
			cin.get(ch);
			
			if(ch == '!')
				break; //Stops when user enters the char '!' 
      
      		else
				{//4
         		 	if(vowel_check(ch)) 
         		  		vowels ++;
           

					else if(whitespace_check(ch)) 
						whitespaces ++;  
				}//4 
	
  		}//3

		print(vowels, whitespaces);   //Calls function print
    	cout << "Continue (y/n)?" << endl;  //Prompts user for answer
   	 	
   	 	char user_answer; //Declared user_answer as type char
   		cin >> user_answer;
     
  		if(user_answer == 'y' || user_answer == 'Y') // small or capital y
    		continue; //If user selects yes then they will be prompted to enter a sentence again
   		else if(user_answer == 'n' || user_answer == 'N') //small or capital n
    		break;  //If user selects no the program quits
 	}//2
 
 return 0;
 
}//1  //Main function ends here

//Tried fixing the indentation as previously noted on Blackboard


  
