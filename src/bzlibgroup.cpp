/**********************************************************************/
//Author: Alex Peppe
//File: bzlibgroup.cpp
//
//The BZLib group object fleshed out.
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

Group::Group() 
{ 
	name = "";
	rotation = 0;
	scalex = 0;
	scaley = 0;
	scalez = 0;
	color = "";
	tint = "";
	teamStr = "";
}

void Group::startGroup()
//Precondition:  The argument is a non-empty string.
//Function:	 Starts a group.
{
	std::ofstream fout;
	name = "grp";
	strinta( name, groupNameIncrement() );
	fout.open( TEMPFILE, std::ios::app );
	fout << "\n#Start of " << name << "\n";
	fout << "define " << name << "\n";
	indent = "  ";
	fout.close();
}

void Group::endGroup()
//Precondition:  none
//Function:      Ends a group.
{
	std::ofstream fout;
	fout.open( TEMPFILE, std::ios::app );
	fout << "enddef\n";
	fout << "#End of " << name << "\n\n";
	indent = "";
	fout.close();
}

void Group::setColor( double r, double g, double b, double a )
//Precondition:  none
//Function:      Sets the color for the group.
{
	/* Error Detection */
	if ( ( r < 0 ) || ( g < 0 ) || ( b < 0 ) || ( a < 0 ) )
	{
		cout << "bzlib: Invalid Color: " << r << " " << g << " " << b << endl;
		cout << "     : All values must be non-negative." << endl;
		exit(1);
	}
	if ( ( r > 1 ) || ( g > 1 ) || ( b > 1 ) || ( a > 1 ) )
	{
		cout << "bzlib: Invalid Color: " << r << " " << g << " " << b << endl;
		cout << "     : All values must be less than or equal to one." << endl;
		exit(1);
	}

	/* Assignment */	
	std::string colorString;
	colorString = "";
	strdbla( colorString, r );
	colorString += " ";
	strdbla( colorString, g );
	colorString += " ";
	strdbla( colorString, b );
	colorString += " ";
	strdbla( colorString, a );
	color = colorString;
}

void Group::setColor( double r, double g, double b )
//Precondition:  none
//Function:      Sets the color for the group.
{
	setColor( r, g, b, 1 );
}

void Group::setTint( double r, double g, double b, double a )
//Precondition:  none
//Function:      "Tints" the objects in the group.
{
	/* Error Detection */
	if ( ( r < 0 ) || ( g < 0 ) || ( b < 0 ) || ( a < 0 ) )
	{
		cout << "bzlib: Invalid Tint: " << r << " " << g << " " << b << endl;
		cout << "     : All values must be non-negative." << endl;
		exit(1);
	}
	if ( ( r > 1 ) || ( g > 1 ) || ( b > 1 ) || ( a > 1 ) )
	{
		cout << "bzlib: Invalid Tint: " << r << " " << g << " " << b << endl;
		cout << "     : All values must be less than or equal to one." << endl;
		exit(1);
	}

	/* Assignment */	
	std::string tintString;
	tintString = "";
	strdbla( tintString, r );
	tintString += " ";
	strdbla( tintString, g );
	tintString += " ";
	strdbla( tintString, b );
	tintString += " ";
	strdbla( tintString, a );
	tint = tintString;
}

void Group::setTint( double r, double g, double b )
//Precondition:  none
//Function:      "Tints" the objects in the group.
{
	setTint( r, g, b, 1 );
}

void Group::setScale( double scalex, double scaley, double scalez )
//Precondition:  none
//Function:      Scales the objects.
{
	this->scalex = scalex;
	this->scaley = scaley;
	this->scalez = scalez;
}

void Group::setLocation( Point p )
//Precondition:  none
//Function:      Sets the position variable.
{
	shift = p;
}

void Group::setTeam( std::string team )
//Precondition:  none
//Function:	 Adds a team to a group.
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
		cout << "bzlib: Invalid Team in Group: " << team << endl;
		cout << "     : Acceptable teams: BLUE, RED, GREEN, PURPLE, and ROGUE." << endl;
		exit(1);
	}	
}

void Group::setSpin( double angle, Point p )
//Precondition:  none
//Function:      Sets the rotation variable.
{
	rotation = angle;
	spinPoint = p;
}

void Group::Make()
//Precondition:  none
//Function:      Makes the group with the given features.
{
	std::ofstream fout;
	fout.open( TEMPFILE, std::ios::app );
	
	fout << indent << "group " << name << endl;
	fout << indent << "  #name " << name << endl;
	if ( ( shift.x != 0 ) || ( shift.y != 0 ) || ( shift.z != 0 ) )
		fout << indent << "  shift " << shift.x << " " << shift.y << " " << shift.z << endl;
	if ( rotation != 0 )
		fout << indent << "  spin " << rotation << " " << spinPoint.x << " " << spinPoint.y << " " << spinPoint.z << endl;
	if ( ( scalex != 0 ) || ( scaley != 0 ) || ( scalez != 0 ) )
		fout << indent << "  scale " << scalex << " " << scaley << " " << scalez << endl;
	if ( teamStr != "" )
		fout << indent << "  team " << teamStr << endl;
	if ( color != "" )
		fout << indent << "  color " << color << endl;
	if ( tint != "" )
		fout << indent << "  tint " << tint << endl;
	
	fout << indent << "end\n";
	
	fout.close();
}
