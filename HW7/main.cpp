//*******************************************************************
//
//  Program:     Homework 7, Encryption.
//
//  Author:      Sam Abumoghli
//  Email:       sam@moghli.com
//
//
//  Description: Program encrypts and decrypts text entered by the user using a technique called 'Transposition Cipher'.
//
//  Date:         04/04/2016
//
//*******************************************************************
#include <fstream>
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
//#include <string>
using namespace std;

const int SIZE = 101; //Const size for all arrays.


//Function: input_data.
//The function prompts the user to input text and reads the text into the array input
//Function finds the number of chars entered and passes the input array and length as an int back to main.
void input_data(char input[], int& length);

//Function: encrypt_data.
//The function uses text entered by the user from the function: input_data. and length.
//The function uses the transposition cipher method to encrypt the data and outputs the result to the screen.
void encrypt_data(const char input[], char even[], char odd[], char output[], int length);


//Function: decrypt_data.
//The function uses text entered by the user from the function: input_data. and length.
//The function uses the transposition cipher method to decrypt the data and outputs the result to the screen.
void decrypt_data(const char input[], char even[], char odd[], char output[], int length);


//Main Function:
int main()
{
    int userCH = 0; //Users answer to the menu
    char userAns; //Users answer to do while loop
    char input[SIZE]; //Array to input data
    char even[SIZE]; //Temp array for even indexes
    char odd[SIZE]; //Temp array for odd indexes
    char output[SIZE]; //Array for final output for both encryption and decryption functions
    int length = 0; //length of input array
    
    //Welcome prompt
    cout << "Welcome to the Transposition Cipher Application!" << endl;
    cout << "Pick an option from the menu and hit enter: " << endl;
  
    
    do //Do while loop
    {
        //Main menu:
        cout << "(1) Encrypt a message." << endl;
        cout << "(2) Decrypt a message." << endl;
        cout << "(3) Quit." << endl;
        cout << endl;
        cin >> userCH; //User inputs choice
        
        if(userCH == 1) //Encrypt
        {
            input_data(input, length); //Call to function: input_data
        
            encrypt_data(input, even, odd, output, length); //Call to function: encrypt_data
            cout << "Encrypted text:  " << output << endl; //Output
        }
        else if(userCH == 2) //Decrypt
        {
            input_data(input, length);  //Call to function: input_data
            
            decrypt_data(input, even, odd, output, length); //Call to function: decrypt_data
            cout << "Decrypted text:  " << output << endl; //Output
        }
        else if(userCH == 3) //Exit
        {
            cout << "Quitting..." << endl;
            exit(1); //Exits program
        }
        else //Invalid
        {
            cout << "Invalid." << endl;
        }
        
        //Prompt to repeat do while loop
        cout << "Run again? (Y/N)?";
        cin >> userAns;
        
    }while(userAns == 'y' || userAns == 'Y'); //Condition for do while loop
    cout << "Quitting..." << endl;
    
    return 0;
} //End of main
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Function: input_data.
void input_data(char input[], int& length)
{
    cout << "Enter up to 100 characters of text: " << endl;
    cin.ignore();
    cin.getline(input, SIZE-1); //Reads a maximum of 100 chars. The last index in the array is for the sentinal value.
    length = strlen(input); //Find the number of characters the user inputs
}

//Function: encrypt_data.
void encrypt_data(const char input[], char even[], char odd[], char output[], int length)
{
    //Reads the chars from array input to both arrays odd and even based on if the index of the array main is odd or even.
    for(int i = 0; i < length; i++)
    {
        if(i%2 == 0)
        {
            even[i/2] = input[i];
        }
        else
        {
            odd[i/2] = input[i];
        }
    }
    
    //Adds the sentinal value '\0' to the end of the temp arrays odd and even.
    if(length %2 == 0)
    {
        even[(length / 2 ) + 1] = '\0';
    }
    else
    {
        odd[(length / 2 ) + 2] = '\0';
    }
    odd[(length / 2 ) + 1] = '\0';
    
    strcpy(output, odd); //Copies contents of cstring odd to start of cstring output
    strcat(output, even); //Copies contents of cstring even to the end of cstring output
}

//Function: decrypt_data.
void decrypt_data(const char input[], char even[], char odd[], char output[], int length)
{
    
    int evenSize = 0, oddSize = 0; //Variables for the sizes of odd and even
    int count = 0;
    
    //Find evenSize and oddSize relative to the length of the text entered.
    if(length %2 == 0)
    {
        evenSize = (length / 2 ) + 0;
    }
    else
    {
        oddSize = (length / 2 ) + 2;
    }
    oddSize = (length / 2 ) + 1;
    
    //Read into odd array
    for(int i = 0; i < oddSize - 1 ;i++)
    {
        odd[i] = input[i];
        count++;
    }
    
    
    //Read into even array
    for(int j = count; j < length; j++)
    {
        //for(int l = 0; l < length; l++)
        even[j - count] = input[j];
    }
   
    //Extractin the data from the temp functions odd and even.
    int e = 0; //count for even array
    int o = 0; //count for odd array
    for(int i = 0; i < length; i++)
    {
        
        if(i%2 == 0) //Checks if index is even.
        {
            output[i] = even[e];
            e++;
        }
        else //Index is odd
        {
            output[i] = odd[o];
            o++;
        }
    }
}