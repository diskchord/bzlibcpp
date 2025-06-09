/**********************************************************************/
//Author: Alex Peppe
//File: sharedstats.cpp
//
// ____ _______      _ _
//|  _ \___  / |    (_) |     _____
//| |_) | / /| |     _| |__  / ____|     _
//|  _ < / / | |    | | '_ \| |  _| |_ _| |_
//| |_) / /__| |____| | |_) | | |_   _|_   _|
//|____/_____|______|_|_.__/| |___|_|   |_|
//                           \_____|
//
//
//This is a collection of variables defined as externs in the
//sharedstats.h file.
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

#include <string>

using namespace std;

int objects        =    0;
int meshes         =    0;
int groups         =    0;
int teleporters    =    0;
int arcs           =    0;
int boxes          =    0;
int pyramids       =    0;
int oldboxes       =    0;
int oldpyramids    =    0;
int zones          =    0;
int spheres        =    0;
int cones          =    0;
int numOfMaterials =    0;
int numOfPhysics   =    0;
int numOfDynCols   =    0;
int numOfTextures  =    0;
std::string indent =   "";
