//*******************************************************************
//
//  Program:     Homework 6, Extract Emails.
//
//  Author:      Sam Abumoghli
//  Email:       sam@moghli.com
//
//
//  Description: The program proompts the user to enter the names of the input and output files, reads in data from a file and extracts the emails.
//                  The program then outputs the emails, usernames, and domains to a file.
//  Date:         03/25/2016
//
//*******************************************************************


#include <fstream>
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string> //imp
#include <cctype> // Include directive to use predefinded character functions.

using namespace std;
const long int  SIZE = 10000; //Constant size for all arrays.

//Function: fileNames.
//The function prompts the users to enter the names of the input and output files and proceeds to open them.
//The function returns the if/ofstreams back to the main function.
void fileNames(ifstream& fileIN, ofstream& fileOUT);

//Function: readFile.
//The function uses the ifstream from main and reads the file line by line into an array which is returned back to main.
void readFile(string lines[SIZE], int& numberoflines, ifstream& filein);

//Function: extract_emails.
//The function extracts the emails from the array lines and stores the extracted emails into the array emails that is returned back to main.
//The function checks for duplicate emails before storing them into the array.
//The function uses the array lines and returns the array emails, variables i for the loop, and the number of emails back to main.
void extract_emails(string lines[SIZE], string emails[SIZE], int& i, int& numOfEmails);


//Function: sort_emails.
//The function uses the array emails (passed by as constant) to extract the usernames and domains and sort them into their own seperate arrays
//The function returns the arrays userNames and domains back to main.
void sort_emails(const string emails[], string userNames[], string domains[], int& i, int& count);

//Function: outputFile
//The function uses all three arrays, emails, userNames and domains to output the results to a file. Also outputs the number of emails and lines read.
//The function uses all three arrays as constants.
void outputFile(const string emails[], const string userNames[], const string domains[], int numOfEmails, int count, int numberoflines, ofstream& fileout);



//Main Function:
int main()
{
    ifstream filein; //Stream for input file
    ofstream fileout; //Stream for output file
    string lines[SIZE]; //Array that stores lines
    string emails[SIZE]; //Array that stores emails
    string userNames[SIZE]; //Array to store usernames
    string domains[SIZE]; //Array to store domains
    
    int numberoflines = 1; //Number of lines read, set as 1 because the first line is read outside array
    int numOfEmails= 0; //Number of emails
    int count = 0;
    
    
    fileNames(filein, fileout); //Call to function: fileNames
    readFile(lines, numberoflines, filein); //Calls the function: readFile.
    
    
    //Extracts the emails from the lines.
    for(int i = 0; i < numberoflines; i++) //Reads until the condition i less than number of lines is true
    {
        while(lines[i] != "") //While the line read is not empty
        {
            extract_emails(lines, emails, i, numOfEmails); //Call to the function: extract_emails.
        }
    }
    
    //Sorts the data.
    for(int i = 0; i < numOfEmails; i++) //Reads until the condition i less than number of lines is true
    {
        sort_emails(emails, userNames,  domains, i, count); //Call to function: sort_emails.
    }
    
    outputFile(emails, userNames, domains, numOfEmails, count, numberoflines, fileout); //Call to function: outputFile.
    
    
    filein.close(); //Closes the input file.
    fileout.close(); //Closes the output file.
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Function: fileNames.
void fileNames(ifstream& fileIN, ofstream& fileOUT) //Works!
{
    string inputFN, outputFN;
    cout << "Enter the name of the input file:  ";
    cin >> inputFN;
    cout << "Enter the name of the output file:  ";
    cin >> outputFN;
    
    
    
    fileIN.open(inputFN.c_str());
    if(fileIN.fail())
    {
        cout << "Error: Input file failed to open!" << endl;
        exit(1);
    }
    
    fileOUT.open(outputFN.c_str());
    if(fileIN.fail())
    {
        cout << "Error: Output file failed to open!" << endl;
        exit(1);
    }
}

//Function: readFile.
void readFile(string lines[SIZE], int& numberoflines, ifstream& filein)
{
    getline(filein, lines[0]); //Getline function to read the first line to the first indes in array (lines)
    for(int i = 1;!filein.eof(); i++) //For loop to read in the lines starting from the second line
    {
        getline(filein, lines[i]); //Getline function to read the files starting from the second line
        numberoflines++; //numOfEmailss the number of files read by incrementing the variable starting from 1
    }
}
//Function: extract_emails.
void extract_emails(string lines[SIZE], string emails[SIZE], int& i, int& numOfEmails)
{
    
    long int first = 0; //Location of the begning of the email
    long int second = 0; //Location of the end of the email
    string tempEmail;  //Temporary email
    bool condition = true;
    
    if(lines[i].find("href=\"mailto:") == string::npos) //from bb example and lc++.com
    {
        lines[i] = ""; //if line does not include "href=\"mailto:" then its set to blank
    }
    else
    {
        first = lines[i].find("href=\"mailto:"); //find position of the start of email
        first += 13; //position of the start of email ("href=\"mailto:" + 13 spaces)
        lines[i].erase(0, first); //erase everything prior to first email from string
        first = 0;
        second = lines[i].find("\""); //find position of the end of the email in string
        tempEmail = lines[i].substr(0, second); //extract email between the two positions
        
        for(int j = 0; j < numOfEmails; j++)// The loop checks for duplicate emails.
        {
            if(tempEmail == emails[j])
            {
                condition = false;
            }
            
        }
        if(condition == true)
        {
            emails[numOfEmails] = tempEmail;  //lines[i].substr(0, second);//extract email between both positions
            numOfEmails++;
        }
        
        lines[i].erase(0, second);
    }
}

//Functions: sort_emails.
void sort_emails(const string emails[], string userNames[], string domains[], int& i, int& count)
{
    long int secondLoc = 0;
    
    secondLoc = emails[i].find("@");
    secondLoc += 1;
    userNames[count] = emails[i].substr(0, secondLoc -1);
    domains[count] = emails[i].substr(secondLoc);
    count++;
}

//Function: outputFile.
void outputFile(const string emails[], const string userNames[], const string domains[], int numOfEmails, int count, int numberoflines, ofstream& fileout)
{
    fileout << left << setw(25) << "Email:" << setw(20) << "Username:" << setw(15) << "Domain:" << endl << endl;
    for(int i = 0; i < numOfEmails; i++)
    {
        fileout << left <<setw(25) << emails[i] << setw(20) << userNames[i] << setw(15) << domains[i] << endl;
    }
    fileout << "Number of emails: " << numOfEmails << endl;  //For testing output
    fileout << "Number of lines: " << numberoflines << endl; //For testing output
}


