// main.cpp

// Author: Ryan Canty

// Date: 10/21/15

// Course: CSC1610

// Description: This file takes three user-inputted strings, prompts them for a
// selection to rearrange the strings, and outputs the rearranged strings to the
// user.

// Input: Three user-defined strings collected from the standard input stream
// (keyboard).

// Output: The rearranged strings.


#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cassert>
#include <string>
#include <string.h>

using namespace std;

bool getMin( string, string ); //Prototype
bool getMax( string, string ); //Prototype
bool getMin( int, int ); //Prototype
bool getMax( int, int ); //Prototype
string alphabetize( string, string, string, int ); //Prototype
string byLength( string, string, string, int ); //Prototype
string rearrange( string, string, string, int ); //Prototype
string order( string, string, string ); //Prototype
string sameLengthShortest( string, string, string ); //Prototype
string sameLengthLongest( string, string, string );
string sameLengthOf2Short( string, string, string ); //Prototype
string sameLengthOf2Long( string, string, string ); //Prototype

/*
 * 
 */
int main() {
    
    string userString1; //First user-inputted string
    string userString2; //Second user-inputted string
    string userString3; //Third user-inputted string
    cout << "Please input three strings: " << endl; //Prompt for strings
    cin >> userString1 >> userString2 >> userString3; //Store strings
    cout << " " << endl; //Blank line
    
    int select1 = 1; //Integer that represents first selection
    int select2 = 2; //Integer that represents second selection
    int select3 = 3; //Integer that represents third selection
    int select4 = 4; //Integer that represents fourth selection
    int selection; //Integer that will hold the user response.
    
    cout << select1 << " - Listed alphabetically, earliest to latest" << endl;
    cout << select2 << " - Listed alphabetically, latest to earliest" << endl;
    cout << select3 << " - Listed length, shortest to longest" << endl;
    cout << select4 << " - Listed length, longest to shortest" << endl;
    //Creates an interface for the user to work with.
    cin >> selection; //Take in the user selection
   
    cout << rearrange( userString1, userString2, userString3, selection ) << endl;
    //Calls function

    return 0;
}
//Description: Takes in two user-inputted strings and returns true if s1 comes before s2 alphabetically.
//Precondition: The lengths of string s1 and s2 must be greater than 0.
//Postcondition: true is returned if s1 comes before s2 alphabetically.
bool getMin( string s1, string s2)
{
    assert(s1.length() > 0);
    assert(s2.length() > 0);
    return s1 < s2;
}
//Description: Takes in two user-inputted strings and returns true if s2 comes before s1 alphabetically.
//Precondition: The lengths of string s1 and s2 must be greater than 0.
//Postcondition: true is returned when s1 comes after s2 alphabetically.
bool getMax( string s1, string s2 )
{
    assert(s1.length() > 0);
    assert(s2.length() > 0);
    return s1 > s2;
}
//Description: Takes in two integers, the lengths of the strings, and returns true when n1 is less than or equal to n2.
//Precondition: n1 and n2 must be greater than 0.
//Postcondition: true is returned when n1 is less than or equal to n2.
bool getMin( int n1, int n2 )
{
    assert(n1 > 0);
    assert(n2 > 0);
    return n1 <= n2;
}
//Description: Takes in two integers, the lengths of the strings, and returns true when n1 is greater than or equal to n2.
//Precondition: n1 and n2 must be greater than 0.
//Postcondition: true is returned when n1 is greater than or equal to n2.
bool getMax( int n1, int n2 )
{
    assert(n1 > 0);
    assert(n2 > 0);
    return n1 >= n2;
}
//Description: Takes in three strings and returns them in order.
//Precondition: The lengths of string s1, s2, and s3 must be greater than 0.
//Postcondition: The three strings are returned in order.
string order( string s1, string s2, string s3 )
{
    assert(s1.length() > 0);
    assert(s2.length() > 0);
    assert(s3.length() > 0);
    return s1 + ' ' + s2 + ' ' + s3;
}
//Description: Takes in three strings, with either 2 or 3 being the same length, and returns them in order from shortest
//to longest. If 2 or 3 strings are the same length, it returns them alphabetically.
//Precondition: The lengths of string s1, s2, and s3 must be greater than 0.
//Postcondition: The three strings are returned in order from shortest to longest, and alphabetically if they are
//the same length.
string sameLengthShortest( string s1, string s2, string s3 )
{
    assert(s1.length() > 0);
    assert(s2.length() > 0);
    assert(s3.length() > 0);
    if(s1.length() == s2.length())
    {
        return sameLengthOf2Short(s1, s2, s3);
    }
    else if(s1.length() == s3.length())
    {
        return sameLengthOf2Short(s1, s3, s2);
    }
    else if(s2.length() == s3.length())
    {
        return sameLengthOf2Short(s2, s3, s1);
    }
}
//Description: Takes in three strings, with either 2 or 3 being the same length, and returns them in order from longest
//to shortest. If 2 or 3 strings are the same length, it returns them alphabetically.
//Precondition: The lengths of string s1, s2, and s3 must be greater than 0.
//Postcondition: The three strings are returned in order from longest to shortest, and alphabetically if they are
//the same length.
string sameLengthLongest( string s1, string s2, string s3 )
{
    assert(s1.length() > 0);
    assert(s2.length() > 0);
    assert(s3.length() > 0);
    if(s1.length() == s2.length())
    {
        return sameLengthOf2Long(s1, s2, s3);
    }
    else if(s1.length() == s3.length())
    {
        return sameLengthOf2Long(s1, s3, s2);
    }
    else if(s2.length() == s3.length())
    {
        return sameLengthOf2Long(s2, s3, s1);
    }
}
//Description: Takes in three strings, with 2 being the same length, and returns them alphabetically.
//Precondition: The lengths of string s1, s2, and s3 must be greater than 0.
//Postcondition: The three strings are returned alphabetically and also in order from least to greatest.
string sameLengthOf2Short( string s1, string s2, string extra )
{
    string full = "";
    if(getMin(s1, s2))
    {
        full = s1 + ' ';
        if(getMin(s2,extra))
        {
             full += s2 + ' ' + extra;
        }
        else
        {
             full += extra + ' ' + s2;
        }
     }
     else
     {
        full = s2 + ' ';
        if(getMin(s1,extra))
        {
             full += s1 + ' ' + extra;
        }
        else
        {
             full += extra + ' ' + s1;
        }
      }
    return full;
      
}
//Description: Takes in three strings, with 2 being the same length, and returns them alphabetically.
//Precondition: The lengths of string s1, s2, and s3 must be greater than 0.
//Postcondition: //Postcondition: The three strings are returned alphabetically and also in order from greatest to least.
string sameLengthOf2Long( string s1, string s2, string extra )
{
    string full = "";
    if(getMax(s1, s2))
    {
        
        if(getMax(s2,extra))
        {
             full += s1 + ' ' + s2 + ' ' + extra;
        }
        else
        {
             full += extra + ' ' + s1 + ' '+ s2;
        }
     }
     else
     {
        if(getMax(s1,extra))
        {
             full += s2 + ' ' + s1 + ' ' + extra;
        }
        else
        {
             full += extra + ' ' + s2 + ' ' + s1;
        }
      }
    return full;
}
//Description: Takes in three strings and an int check, if check equals 1, return the strings in 
//alphabetical order from earliest to latest, if check equals -1, return the strings in 
//alphabetical order from latest to earliest.
//Precondition: The lengths of string s1, s2, and s3 must be greater than 0, check must be 1 or -1
//Postcondition: The three strings are returned in alphabetical order, from earliest to latest or
//latest to earliest.
string alphabatize( string s1, string s2, string s3, int check )
{
    assert(s1.length() > 0);
    assert(s2.length() > 0);
    assert(s3.length() > 0);
    assert(check == 1 || check == -1);
    if(check == 1)
    {
        if(getMin(s1, s2) && getMin(s1, s3) && getMin(s2, s3))
        {
            return order( s1, s2, s3 );
        }
        else if(getMin(s1, s2) && getMin(s1, s3) && getMin(s3, s2))
        {
            return order( s1, s3, s2 );
        }
        else if(getMin(s2, s1) && getMin(s2, s3) && getMin(s1, s3))
        {
            return order( s2, s1, s3 );
        }
         else if(getMin(s2, s1) && getMin(s2, s3) && getMin(s3, s1))
        {
            return order( s2, s3, s1 );
        }
        else if(getMin(s3, s1) && getMin(s3, s2) && getMin(s1, s2))
        {
            return order( s3, s1, s2 );
        }
        else
            return order( s3, s2, s1 );
        
        
    }
    else if(check == -1)
    {
       if(getMax(s1, s2) && getMax(s1, s3) && getMax(s2, s3))
        {
            return order( s1, s2, s3 );
        }
        else if(getMax(s1, s2) && getMax(s1, s3) && getMax(s3, s2))
        {
            return order( s1, s3, s2 );
        }
        else if(getMax(s2, s1) && getMax(s2, s3) && getMax(s1, s3))
        {
            return order( s2, s1, s3 );
        }
         else if(getMax(s2, s1) && getMax(s2, s3) && getMax(s3, s1))
        {
            return order( s2, s3, s1 );
        }
        else if(getMax(s3, s1) && getMax(s3, s2) && getMax(s1, s2))
        {
            return order( s3, s1, s2 );
        }
        else
            return order( s3, s2, s1 );
    }
}
//Description: Takes in three strings and an int check, if check equals 1, return the strings in 
//order by length from shortest to longest, if check equals -1, return the strings in 
//order by length from longest to shortest.
//Precondition: The lengths of string s1, s2, and s3 must be greater than 0, check must be 1 or -1
//Postcondition: The three strings are returned in length order, from shortest to longest or
//longest to shortest.
string byLength( string s1, string s2, string s3, int check )
{
    
    int s1Length = s1.length();
    int s2Length = s2.length();
    int s3Length = s3.length();
    assert(s1Length > 0);
    assert(s2Length > 0);
    assert(s3Length > 0);
    assert(check == 1 || check == -1);
    
    if(check == 1)
    {
        if(getMin(s1Length, s2Length) && getMin(s1Length, s3Length) && getMin(s2Length, s3Length))
        {
            return sameLengthShortest(s1, s2, s3);
        }
        else if(getMin(s1Length, s2Length) && getMin(s1Length, s3Length) && getMin(s3Length, s2Length))
        {
            return order( s1, s3, s2 );
        }
        else if(getMin(s2Length, s1Length) && getMin(s2Length, s3Length) && getMin(s1Length, s3Length))
        {
            return order( s2, s1, s3 );
        }
         else if(getMin(s2Length, s1Length) && getMin(s2Length, s3Length) && getMin(s3Length, s1Length))
        {
            return order( s2, s3, s1 );
        }
        else if(getMin(s3.length(), s1.length()) && getMin(s3.length(), s2.length()) && getMin(s1.length(), s2.length()))
        {
            return order( s3, s1, s2 );
        }
        else
            return order( s3, s2, s1 );
    }
    else if(check == -1)
    {
        if(getMax(s1Length, s2Length) && getMax(s1Length, s3Length) && getMax(s2Length, s3Length))
        {
            return sameLengthLongest(s1, s2, s3);
        }
        else if(getMax(s1Length, s2Length) && getMax(s1Length, s3Length) && getMax(s3Length, s2Length))
        {
            return order( s1, s3, s2 );
        }
        else if(getMax(s2Length, s1Length) && getMax(s2Length, s3Length) && getMax(s1Length, s3Length))
        {
            return order( s2, s1, s3 );
        }
         else if(getMax(s2Length, s1Length) && getMax(s2Length, s3Length) && getMax(s3Length, s1Length))
        {
            return order( s2, s3, s1 );
        }
        else if(getMax(s3.length(), s1.length()) && getMax(s3.length(), s2.length()) && getMax(s1.length(), s2.length()))
        {
            return order( s3, s1, s2 );
        }
        else
            return order( s3, s2, s1 );
    }
}
//Description: Takes in three strings and an int selection from the user, if selection equals 1, arrange the
//strings in alphabetical order from earliest to latest.  If selection equals 2, arrange the
//strings in alphabetical order from latest to earliest.  If selection equals 3, arrange the
//strings in length order from shortest to longest.  If selection equals 4, arrange the strings
//in length order from longest to shortest.
//Precondition: The lengths of string s1, s2, and s3 must be greater than 0, selection must be
//either 1, 2, 3, or 4.
//Postcondition: The three strings are returned in alphabetical order, from earliest to latest or
//latest to earliest, or the strings are returned in length order, from shortest to longest or
//longest to shortest depending on what selection is.
string rearrange( string s1, string s2, string s3, int selection )
{
    assert(s1.length() > 0);
    assert(s2.length() > 0);
    assert(s3.length() > 0);
    assert(selection == 1 || selection == 2 || selection == 3 || selection ==4);
    
    switch(selection)
    {
        case 1:
        {
            return alphabatize( s1, s2, s3, 1 );
        }
        case 2:
        {
            return alphabatize(  s1, s2, s3, -1 );
        }
        case 3:
        {
            return byLength( s1, s2, s3, 1 );
        }
        case 4: 
        {
            return byLength( s1, s2, s3, -1 );
        }
    }
}