/**********************************************************************/
//Author: Alex Peppe
//File: bzlibteleporter.h
//
//Contains the Teleporter class prototypes.
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

#ifndef __TELEPORTER_CLASS
#define __TELEPORTER_CLASS

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include "bzlibpoint.h"
#include "bzlibobjects.h"

class Teleporter : public Object
{
public:
	Teleporter();
	Teleporter( Point, Point );

	void setLink( std::string, Teleporter, std::string );
	//Precondition:  none
	//Function:      Takes a side of the teleporter and links it to the
	//               stated side of another.

	void setBorder( double );
	//Precondition:  none
	//Function:      Sets the border size.
	
	double getBorder();
	//Precondition:  none
	//Function:      Returns the border size.

	void Make();
	//Precondition:  none
	//Function:      Adds the object to the world. Also adds any drivers,
	//		 materials, or dynamic colors that the object needs.
	
private:
	std::string frontLink;
	std::string backLink;
	std::string name;
	double border;
};

#endif
