/**********************************************************************/
//Author: Alex Peppe
//File: bzlibarc.h
//
//Contains the Arc class and its prototypes.
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

#ifndef __ARC_CLASS
#define __ARC_CLASS

#include <iostream>
#include <fstream>
#include <string>

#include "bzlibworld.h"
#include "bzlibpoint.h"
#include "bzlibmeshobject.h"

class Arc : public MeshObject
{
public:
	Arc();
	Arc( Point, Point );

	void setRatio( double );
	//Precondition:  none
	//Function:      Sets the ratio variable.

	void setAngle( double );
	//Precondition:  none
	//Function:      Sets the angle variable.

	void setDivisions( int );
	//Precondition:  none
	//Function:      Sets the divisions variable.

	void Make();
	//Precondition:  none
	//Function:      Adds the object to the world. Also adds any drivers,
	//		 materials, or dynamic colors that the object needs.

private:
	double ratio;
	double angle;
	int divisions;
};

#endif
