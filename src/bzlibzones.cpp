/**********************************************************************/
//Author: Alex Peppe
//File: bzlibzones.cpp
//
//Contains the Zone class definitions.
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

Zone::Zone()
{
	flagStr = "";
	teamStr = "";
	safeStr = "";
}

Zone::Zone( Point p1, Point p2 )
{
	flagStr = "";
	teamStr = "";
	safeStr = "";
	setLocation( p1, p2 );
	setRotation( 0 );
}

void Zone::addFlag( std::string flag )
//Precondition:  flag must be a valid BZFlag flag.
//Function:	 Adds a flag to a zone.
{
	flagStr += flag;
	flagStr += " ";
}

void Zone::addTeam( std::string team )
//Precondition:  none
//Function:	 Adds a team to a zone.
{
	if ( team == "BLUE" || team == "RED" || team == "GREEN" || team == "PURPLE" || team == "ROGUE" || team == "RABBIT" || team == "OBSERVER" )
	{
		if ( team == "ROGUE" )
			strinta( teamStr, TROGUE );
		else if ( team == "RED" )
			strinta( teamStr, TRED );
		else if ( team == "RABBIT" )
			strinta( teamStr, TRABBIT );
		else if ( team == "PURPLE" )
			strinta( teamStr, TPURPLE );
		else if ( team == "BLUE" )
			strinta( teamStr, TBLUE );
		else if ( team == "GREEN" )
			strinta( teamStr, TGREEN );
		else
			strinta( teamStr, TOBSERVER );
		teamStr += " ";
	}
	else
	{
		cout << "bzlib: Invalid Team in Zone: " << team << endl;
		cout << "     : Acceptable teams: BLUE, RED, GREEN, PURPLE, and ROGUE." << endl;
		exit(1);
	}	
}

void Zone::addSafety( std::string team )
//Precondition:  none
//Function:	 Adds a place for a team flag to go when passed.
{
	if ( team == "BLUE" || team == "RED" || team == "GREEN" || team == "PURPLE" || team == "ROGUE" || team == "RABBIT" || team == "OBSERVER" )
	{
		if ( team == "ROGUE" )
			strinta( safeStr, TROGUE );
		else if ( team == "RED" )
			strinta( safeStr, TRED );
		else if ( team == "RABBIT" )
			strinta( safeStr, TRABBIT );
		else if ( team == "PURPLE" )
			strinta( safeStr, TPURPLE );
		else if ( team == "BLUE" )
			strinta( safeStr, TBLUE );
		else if ( team == "GREEN" )
			strinta( safeStr, TGREEN );
		else
			strinta( safeStr, TOBSERVER );
		safeStr += " ";
	}
	else
	{
		cout << "bzlib: Invalid Safety in Zone: " << team << endl;
		cout << "     : Acceptable teams: BLUE, RED, GREEN, PURPLE, and ROGUE." << endl;
		exit(1);
	}	
}

void Zone::Make()
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

	/* Build */
	fout << indent << "Zone\n";
	fout << indent << "  #name " << name << "\n";
	fout << indent << "  position " << px << " " << py << " " << pz << "\n";
	fout << indent << "  size " << sx << " " << sy << " " << sz << "\n";
	fout << indent << "  rotation " << rot << "\n";

	/* Arguments */
	if ( teamStr != "" )
		fout << indent << "  team " << teamStr << "\n";
	if ( safeStr != "" )
		fout << indent << "  safety " << safeStr << "\n";
	if ( flagStr != "" )
		fout << indent << "  flag " << flagStr << "\n";

	fout << indent << "end\n";

	fout.close();

	/* Tally */
	zones++;
}
