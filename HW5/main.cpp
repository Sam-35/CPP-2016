//*******************************************************************
//
//  Program:     Homework 5 Count Violations.
//
//  Author:      Sam Abumoghli
//  Email:       sam@moghli.com
//
//
//  Description: The program reads license plate numbers from a file picked by the user and outputs the number of violations if any
//               for that specific license pate number. The number of violations is based on how many times the license plate number
//               repeats in the file.
//  Date:         03/15/2016
//
//*******************************************************************

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;


//Function: inputFileNames
//Prompts the user for the name of the input file and opens it.
//input file is called by reference so that it can be used in main
void inputFileName(ifstream& fileIN);

//Function: readFile
//The function reads the integer values from the file opened the function: inputFieName and stores them in the array
//The function keeps reading the integers until the end of the file.
int readFile(ifstream& fileIN, int array[250]);


//Function: occurance.
//The function requires count, userInput and the array to find out how many times a certain license plate number repeats inside
//the file and then outputs the final value as an integer
int occurance(int count, int array[250], int userInput);




int main()
{
    ifstream fileIN; //input file
    
    int array[250]; //array that reads the license plate numbers from the file
    int count = 0;
    int userInput = 0; //variable that holds the user input for the license plate number
    int lastValue = 0; //number of violations/ number of repitions of that specific license plate number in the file
    
    inputFileName(fileIN); //calls function: inputFileNames
    count = readFile(fileIN, array); //calls function: readFile and assigns the output value to the variable count
    
    do
    {
        
        cout << "Enter a license number: " << endl; //prompts the user to enter a license plate number
        cin >> userInput;
        
        if(userInput == 0) //program ends if the user enters 0
        {
            cout << "Goodbye" << endl;
        }
        else if(userInput < 0) //negative numbers are invalid because you cannot have negative license plates
        {
            cout << "Invalid driver license number. Try again." << endl;
        }
        else
        {
            lastValue = occurance(count, array, userInput); //function occurance is called and the output is assigned to lastValue
            
            cout << "Driver license " << userInput << " has " << lastValue << " violations." << endl;
            if(lastValue > 6)
            {
                cout << "Driver license should be suspended" << endl; //if the license plate repeats more than 6 times
            }
        }
    }while(userInput != 0); //loop terminates if user enters 0 (sentinial vaue)
    
    
    
    //fileIN.close(); //closes input file
   
    return 0;
}


void inputFileName(ifstream& fileIN)
{
    string inputFileName;
    
    
    cout << "Enter the name of the input file: ";
    cin >> inputFileName;
  
    
    fileIN.open(inputFileName.c_str());
    if(fileIN.fail())
    {
        cout << "Error: input file failed to open!" << endl;
        exit(1);
    }
    
  
    
}

int readFile(ifstream& fileIN, int array[250])
{
    int count = 0;
    fileIN >> array[0];
    for(int i = 1; !fileIN.eof(); i++)
    {
        fileIN >> array[i];
        count = i;
        
    }
    
    return(count);
    
}

int occurance(int count, int array[250], int userInput)
{
    int countOCC = 0;
    for(int i = 0; i < count; i++)
    {
        if(array[i] == userInput)
            countOCC += 1;
            
    }
    return(countOCC);
}