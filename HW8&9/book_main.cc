#include <fstream>
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <string>
#include "book.h"
using namespace std;

const long int ARRAYSIZE = 15000; //Size for array.

void input_books(ifstream& fileIN, string inputBooks[], int& numberOfLines, string& fileName);
void extract_books(const string inputBooks[], Book books[], int numberOfLines, int& numberOfBooks);
void outputFile(ofstream& fileOUT, Book printBooks[], Book books[], int numberOfBooks, string fileName);
void seperate_print(Book printBooks[], int numberOfResults);
void option_one(int numberOfLines, int numberOfBooks, int& userAns, Book books[], Book printBooks[]);

//Main Function.
int main()
{
    int userAns = 0; //User answer for main menu and search menu.
    char userCH; //User answer for whether to save file or exit.
    string input; //Testing string
    
    ifstream fileIN; //Input file stream
    ofstream fileOUT; //Overwrite input file
    string fileName; //Name of input file.
    
    int numberOfLines = 1, numberOfBooks = 0; //numberOfLines read from function: input_books, numberOfBooks from function: extract_books.
    
    string inputBooks[ARRAYSIZE]; //Array to input all lines
    Book books[ARRAYSIZE]; //Final array after trash is cleared out
    
    
    Book printBooks[ARRAYSIZE]; //Array to hold results matched
    
    input_books(fileIN, inputBooks, numberOfLines, fileName); //Call to function: input_books.
    
    extract_books(inputBooks, books, numberOfLines, numberOfBooks); //Call to function: extract_books.
    
    
    cout << "Pick an option from the menu and hit enter: " << endl;
    do //Start of do-while loop.
    {
        
        //MAIN PROMPT:
        cout << "Lines: " << numberOfLines << " Books: " << numberOfBooks << endl;
        cout << "(1) Search." << endl;
        cout << "(2) Add a book." << endl;
        cout << "(3) Delete a book by title." << endl;
        cout << "(0) Quit the program." << endl;
        cin >> userAns; //User inputs answer.
        
        //OPTION: #1
        if(userAns == 1) //Search.
        {
            do
            {
                option_one(numberOfLines, numberOfBooks, userAns, books, printBooks); //Call to function: option_one.
                
            }while(userAns!= 5);
        }
        
        //OPTION: #2
        else if(userAns == 2) //Add a book.
        {
            string titleI, authorI, authorF;
            int yearI;
            
            cout << "Add a book option: " << endl; // New book should be added to the end of the array. Allow for multiple authors.???????????????????????
            cout << "Enter title: " << endl;
            cin >> titleI;
            cout << "Enter year: " << endl;
            cin >> yearI;
            cout << "Enter authors seperated by a semicolon: " << endl;
            cin >> authorI;
            
            Book Add(titleI, yearI, authorI);
            
            for(int i = 0; i < numberOfBooks; i++)
            {
                printBooks[i] = books[i];
                
            }
            
            printBooks[numberOfBooks] = Add;
            numberOfBooks++;
        }
        
        //OPTION: #3
        /*else if(userAns == 3) //Delete a book.
        {
            //Book trash[ARRAYSIZE];
            cout << "Delete a book by title option: " << endl;  //deletes a book that match the title exactly?????????????????????????????
            string titleI[10];
            cout << "Enter title: " << endl;
            cin >> titleI;
            int j = 0;
            for(int i = 0; i < numberOfBooks; i++)
            {
                if(books[i].get_title() != titleI[i])
                {
                    printBooks[j] = books[i];
                    j++;
                }
            }
        }
        */
        //OPTION: #0
        else if(userAns == 0) //Quit program.
            
        {
            cout << "Save changes to the original library (Y/N)?" << endl;
            cin >> userCH; //Ask the user if they want to save changes to the library. If the user chooses to save, then save all the books back to the same input file.
            if(userCH == 'y' || userCH == 'Y')
            {
                cout << "Saving.." << endl; //Save to file.
                outputFile(fileOUT, printBooks, books, numberOfBooks, fileName); //Call to function: outputFile.
            }
            else if(userCH == 'n' || userCH == 'N') //Does not overwrite input file and quits the program.
            {
                cout << "Quitting..." << endl;
                exit(1); //Exits program.
            }
        }
        //OPTION: Invalid
        else //Invalid input, try again.
        {
            cout << "Invalid input!" << endl;
            cout << "Try again..." << endl;
        }
    }while(userAns != 0); //End of do-while loop.
    
    fileIN.close(); //Closes the input file.
    fileOUT.close(); //Closes the input file if user chooses to overwrite.
    return 0;
}
//Main ends.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void option_one(int numberOfLines, int numberOfBooks, int& userAns, Book books[], Book printBooks[])
{
    string input;
    int numberOfResults = 0; //Number of results that match the string inputted by the user.
    //User prompt and answer for searching.
    cout << "Search Option: " << endl;
    cout << "(1) Search for any string in the title, year, or author." << endl;
    cout << "(2) Search by author." << endl;
    cout << "(3) Search by title." << endl;
    cout << "(4) Search by year." << endl;
    cout << "(5) Exit to main menu." << endl;
    cout << "(0) Quit the program." << endl;
    cin >> userAns;
    
    if(userAns == 1) //Any string
    {
        cout << "Enter string to search for and hit enter: " << endl;
        cin >> input;
        for(int i = 0; i < numberOfLines; i++)
        {
            if(books[i].match(input))
            {
                printBooks[numberOfResults] = books[i];
                numberOfResults++; //Number of results
            }
        }
        seperate_print(printBooks, numberOfResults);
        
    }
    else if(userAns == 2) //Author
    {
        cout << "Enter name of the author to search for and hit enter: " << endl;
        cin >> input;
        for(int i = 0; i < numberOfLines; i++)
        {
            if(books[i].match_author(input))
            {
                printBooks[numberOfResults] = books[i];
                numberOfResults++; //Number of results
            }
        }
        seperate_print(printBooks, numberOfResults);
    }
    else if(userAns == 3) //Title
    {
        cout << "Enter name of the title to search for and hit enter: " << endl;
        cin >> input;
        for(int i = 0; i < numberOfLines; i++)
        {
            if(books[i].match_title(input))
            {
                printBooks[numberOfResults] = books[i];
                numberOfResults++; //Number of results
            }
        }
        seperate_print(printBooks, numberOfResults);
    }
    else if(userAns == 4) //Year
    {
        cout << "Enter the year to search for and hit enter: " << endl;
        cin >> input;
        for(int i = 0; i < numberOfLines; i++)
        {
            if(books[i].match_year(input))
            {
                printBooks[numberOfResults] = books[i];
                numberOfResults++; //Number of results
            }
        }
        seperate_print(printBooks, numberOfResults);
    }
    else if(userAns == 5)
    {
        cout << "Back to main menu." << endl;
    }
    else if(userAns == 0) //Quit the program
    {
        cout << "Quitting..." << endl;
        exit(1);
    }
    else //Invalid input, try again.
    {
        cout << "Invalid input!" << endl;
        cout << "Try again..." << endl;
    }
}




    
}
void input_books(ifstream& fileIN, string inputBooks[], int& numberOfLines, string& fileName) //Works!
{
    
    cout << "Enter the name of the input file that contains the book library:  ";
    cin >> fileName;
    fileName = "BookDB.txt"; //REMOVE AFTER TESTING!!!!!!!!!
    string tempString;
    long int size;
    
    fileIN.open(fileName.c_str()); //Checks if the input file fails to open.
    if(fileIN.fail())
    {
        cout << "Error: Input file failed to open!" << endl;
        exit(1);
    }
    int loc = -1; //Location of first char that is NOT zero.
    int loc2 = 0; //Location of last char that is NOT zero.
    
    //Input to array: inputBooks[i]
    getline(fileIN, inputBooks[0]); //Reads the first line to the index 0.
    
    for(int i = 1;!fileIN.eof(); i++) //Reads from 1 until end of file.
    {
        getline(fileIN, inputBooks[i]);
        
        size = inputBooks[i].length();
        
        for(int k = 0; k < size; k++)
        {
            
            if(!isspace(inputBooks[i][k]))
            {
                if(loc == -1)
                {
                    loc = k;
                }
                loc2 = k;
            }
        }
        inputBooks[i] = inputBooks[i].substr(loc, loc2 + 2);
        
        numberOfLines++; //Number of lines read, numberOfLines set to one in main.
    }
    cout << "LOCATION: " << loc2 << endl;
}

void extract_books(const string inputBooks[], Book books[], int numberOfLines, int& numberOfBooks) //Works!
{
    string trash[ARRAYSIZE]; //Useless array that stores trash
    int j = 1; //Counter for array that stores good lines books[j]
    
    books[0] = inputBooks[0];
    for(int i = 1; i < numberOfLines; i++) //Runs through all of the input array
    {
        //All leading and trailing spaces must be removed prior to processing each line.????????
        if(inputBooks[i].find("#", 0) != string::npos) // Whatif "book #comment"????????????????????????????????????????????????
        {
            trash[i] = inputBooks[i];
        }
        else if(inputBooks[i] == "\n" || inputBooks[i] == "\t" || inputBooks[i] == "") //??????????????????
        {
            trash[i] = inputBooks[i];
        }
        else
        {
            books[j] = inputBooks[i];
            j++; //Counter
            numberOfBooks++; //Number of books
        }
    }
}

void outputFile(ofstream& fileOUT, Book printBooks[], Book books[], int numberOfBooks, string fileName) //Works!
{
    
    fileOUT.open(fileName.c_str()); //Tests if output file fails to open.
    if(fileOUT.fail())
    {
        cout << "Error: Input file failed to open!" << endl;
        exit(1);
    }
    
    
    
    for(int i = 0; i < numberOfBooks + 1; i++) //Outputs the array books[] to the file, i has to be less the number of books read.
    {
        fileOUT << printBooks[i] << endl; //Outputs final version of the array books.
    }
}

void seperate_print(Book printBooks[], int numberOfResults) //Works!!
{
    for(int i = 0; i < numberOfResults; i++) //Output printBooks to screen up to numberOfResults
    {
        cout << printBooks[i] << endl; //Print array to screen
    }
}






