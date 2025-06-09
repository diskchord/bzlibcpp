/**********************************************************************/
//Author: Alex Peppe
//File: sharedstats.h
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
//A collection of externs which refer to the variables in the
//sharedstats.cpp file. This should be included in all headers that
//use the said headers.
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

#ifndef SHARED_STATS
#define SHARED_STATS

extern int objects;
extern int meshes;
extern int groups;
extern int teleporters;
extern int arcs;
extern int boxes;
extern int pyramids;
extern int oldboxes;
extern int oldpyramids;
extern int zones;
extern int spheres;
extern int cones;
extern int numOfMaterials;
extern int numOfPhysics;
extern int numOfDynCols;
extern int numOfTextures;
extern std::string indent;

#endif
