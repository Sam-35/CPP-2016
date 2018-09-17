#ifndef BOOK_H
#define BOOK_H

//*******************************************************************
//
//  Program:     Homework 9. Book Project.
//
//  Author:      Sam Abumoghli
//  Email:       sam@moghli.com
//
//
//  Description: Program contains a class called Book that includes variables author, title and year.
//               The program contains public and private member functions for the class Book.
//
//  Date:         04/20/2016
//
//*******************************************************************
#include <fstream>
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <string>
using namespace std;

//***Class: Book.***
class Book
{
public: //#Public member variables and functions:#
    
    //#Constructor Member Functions:# (1) $
    //Function: Book.
    //Default constructor. Initlizes variable to default values.
    Book();
    //Function: Book.
    //Initlize constructor.
    Book(string titleNew, int yearNew, string authorNew);
    //Function: Book.
    //Splits the string all_data into two strings; author and title and one int year.
    Book(string all_data); //Split constructor
    
    //#Setters:# (2) $
    //Function: setTitle.
    //Initilizes variable title.
    void setTitle(string titleNew);
    //Functions: setYear.
    //Initlizes variable year.
    void setYear(int yearNew);
    //Function: setAuthor.
    //Initilizes variable author.
    void setAuthor(string authorNew);
    
    
    //#Getters:# (3) $
    //Function: get_title.
    //Returns title, of type string.
    string get_title();
    //Function: get_year.
    //Returns year, of type int.
    int get_year();
    //Function: get_author.
    //Returns author, of type string.
    string get_author();
    
    //Compare functions: (4) $
    //Function: match_title.
    //Checks if string matches title
    //Calls private member function: stringLower.
    bool match_title(string target_title);
    //Function: match_year.
    //Checks if string matches year
    //Uses predefined function to_string(number_variable)
    bool match_year(string target_year);
    //Function: match_author
    //Checks if string matches author
    //Calls private member function: stringLower.
    bool match_author(string target_author);
    //Function: match.
    //Checks if string matches anything from variables title, year and author.
    //Calls private member function: stringLower.
    bool match(string target); //Checks if any string matches
    
    //Other Functions: (5) $
    friend ostream& operator <<(ostream &out,
                                const Book &b1);
    
    friend bool operator ==(const Book &b1, const Book &b2);
    
private: //#Private member variables and functions;#
    //Can only be accessed by class member functions.
    //Private member variables:
    string title;  //Book title
    int year; //Book year
    string author; //Book author
    
    //int numberOfBooks, numberOfLines;
    //string inputBooks[ARRAYSIZE]; //Temp array for input
    //string books[ARRAYSIZE]; //Final array that holds books
    
public:
    
    //Function: stringLower.
    //Takes in a string with upper/lowercase characters and returns a string with all lowercase characters.
    //Can only be accessed by class member functions.
    string stringLower(string upper) const;
};
//***Class ends.***
#endif
