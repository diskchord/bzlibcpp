/**********************************************************************/
//Author: Alex Peppe
//File: bzlibpoint.h
//
//Contains the Point class.
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

#ifndef __POINT_CLASS
#define __POINT_CLASS

class Point
{
public:
	Point();
	Point( double, double, double );

	Point operator+( Point );
	//Precondition:  none
	//Function:      Takes a point and adds all of its values to this
	//               one.

	void operator+=( Point );
	//Precondition:  none
	//Function:      Takes a point and addsall of its value to this
	//               one, and then assigns the results to this one.

	Point operator-( Point );
	//Precondition:  none
	//Function:      Takes a point and subtracts all of its values 
	//               from this one.

        void operator-=( Point );
        //Precondition:  none
        //Function:      Takes a point and subtracts all of its values
        //               from this one, and then assigns the results to
	//               this one.
	
	Point operator*=( Point );
	//Precondition:  none
	//Function:      Takes a point and multiplies all of its values 
	//               times this one.

	Point operator*( double );
	//Precondition:  none
	//Function:      Takes a point and multiplies all of its values 
	//               times this one.

	void operator()( double, double, double );
	//Precondition:  none
	//Function:      Sets the coordinates of the points.

	bool nonZero();
	//Precondition:  none
	//Function:      Returns true if the coordinates are something
	//               other than (0, 0, 0). Returns false otherwise.

	double x;
	double y;
	double z;
};

#endif
