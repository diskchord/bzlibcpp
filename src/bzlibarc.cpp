/**********************************************************************/
//Author: Alex Peppe
//File: bzlibarc.cpp
//
//Contains the definitions of the Arc class functions.
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

Arc::Arc()
//Precondition:  none
//Function:      Sets up the object.
{
	ratio = 1;
	angle = 0;
	divisions = 0;
}

Arc::Arc( Point p1, Point p2 )
//Precondition:  none
//Function:      Sets up the object using Points provided by the 
//				 user.
{
	ratio = 1;
	angle = 0;
	divisions = 0;
	setLocation( p1, p2 );
	setRotation( 0 );
}

void Arc::setRatio( double ratio )
//Precondition:  none
//Function:      Sets the ratio variable.
{
	this->ratio = ratio;
}

void Arc::setAngle( double angle )
//Precondition:  none
//Function:      Sets the angle variable.
{
	this->angle = angle;
}

void Arc::setDivisions( int divisions )
//Precondition:  none
//Function:      Sets the divisions variable.
{
	this->divisions = divisions;
}

void Arc::Make()
//Precondition:  none
//Function:      Adds the object to the world. Also adds any drivers,
//		 materials, or dynamic colors that the object needs.
{

	/* NOTE: All of this information is outputted to a temporary 
	   file. The actual information is placed in the map file when
	   the world object runs its Make() function. */

	/* Variables */
	std::string fileName = TEMPFILE; //Temporary file
	std::ifstream fin;
	std::ofstream fout;
	arcs++;

	/* Position, size, and rotation */
	double px, py, pz;
	getPosition( px, py, pz );
	
	double sx, sy, sz;
	getSize( sx, sy, sz );

	double rot;
	getRotation( rot );
	
	std::string physicsID = "";
	std::string textureID = "";
	std::string dyncolID = "";
	std::string matID = "";
	makeSetup( physicsID, textureID, dyncolID, matID );

	fout.open( fileName.c_str(), std::ios::app );

	/* Object Syntax */
	fout << indent << "Arc\n";
	fout << indent << "  #name " << name << "\n";
	fout << indent << "  position " << px << " " << py << " " << pz << "\n";
	fout << indent << "  size " << sx << " " << sy << " " << sz << "\n";
	if ( rotation )
		fout << indent << "  rotation " << rot << "\n";
	if ( ( ratio < 1 ) && ( ratio > 0 ) )
		fout << indent << "  ratio " << ratio << "\n";
	if ( angle )
		fout << indent << "  angle " << angle << "\n";
	if ( divisions )
		fout << indent << "  divisions " << divisions << "\n";
	if ( raw != "" )
		fout << raw;
	if ( physicsID != "" )
		fout << indent << "  phydrv " << physicsID << "\n";
	if ( matID != "" )
	{
		if ( topTex || bottomTex || startTex || endTex || insideTex || outsideTex )
		{	
			if (!texSizeAdded)
				setTexSize( 100, 10, 1, 1 );

			/* Top */
			if (!topTex)
				fout << indent << "  top matref " << matID << "\n";
			else
				fout << indent << "  top matref " << topTexID << "\n";
			
			/* Bottom */
			if (!bottomTex)
				fout << indent << "  bottom matref " << matID << "\n";
			else
				fout << indent << "  bottom matref " << bottomTexID << "\n";
			
			/* Start */
			if (!startTex)
				fout << indent << "  startside matref " << matID << "\n";
			else
				fout << indent << "  startside matref " << startTexID << "\n";
			
			/* End */
			if (!endTex)
				fout << indent << "  endside matref " << matID << "\n";
			else
				fout << indent << "  endside matref " << endTexID << "\n";			

			/* Inside */
			if (!insideTex)
				fout << indent << "  inside matref " << matID << "\n";
			else
				fout << indent << "  inside matref " << insideTexID << "\n";

			/* Outside */
			if (!outsideTex)
				fout << indent << "  outside matref " << matID << "\n";
			else
				fout << indent << "  outside matref " << outsideTexID << "\n";
		}
		else
			fout << indent << "  matref " << matID << "\n";
	}

	fout << indent << "end\n";

	name = "ob";
	strinta( name, nameIncrement() );

	fout.close();
}
