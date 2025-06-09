/**********************************************************************/
//Author: Alex Peppe
//File: bzlibbox.h
//
//Contains the Box class and its function prototypes.
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

#ifndef __BOX_CLASS
#define __BOX_CLASS

#include <iostream>
#include <fstream>
#include <string>

#include "bzlibworld.h"
#include "bzlibpoint.h"
#include "bzlibmeshobject.h"
#include "bzlibgroup.h"

class Box : public MeshObject
{
public:
	Box();
	Box( Point, Point );

	void repeatMakeRotate90( Point p );
	//Precondition:  none
	//Function:      Repeats an object around.

	void Make();
	//Precondition:  none
	//Function:      Adds the object to the world. Also adds any drivers,
	//		 materials, or dynamic colors that the object needs.
};

#endif
