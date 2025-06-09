/**********************************************************************/
//Author: Alex Peppe
//File: bzlibshared.h
//
//Contains shared functions prototypes.
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

/**********PLEASE SEE SHARED.CPP FOR MORE INFORMATION**********/
bool equalIgnoreCase( std::string str1, std::string str2 );
//Precondition:  none
//Function:      Tests two strings to see if they are equal, but does so
//               ignoring case.

std::string trim( std::string toTrim );
//Precondition:  none
//Function:      Trims extra spaces off the beginning and end of strings.

int nameIncrement();
//Precondition:  none
//Function:      Keeps track of the current object number.

int teleNameIncrement();
//Precondition:  none
//Function:      Keeps track of the current teleporter number.

int groupNameIncrement();
//Precondition:  none
//Function:      Keeps track of the current group number.

void strinta(std::string& str, int num);
//Precondition:  none
//Function:      This function adds an integer to string.

void strflta(std::string& str, double num);
//Precondition:  none
//Function:      This function adds a float to string.

void strdbla(std::string& str, double num);
//Precondition:  none
//Function:      This function adds a double to string.
