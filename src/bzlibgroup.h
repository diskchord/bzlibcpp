/**********************************************************************/
//Author: Alex Peppe
//File: bzlibgroup.h
//
//The BZLib group object.
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

#ifndef __GROUP_CLASS
#define __GROUP_CLASS

#include <iostream>
#include <fstream>
#include <string>

#include "bzlibworld.h"
#include "bzlibobjects.h"

class Group
{
public:
	Group();
	
	void startGroup();
	//Precondition:  The argument is a non-empty string.
	//Function:	 Starts a group.

	void endGroup();
	//Precondition:  none
	//Function:      Ends a group.
	
	void setColor( double, double, double, double );
	//Precondition:  none
	//Function:      Sets the color for the group.

	void setColor( double, double, double );
	//Precondition:  none
	//Function:      Sets the color for the group.

	void setTint( double, double, double, double );
	//Precondition:  none
	//Function:      "Tints" the objects in the group.

	void setTint( double, double, double );
	//Precondition:  none
	//Function:      "Tints" the objects in the group.

	void setScale( double, double, double );
	//Precondition:  none
	//Function:      Scales the objects.
	
	void setLocation( Point );
	//Precondition:  none
	//Function:      Sets the position variable.

	void setTeam( std::string team );
	//Precondition:  none
	//Function:	 Adds a team to a group.

	void setSpin( double, Point );
	//Precondition:  none
	//Function:      Sets the rotation and spinPoint variables.

	void Make();
	//Precondition:  none
	//Function:      Makes the group with the given features.

private:
	std::string name;
	std::string teamStr;
	std::string color;
	std::string tint;
	double rotation;
	double scalex;
	double scaley;
	double scalez;
	Point shift;
	Point spinPoint;
};

#endif
