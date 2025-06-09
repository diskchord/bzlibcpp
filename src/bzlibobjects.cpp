/**********************************************************************/
//Author: Alex Peppe
//File: bzlibobjects.cpp
//
//Contains the Object class definitions.
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

#include "bzlib.h"
#include "sharedstats.h"

Object::Object()
{
	std::ofstream fout;
	std::ifstream fin;
	position[0] = 0;
	position[1] = 0;
	position[2] = 0;
	size[0] = 0;
	size[1] = 0;
	size[2] = 0;
	rotation = 0;
	raw = "";
	name = "ob";
	strinta( name, nameIncrement() );
}

void Object::setLocation( Point p1, Point p2 )
//Precondition:  none
//Function:      Sets the local variables.
{
	Point obPosition( p1 + p2 );
	if ( p1.z < p2.z )
		obPosition.z = p1.z;
	else
		obPosition.z = p2.z;
	Point obSize = p2 - p1;
	if ( obSize.x == 0 || obSize.y == 0 || obSize.z == 0 )
	{
		std::cout << "bzlib: Invalid Object Size.\n";
		std::cout << "     : Object " << name << ": (" << obSize.x << ", " << obSize.y << ", " << obSize.z << ")\n";
	}

	position[0] = obPosition.x / 2;
	position[1] = obPosition.y / 2;
	position[2] = obPosition.z;

	size[0] = abs( obSize.x / 2 );
	size[1] = abs( obSize.y / 2 );
	size[2] = abs( obSize.z );

	objects++;
}

void Object::setRotation( double rotation )
//Precondition:  none
//Function:      Sets rotation.
{
	this->rotation = rotation;
}

void Object::getPosition( double& x, double& y, double& z )
//Precondition:  none
//Function:      Passes out the position of the object.
{
	x = position[0];
	y = position[1];
	z = position[2];
}

void Object::getSize( double& x, double& y, double& z )
//Precondition:  none
//Function:      Passes out the size of the object.
{
	x = size[0];
	y = size[1];
	z = size[2];
}

void Object::getRotation( double& rot )
//Precondition:  none
//Function:      Passes out the object's rotation.
{
	rot = rotation;
}

void Object::setName( std::string name )
//Precondition:  none
//Function:      Sets the object's name. It is extremely unwise
//               to do this. Only do so if you have a good reason.
{
	this->name = trim( name );
}

void Object::addRaw( std::string raw )
//Precondition:  none
//Function:      Adds raw code to the object.
{
	this->raw += indent + "  " + trim( raw ) + "\n";
}

void Object::setDriveThrough()
//Precondition:  none
//Function:      Makes object drivethrough.
{
	addRaw( "drivethrough" );
}
	
void Object::setPassable()
//Precondition:  none
//Function:      Makes object drivethrough.
{
	addRaw( "passable" );
}
