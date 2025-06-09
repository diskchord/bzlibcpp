/**********************************************************************/
//Author: Alex Peppe
//File: bzlibsphere.h
//
//Contains the Sphere class.
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

#ifndef __SPHERE_CLASS
#define __SPHERE_CLASS

#include <iostream>
#include <fstream>
#include <string>

#include "bzlibworld.h"
#include "bzlibpoint.h"
#include "bzlibmeshobject.h"

class Sphere : public MeshObject
{
public:
	Sphere();
	Sphere( Point, Point );

	void setRadius( double );
	//Precondition:  none
	//Function:      Sets the ratio variable.

	void setDivisions( int );
	//Precondition:  none
	//Function:      Sets the divisions variable.

	void Make();
	//Precondition:  none
	//Function:      Adds the object to the world. Also adds any drivers,
	//		 materials, or dynamic colors that the object needs.

private:
	double radius;
	double angle;
	int divisions;
};

#endif
