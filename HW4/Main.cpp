//*******************************************************************
//
//  Program:     Projected Population
//
//  Author:      Sam Abumoghli
//  Email:       sam@moghli.com
//
//
//  Description:  This program inputs variables for a file of the users choosing and calculuates
//                the projected population of each country using the variables from the input file
//                and then outputs the results to an output file of the users choosing.
//  Date:         02/26/2016
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

ifstream fileIN; //Declaring fileIN as ifstream
ofstream fileOUT; //Declaring fileOUT as ofstream

void input_file_names(string &input, string &output);
//Function: input_file_names
//The function prompts the user to input files names for input and output files.
//Call by refrence is enabled for the strings (input and output files names)
//The names of the files entered by the user are stored in the string variables declared in the prototype

int populationProjected(int population, double &years, double &birthRate, double &deathRate);
//Function: populationProjected
//This function uses the variables current population, years, birth rate and death rate from
//the file that the user chooses as the input file to culculate the projected population growth
//this function contains a for loop that is set to repeat for the number of years provided.
//This function returns an integer value.
//The variables used in this function are available in main.

void results(string countryName, int currentPop, int answerF, double years);
//Function: results
//This function uses the variables country name, current population, number of years,
//and the final answer which is the output from the function projectedPopulation.
//This function takes its arguments from main and outputs them to the output file chosen by user.
//Function is used to write to the output file.


//Main Function starts here
int main()
{
    string inputfilename; //name of the input file
    string outputfilename; //name of the output file
    
    input_file_names(inputfilename,outputfilename);
    //Calls the function 'input_file_names' to prompt the user to enter the names of the files input/output
    
    string prevCountry = "Nothing"; //Used to eventually break the loop
    string countryName; //Country name
    int currentPop; //Current population
    int answerF; //The final result after the calculation of projected population growth
    double birthRate; //Birth rate
    double birthRC; //we dont use these numbers in our calculations but we input them anyways
    double deathRate; //Death rate
    double deathRC; //we dont use these numbers in our calculations but we input them anyways
    double years; //years n

    
    fileIN.open(inputfilename.c_str()); //opens the input file and checks if it fails
    if(fileIN.fail())
    {
        cout << "Error: input file failed to open." << endl;
        exit(1);
    }
    
    fileOUT.open(outputfilename.c_str()); //opens the output file and checks if it fails
    if(fileOUT.fail())
    {
        cout << "Error: output file failed to open." << endl;
        exit(1);
    }
    
    fileIN >> countryName;
    
    fileOUT << setw(10) << "Country" << setw(15) << "Current Pop" << setw(15) << "Projected Pop" << setw(15) << "Years" << endl;
    fileOUT << "-------------------------------------------------------" << endl;
    
    
    //While loop is used to input the lines one by one
    while(countryName != prevCountry)//Only way that worked for me to prevent loop from becoming infinite
    {
        fileIN >>  currentPop >> birthRate >> birthRC  >> deathRate >> deathRC >> years;
        //Inputs all of the values in the .txt file in order
        
        answerF = populationProjected(currentPop, years, birthRate, deathRate);
        //Calls function populationProjected and assigned arguments to it. The result is declared as answerF.
        results(countryName, currentPop, answerF, years);
        //Calls function 'Results' that displays the final values of the calculation.
        
       
        prevCountry = countryName;
        fileIN >> countryName;
    }
    
    fileIN.close(); //Closes the input file
    fileOUT.close(); //Closes the output file
    return 0;
}

//Function: input_file_name
void input_file_names(string &input, string &output)
{
    cout << "Enter the name of the file to load: ";
    cin >>  input;
    cout <<"Enter the name of the file to save results to: ";
    cin >> output;
}

//Function: populationProjected
int populationProjected(int population, double &years, double &birthRate, double &deathRate)
{
    double populationGrowth = 0;
    int newPop = 0;
    populationGrowth = (birthRate - deathRate) / 100;
    
    for (int i = 0; i < years; i++)
    {
        population = population + populationGrowth * population;
        newPop = population;
        
    }
    return(newPop);
}

//Function: results
void results(string countryName, int currentPop, int answerF, double years)
{
    fileOUT << setw(10) << countryName << setw(15) << currentPop << setw(15) << answerF << setw(15) << years << endl;
    
}