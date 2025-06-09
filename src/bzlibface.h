/**********************************************************************/
//Author: Alex Peppe
//File: bzlibface.h
//
//Contains the Face typedef.
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

#ifndef __FACE_CLASS
#define __FACE_CLASS

#include <iostream>
#include <fstream>
#include <string>

#include "bzlibworld.h"
#include "bzlibpoint.h"
#include "bzlibobjects.h"

//I am aware that the retention of Physics commands and such are not
//necessary, and that there are some extra private variables using
//this system. However, a MeshObject does serve the purpose well
//despite having extra stuff.
//
//Possibly when a mesh interface is implemented the Physics commands
//will have value, so those probably won't ever be deleted.
//
//FIXME: Make this a complete class on its own, rather than being
//       reliant on MeshObject. Please allow the various functions
//       to come from the same source, i.e. don't make two setColor()s.

typedef MeshObject Face;

#endif
