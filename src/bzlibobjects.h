/**********************************************************************/
//Author: Alex Peppe
//File: bzlibobjects.h
//
//Contains the Object class.
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

#ifndef __OBJECT_CLASSES
#define __OBJECT_CLASSES

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <cmath>

#include "bzlibpoint.h"

class Object
{
public:
	Object();

	void setLocation( Point, Point );
	//Precondition:  none
	//Function:      Sets the local variables.

	void setRotation( double );
	//Precondition:  none
	//Function:      Sets rotation.

	void getPosition( double&, double&, double& );
	//Precondition:  none
	//Function:      Passes out the position of the object.

	void getSize( double&, double&, double& );
	//Precondition:  none
	//Function:      Passes out the size of the object.

	void getRotation( double& );
	//Precondition:  none
	//Function:      Passes out the object's rotation.

	void setName( std::string );
	//Precondition:  none
	//Function:      Sets the object's name. It is extremely unwise
	//               to do this. Only do so if you have a good reason.

	void addRaw( std::string );
	//Precondition:  none
	//Function:      Adds raw code to the object.
	
	void setDriveThrough();
	//Precondition:  none
	//Function:      Makes object drivethrough.
	
	void setPassable();
	//Precondition:  none
	//Function:      Makes object passthrough.

protected:
	double position[3];
	double size[3];
	double rotation;
	std::string raw;
	std::string name;
};

#endif
