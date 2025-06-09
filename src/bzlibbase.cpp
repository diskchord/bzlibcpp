/**********************************************************************/
//Author: Alex Peppe
//File: bzlibbase.cpp
//
//Contains the Base class function definitions.
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

Base::Base()
{
	team = 0;
}

Base::Base( Point p1, Point p2 )
{
	team = 0;
	setLocation( p1, p2 );
	setRotation( 0 );
}

void Base::setTeam( int newTeam )
//Precondition:  none
//Function:      Sets the team variable.
{
	team = newTeam;
}

void Base::Make()
//Precondition:  none
//Function:      Adds the object to the world. Also adds any drivers,
//		 materials, or dynamic colors that the object needs.
{

	/* NOTE: All of this information is outputted to a temporary 
	   file. The actual information is placed in the map file when
	   the world object runs its Make() function. */

	std::string fileName = TEMPFILE;
	std::ifstream fin;
	std::ofstream fout;
	
	fout.open( fileName.c_str(), std::ios::app );
	
	double px, py, pz;
	getPosition( px, py, pz );
	
	double sx, sy, sz;
	getSize( sx, sy, sz );

	double rot;
	getRotation( rot );

	fout << indent << "Base\n";
	fout << indent << "  #name " << name << "\n";
	fout << indent << "  position " << px << " " << py << " " << pz << "\n";
	fout << indent << "  size " << sx << " " << sy << " " << sz << "\n";
	fout << indent << "  rotation " << rot << "\n";
	fout << indent << "  color " << team << "\n";
	if ( raw != "" )
	{
		fout << raw;
	}
	fout << indent << "end\n";

	oldboxes++;
	
	fout.close();

	name = "ob";
	strinta( name, nameIncrement() );
}
