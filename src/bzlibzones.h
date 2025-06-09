/**********************************************************************/
//Author: Alex Peppe
//File: bzlibzones.h
//
//Contains the Zone class prototypes.
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

#ifndef __ZONE_CLASS
#define __ZONE_CLASS

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include "bzlibpoint.h"
#include "bzlibobjects.h"

class Zone : public Object
{
public:
	Zone();
	Zone( Point, Point );
	
	void addFlag( std::string );
	//Precondition:  flag must be a valid BZFlag flag.
	//Function:	 Adds a flag to a zone.
	
	void addTeam( std::string );
	//Precondition:  none
	//Function:	 Adds a team to a zone.
	
	void addSafety( std::string );
	//Precondition:  none
	//Function:	 Adds a place for a team flag to go when passed.

	void Make();
	//Precondition:  none
	//Function:      Adds the object to the world. Also adds any drivers,
	//		 materials, or dynamic colors that the object needs.

private:
	std::string flagStr;
	std::string teamStr;
	std::string safeStr;
};

#endif
