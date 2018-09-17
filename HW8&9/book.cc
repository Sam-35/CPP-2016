
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

//Constructor Member Functions: (Initilize) //Done! (1)
//Book Function: Book.
Book::Book()
{
    title = "***";
    year = 0;
    author = "***";
}
//Book Function: Book.
Book::Book(string titleNew, int yearNew, string authorNew)
{
    title = titleNew;
    year = yearNew;
    author = authorNew;
}
//Book Function: Book.
Book::Book(string all_data)
{
    // > title|year|author
    //all_data = "The Hitchhiker's Guide to the Galaxy|1979|Douglas Adams";
    
    long int firstStop = 0, secondStop = 0, finalStop = 0; //Locations to use when diving all_data
    string yearTemp;//Stores year in a string
    
    firstStop = all_data.find("|");
    title = all_data.substr(0, firstStop);
    
    secondStop = all_data.find("|", firstStop + 2);
    yearTemp = all_data.substr(firstStop + 1, secondStop);
    year = atoi(yearTemp.c_str());
    
    finalStop = all_data.length();
    author = all_data.substr(secondStop + 1, finalStop);
}

//###Setters: (2) //From blackboard example
//Book Function: setTitle.
void Book::setTitle(string titleNew)
{
    title = titleNew;
}
//Book Function: setYear.
void Book::setYear(int yearNew)
{
    year = yearNew;
}
//Book Function: setAuthor.
void Book::setAuthor(string authorNew)
{
    author = authorNew;
}

//###Getters: (3) //From blackboard example
//Book Function: get_title.
string Book::get_title()
{
    return title;
}
//Book Function: get_year.
int Book::get_year()
{
    return year;
}
//Book Function: get_author.
string Book::get_author()
{
    return author;
}

//Compare Member Functions: (4)
//Book Function: match_title.
bool Book::match_title(string target_title) //change both strings to lowercase and use .find from string clase, return bool
{
    string target_titleL, titleL;
    target_titleL = stringLower(target_title); //change target_title to lowercase.
    titleL = stringLower(title); //change title to lowercase.
    
    if(titleL.find(target_titleL) == string::npos) //compare both of the strings
    {
        return false;
    }
    else
    {
        return true;
    }
}

//Book Function: match_year.
bool Book::match_year(string target_year) //Change int year (already declared in private) to string and then compare, return bool, use string function .find
{
    string yearString = to_string(year);
    if(yearString.find(target_year) == string::npos) //compare both of the strings
    {
        return false;
    }
    else
    {
        return true;
    }
    
}

//Book Function: match_author.
bool Book::match_author(string target_author)//change both strings to lowercase and use .find from string clase, return bool
{
    string target_authorL, authorL;
    target_authorL = stringLower(target_author); //change target_author to lowercase.
    authorL = stringLower(author); //change author to lowercase.
    
    if(authorL.find(target_authorL) == string::npos) //compare both of the strings
    {
        return false;
    }
    else
    {
        return true;
    }
}

//Book Function: match.
bool Book::match(string target_any) //change int year (already declared in private) to string, change all strings to lower case and then compare, use string function .find, return bool
{
    //string target_anyL = stringLower(target_any); //change user input to lowercase.
    bool authorB = false, titleB = false, yearB = false;
    
    authorB = match_author(target_any);
    yearB = match_year(target_any);
    titleB = match_title(target_any);
    
    if( authorB == true || yearB == true || titleB == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Private member functions: (6)
//Book Function: stringLower.
string Book::stringLower(string upper) const //Works!!
{
    long int stringSize = upper.length(); //Finds length of the string
    stringSize +=1; //Adds one to the length of the string
    char lowerFinal[stringSize], lowerTemp[stringSize]; //Declares final and temp arrays to hold the string
    
    lowerTemp[stringSize] = '\0'; //Adds sentinal value to lowerTemp
    upper.copy(lowerTemp, stringSize); //Copies string to temp array
    lowerTemp[stringSize - 1] = '\0'; //Adds sentinal value to clear garbage from this index
    
    for(int i = 0; i < stringSize ;i++) //For loop to change each char to lowercase
    {
        lowerFinal[i] = tolower(lowerTemp[i]);
    }
    string s = lowerFinal;
    return(s);
}
//Other Functions: (5)
//Function: Overload operator <<
//From example posted on blackboard
ostream& operator <<(ostream &out,
                     const Book &b1)
{
    
    string yearString = to_string(b1.year);
    out << b1.title + "|" + yearString + "|" + b1.author;
    return out;
} //Modify the overloaded output operator (<<) function to handle multiple authors. Multiple authors will be separated by a semicolon in the data file. They should be printed on separate lines.???????????




//Function: Overload operator ==
//From example posted on blackboard
bool operator ==(const Book &b1,
                 const Book &b2)
{
    return  b1.stringLower(b1.title) == b1.stringLower(b2.title) &&
    b1.year == b2.year && b1.stringLower(b1.author) == b1.stringLower(b2.author);
}





