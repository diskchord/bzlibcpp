/**********************************************************************/
//Author: Alex Peppe
//File: bzliboldpyramid.h
//
//Contains the OldPyramid classes.
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

#ifndef __OLDPYRAMID_CLASS
#define __OLDPYRAMID_CLASS

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include "bzlibpoint.h"
#include "bzlibobjects.h"

class OldPyramid : public Object
{
public:
	OldPyramid();
	OldPyramid( Point, Point );

	void Make();
	//Precondition:  none
	//Function:      Adds the object to the world. Also adds any drivers,
	//		 materials, or dynamic colors that the object needs.
};

#endif
