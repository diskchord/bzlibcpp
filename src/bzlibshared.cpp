/**********************************************************************/
//Author: Alex Peppe
//File: bzlibshared.cpp
//
//Contains shared functions.
//
//Copyright 2005 Alex Peppe
//
//This program is free software; you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation; either version 2 of the License, or
//(at your option) any later version.
//
//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with this program; if not, write to the Free Software
//Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
/**********************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctype.h>

using namespace std;

/******************************************************************************
String Related Functions, if nobody else noticed how totally inadequate some
of the STL string library functions are.
******************************************************************************/

bool equalIgnoreCase( std::string str1, std::string str2 )
//Precondition:  none
//Function:      Tests two strings to see if they are equal, but does so
//               ignoring case.
{
	/**********************************************************************
	Make the two local string's values lowercase. This does not affect the
	variables passed to the function.
	**********************************************************************/
	for ( unsigned int i = 0; i < str1.length(); i++ )
		str1[i] = tolower( str1[i] );
	for ( unsigned int i = 0; i < str2.length(); i++ )
		str2[i] = tolower( str2[i] );

	/**********************************************************************
	Check to see if they are equal and return the result.
	**********************************************************************/
	return ( str1 == str2 );
}

std::string trim( std::string toTrim )
//Precondition:  none
//Function:      Trims extra spaces off the beginning and end of strings.
{
	int start = 0;
	int end = toTrim.length();

	/**********************************************************************
	Go from the beginning to the start of text ripping off tabs and spaces.
	I know this goes to toTrim.length(), but notice that it will break
	when there's text other than spaces and tabs.
	**********************************************************************/	
	for ( unsigned int i = 0; i < toTrim.length(); i++ )
	{
		char c = toTrim[i];
		if ( ( c != ' ' ) && ( c != '\t' ) )
		{
			start = i;
			break;
		}
	}

	/**********************************************************************
	Do the same as before, but go from the end to the beginning. Cuts off
	the trailing spaces.
	**********************************************************************/
	for ( unsigned int i = toTrim.length(); i > 0; i-- )
	{
		char c = toTrim[i];
		if ( ( c != ' ' ) && ( c != '\t' ) )
		{
			end = i;
			break;
		}
	}

	/**********************************************************************
	Return the resulting string if there is one.
	**********************************************************************/
	if ( start <= end )
		return toTrim.substr( start, end - ( start - 1 ) );
	else
		return "";
}

/******************************************************************************
Name Functions                                                     
******************************************************************************/

int nameIncrement()
//Precondition:  none
//Function:      Keeps track of the current object number.
{
	static int num = 0;
	return num++;
}

int teleNameIncrement()
//Precondition:  none
//Function:      Keeps track of the current teleporter number.
{
	static int num = 0;
	return num++;
}

int groupNameIncrement()
//Precondition:  none
//Function:      Keeps track of the current group number.
{
	static int num = 0;
	return num++;
}

/******************************************************************************
Append Number to String Functions                                  
Replacing some more gaping holes in the STL string class.
******************************************************************************/

void strinta(std::string& str, int num)
//Precondition:	 none
//Function:	 This function adds an integer to string.
{
	std::ostringstream outStream;
	outStream << str << num;
	str = outStream.str();
}

void strflta(std::string& str, float num)
//Precondition:	 none
//Function:      This function adds a float to string.
{
	std::ostringstream outStream;
	outStream << str << num;
	str = outStream.str();
}

void strdbla(std::string& str, double num)
//Precondition:	 none
//Function:      This function adds a double to string.
{
	std::ostringstream outStream;
	outStream << str << num;
	str = outStream.str();
}
