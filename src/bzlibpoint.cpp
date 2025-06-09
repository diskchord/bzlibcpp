/**********************************************************************/
//Author: Alex Peppe
//File: bzlibpoint.cpp
//
//Contains the Point class definitions.
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

Point::Point()
{
	x = 0;
	y = 0;
	z = 0;
}

Point::Point( double nx, double ny, double nz )
{
	x = nx;
	y = ny;
	z = nz;
}

Point Point::operator+( Point toAdd )
//Precondition:  none
//Function:      Takes a point and adds all of its values to this
//               one.
{
	Point newPoint;

	newPoint.x = x;
	newPoint.y = y;
	newPoint.z = z;

	newPoint.x += toAdd.x;
	newPoint.y += toAdd.y;
	newPoint.z += toAdd.z;

	return newPoint;
}

void Point::operator+=( Point toAdd )
//Precondition:  none
//Function:      Takes a point and addsall of its value to this
//               one, and then assigns the results to this one.
{
        Point thisPoint( this->x, this->y, this->z );
        Point result = thisPoint + toAdd;
        this->operator()( result.x, result.y, result.z );
}

Point Point::operator-( Point toAdd )
//Precondition:  none
//Function:      Takes a point and subtracts all of its values 
//               from this one.
{
	Point newPoint;

	newPoint.x = x;
	newPoint.y = y;
	newPoint.z = z;

	newPoint.x -= toAdd.x;
	newPoint.y -= toAdd.y;
	newPoint.z -= toAdd.z;

	return newPoint;
}

void Point::operator-=( Point toSubtract )
//Precondition:  none
//Function:      Takes a point and subtracts all of its values
//               from this one, and then assigns the results to
//               this one.
{
	Point thisPoint( this->x, this->y, this->z );
	Point result = thisPoint - toSubtract;
	this->operator()( result.x, result.y, result.z );
}

Point Point::operator*( double toMultiply )
//Precondition:  none
//Function:      Takes a point and multiplies all of its values 
//               times this one.
{
	Point newPoint;

	newPoint.x = x;
	newPoint.y = y;
	newPoint.z = z;

	newPoint.x *= toMultiply;
	newPoint.y *= toMultiply;
	newPoint.z *= toMultiply;

	return newPoint;
}

void Point::operator()( double nx, double ny, double nz )
//Precondition:  none
//Function:      Sets the coordinates of the points.
{
	x = nx;
	y = ny;
	z = nz;
}

bool Point::nonZero()
//Precondition:  none
//Function:      Returns true if the coordinates are something
//               other than (0, 0, 0). Returns false otherwise.
{
	if ( ( x == 0 ) && ( y == 0 ) && ( z == 0 ) )
		return false;
	else
		return true;
}
