/**********************************************************************/
//Author: Alex Peppe
//File: bzlibteleporter.cpp
//
//Contains the Teleporter class function definitions.
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

Teleporter::Teleporter()
{
	border = 1;
	frontLink = "";
	backLink = "";
	name = "tele";
	strinta( name, teleNameIncrement() );
}

Teleporter::Teleporter( Point p1, Point p2 )
{
	border = 1;
	frontLink = "";
	backLink = "";
	setLocation( p1, p2 );
	setRotation( 0 );
	name = "tele";
	strinta( name, teleNameIncrement() );
}

void Teleporter::setLink( std::string sideF, Teleporter t, std::string sideT )
//Precondition:  none
//Function:      Takes a side of the teleporter and links it to the
//               stated side of another.
{
	if ( ( sideF != "front" ) && ( sideF != "back" ) && ( sideF != "all" ) )
	{
		cout << "bzlib: Invalid side given for teleporter " << name << ".\n";
		cout << "     : Only 'front', 'back', or 'all' are acceptable.\n";
		exit(1);
	}
	
	if ( ( sideT != "front" ) && ( sideT != "back" ) && ( sideT != "all" ) )
	{
		cout << "bzlib: Invalid side given for teleporter " << t.name << ".\n";
		cout << "     : Only 'front', 'back', or 'all' are acceptable.\n";
		exit(1);
	}

	if ( sideT == "back" )
		backLink += "link\n  from /" + name + ":" + sideF[0] + "\n  to /" + t.name + ":" + sideT[0] + "\nend\n";
	else if ( sideT == "front" )
		frontLink += "link\n  from /" + name + ":" + sideF[0] + "\n  to /" + t.name + ":" + sideT[0] + "\nend\n";
	else
	{
		backLink += "link\n  from /" + name + ":b" + "\n  to /" + t.name + ":f" + "\nend\n";
		frontLink += "link\n  from /" + name + ":f" + "\n  to /" + t.name + ":b" + "\nend\n";
	}
}

void Teleporter::setBorder( double border )
//Precondition:  none
//Function:      Sets the border size.
{
	this->border = border;
}


double Teleporter::getBorder()
//Precondition:  none
//Function:      Returns the border size.
{
	return border;
}

void Teleporter::Make()
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

	if ( frontLink == "" )
		cout << "bzlib: The front of teleporter " << name << " is not linked." << endl;

	if ( backLink == "" )
		cout << "bzlib: The back of teleporter " << name << " is not linked." << endl;

	teleporters++;
	
	/* Build */
	fout << indent << "Teleporter /" << name << "\n";
	fout << indent << "  position " << px << " " << py << " " << pz << "\n";
	fout << indent << "  size " << sx << " " << sy << " " << sz << "\n";
	fout << indent << "  rotation " << rot << "\n";
	fout << indent << "  border " << border << "\n";
	fout << raw;
	fout << indent << "end\n";
	fout.close();
	
	/* Links */
	fout.open( LINKFILE, std::ios::app );
	fout << frontLink;
	fout << backLink;
	fout.close();
}
