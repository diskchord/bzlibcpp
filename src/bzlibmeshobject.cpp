/**********************************************************************/
//Author: Alex Peppe
//File: bzlibmeshobject.cpp
//
//Contains the MeshObject class definitions.
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
#include "bzlibshared.h"

MeshObject::MeshObject()
//Precondition:  none
//Function:      Sets up the object.
{
	physics = "";
	dynTex = "";
	dynCol = "";
	mat = "";
	matTemp = "";
	col = "1 1 1 1";
	tex = "mesh";
	spheremap = false;
	texSizeAdded = false;
	topTex = false;
	bottomTex = false;
	outsideTex = false;
	insideTex = false;
	startTex = false;
	endTex = false;
}

MeshObject::MeshObject( Point p1, Point p2 )
//Precondition:  none
//Function:      Sets up the object using Points provided by the 
//		 user.
{
	physics = "";
	dynTex = "";
	dynCol = "";
	mat = "";
	matTemp = "";
	col = "1 1 1 1";
	tex = "mesh";
	spheremap = false;
	texSizeAdded = false;
	topTex = false;
	bottomTex = false;
	outsideTex = false;
	insideTex = false;
	startTex = false;
	endTex = false;
	setLocation( p1, p2 );
	setRotation( 0 );
}

std::string MeshObject::getPhysics()
//Precondition:  none
//Function:      Returns the physics string.
{
	return physics;
}

void MeshObject::setSide( std::string side, MeshObject details )
//Precondition:  none
//Function:      Makes a face.
{
	std::string physicsID = "";
        std::string textureID = "";
        std::string dyncolID = "";
        std::string matID = "";
        details.makeSetup( physicsID, textureID, dyncolID, matID );
	
        if (side == STARTSIDE)
        {
                startTex = true;
                startTexID = matID;
        }
        else if (side == ENDSIDE)
        {
                endTex = true;
                endTexID = matID;
        }
        else if (side == TOP)
        {
                topTex = true;
                topTexID = matID;
        }
        else if (side == BOTTOM)
        {
                bottomTex = true;
                bottomTexID = matID;
        }
        else if (side == INSIDE)
        {
                insideTex = true;
                insideTexID = matID;
        }
        else if (side == OUTSIDE)
        {
                outsideTex = true;
                outsideTexID = matID;
        }
}

void MeshObject::setEmission( double r, double g, double b, double a )
//Precondition:  r, g, b, and a are non-negative doubles.
//Function:      Sets an object's emissive color.
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

	/* Check for 0 */
	if ( ( r == 0 ) && ( g == 0 ) && ( b == 0 ) )
		return;

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
        emi = colorString;
}

void MeshObject::setEmission( double r, double g, double b )
//Precondition:  r, g, b, and a are non-negative doubles.
//Function:      Sets an object's emissive color.
{
	setEmission( r, g, b, 1 );
}

void MeshObject::setAmbiance( double r, double g, double b, double a )
//Precondition:  r, g, b, and a are non-negative doubles.
//Function:      Sets an object's ambient color.
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
        amb = colorString;
}

void MeshObject::setAmbiance( double r, double g, double b )
//Precondition:  r, g, b, and a are non-negative doubles.
//Function:      Sets an object's ambient color.
{
        setAmbiance( r, g, b, 1 );
}

void MeshObject::setSpecular( double r, double g, double b, double a )
//Precondition:  r, g, b, and a are non-negative doubles.
//Function:      Sets an object's specular color.
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
        spec = colorString;
}

void MeshObject::setSpecular( double r, double g, double b )
//Precondition:  r, g, b, and a are non-negative doubles.
//Function:      Sets an object's specular color.
{
        setSpecular( r, g, b, 1 );
}

void MeshObject::setColor( double r, double g, double b, double a )
//Precondition:  r, g, b, and a are non-negative doubles.
//Function:      Sets an object's color.
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
	if ( ( r == 1 ) && ( g == 1 ) && ( b == 1 ) && ( a == 1 ) )
	{
		return;
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
	col = colorString;
}

void MeshObject::setColor( double r, double g, double b )
//Precondition:  r, g, b, and a are non-negative doubles.
//Function:      Sets an object's color. This function does so
//		 without requesting an alpha value from the user.
{
	setColor( r, g, b, 1 );
}


void MeshObject::setTexture( std::string tex )
//Precondition:  none
//Function:      Takes in a texture and uses addMaterial to insert
//               it.
{
	this->tex = trim( tex );
}

void MeshObject::setTexture( std::string side, std::string textureStr )
//Precondition:  none
//Function:      Takes in a texture and uses addMaterial to insert
//               it.
{
	if (!texSizeAdded)
	{
		cout << "bzlib: A texture size has not been added to object " << name << ", which\n";
		cout << "     : is necessary for adding textures to a specific side.\n";
		cout << "     : Defaulting to 100, 10, 1, 1.\n\n";
		setTexSize( 100, 10, 1, 1 );
	}

	std::string matStr = "material\n  texture " + textureStr + "\n";
	std::string matID = world.addMaterial( matStr, "", "" );

	if (side == STARTSIDE)
	{
		startTex = true;
		startTexID = matID;
	}
	else if (side == ENDSIDE)
	{
		endTex = true;
		endTexID = matID;
	}
	else if (side == TOP)
	{
		topTex = true;
		topTexID = matID;
	}
	else if (side == BOTTOM)
	{
		bottomTex = true;
		bottomTexID = matID;
	}
	else if (side == INSIDE)
	{
		insideTex = true;
		insideTexID = matID;
	}
	else if (side == OUTSIDE)
	{
		outsideTex = true;
		outsideTexID = matID;
	}
}

void MeshObject::addSphereMap()
//Precondition:  none
//Function:      Adds spheremap to an object.
{
	spheremap = true;
}

void MeshObject::addPhysicsRotation( double speed, Point around )
//Precondition:  none
//Function:      Adds a physics setting to the future physics driver.
{
	
	physics += "  angular ";
	
	strdbla( physics, speed );
	physics += " ";
	strdbla( physics, around.x );
	physics += " ";
	strdbla( physics, around.y );
	
	strdbla( physicsID[0], speed );
	physicsID[0] += "_";
	strdbla( physicsID[0], around.x );
	physicsID[0] += "_";
	strdbla( physicsID[0], around.y );
	physicsID[0] += "_";
	strdbla( physicsID[0], around.z );
	physicsID[0] += "_";

	physics += "\n";
}

void MeshObject::addPhysicsSlide( double speed )
//Precondition:  speed is expected to be non-negative.
//Function:      Adds a physics setting to the future physics driver.
{
	physics += "  slide ";
	strdbla( physics, speed );
	physics += "\n";

	strdbla( physicsID[1], speed );
	physicsID[1] += "_";
}

void MeshObject::addPhysicsDeath( std::string message )
//Precondition:  none
//Function:      Adds a physics setting to the future physics driver.
{
	physics += "  death " + message + "\n";
	physicsID[2] += message[0] + message[message.length() - 1] + "_";
}

void MeshObject::addPhysicsLinear( double speedX, double speedY, double speedZ )
//Precondition:  none
//Function:      Adds a physics setting to the future physics driver.
{
	physics += "  linear ";
	strdbla( physics, speedX );
	physics += " ";
	strdbla( physics, speedY );
	physics += " ";
	strdbla( physics, speedZ );
	physics += "\n";

	strdbla( physicsID[3], speedX );
	physicsID[3] += "_";
	strdbla( physicsID[3], speedY );
	physicsID[3] += "_";
	strdbla( physicsID[3], speedZ );
}

void MeshObject::addDynamicTexture( std::string dynTex )
//Precondition:  none
//Function:      Sets the dynTex variable.
{
	this->dynTex += "  " + trim( dynTex ) + "\n";
}

void MeshObject::addDynamicColor( std::string dynCol )
//Precondition:  none
//Function:      Sets the dynCol variable.
{
	this->dynCol += "  " + trim( dynCol ) + "\n";
}

void MeshObject::addMaterial( std::string toAdd )
//Precondition:  none
//Function:      Sets the mat variable.
{
	toAdd = trim( toAdd );
	if ( equalIgnoreCase( toAdd.substr( 0, 5 ), "color" ) )
		col = toAdd.substr( 6 );
	else if ( equalIgnoreCase( toAdd.substr( 0, 7 ), "texture" ) )
		tex = toAdd.substr( 8 );
	else if ( equalIgnoreCase( toAdd.substr( 0, 9 ), "spheremap" ) )
		spheremap = true;
	else if ( equalIgnoreCase( toAdd.substr( 0, 7 ), "texsize" ) )
		addRaw( toAdd.substr( 8 ) );
	else
		matTemp += "  " + toAdd + "\n";
}

void MeshObject::useMaterial( std::string newMaterial )
//Precondition:  none
//Function:      Allows the user to "force" a material on an object.
//		 This is not recommended. The internal systems do
//		 a much better job, and are much more reliable.
{
	std::string materialString;
	addRaw( "matref " + newMaterial );
}

void MeshObject::setTexSize( double i, double j, double k, double l )
//Precondition:  none
//Function:      Allows the user to "force" a texture size.
{
	std::string texsize = "texsize ";
	strdbla( texsize, i );
	texsize += " ";
	strdbla( texsize, j );
	texsize += " ";
	strdbla( texsize, k );
	texsize += " ";
	strdbla( texsize, l );
	addRaw( texsize );

	texSizeAdded = true;
}

void MeshObject::makeSetup( std::string& physicsID, std::string& textureID, std::string& dyncolID, std::string& matID )
//Precondition:  none
//Function:      A group of commands used by all MeshObjects in
//               their Make() functions.
//               Creates the different materials, textures, and such
//               needed by an object and returns their ID's by
//               reference.
{
	std::string textureMat = "";
	std::string dyncolMat = "";
	
	/* Color */
	if ( col != "" && col != "1 1 1 1" )
	{
		mat += "  color " + col + "\n";
		col = "";
	}
	if ( emi != "" )
	{
		mat += "  emission " + emi + "\n";
		emi = "";
	}
	if ( amb != "" )
	{
		mat += "  ambient " + amb + "\n";
		amb = "";
	}
	if ( spec != "" )
	{
		mat += "  specular " + spec + "\n";
		spec = "";
	}

	/* Texture */
	if ( ( tex != "" ) && !spheremap )
	{
		mat += "  texture " + tex + "\n";
		tex = "";
	}
	else if ( ( tex != "" ) && spheremap )
	{
		mat += "  addtexture " + tex + "\n";
		tex = "";
	}
	
	/* User added material stuff */
	if ( matTemp != "" )
	{
		mat += matTemp;
		matTemp = "";
	}

	/* Spheremap */
	if ( spheremap )
	{
		mat += "  spheremap\n";
		spheremap = false;
	}

	/* Physics */
	if (physics != "")
	{
		std::string physicsStr = "";
		physicsStr += "physics\n";
		physicsStr += physics;
		physicsID = world.addPhysics( physicsStr );
	}

	/* Dynamic Texture */
	if (dynTex != "")
	{
		std::string textureStr = "";
		textureStr += "textureMatrix\n";
		textureStr += dynTex;
		textureID = world.addTexture( textureStr );
	}
	
	/* Dynamic Color*/
	if (dynCol != "")
	{
		std::string dyncolStr = "";
		dyncolStr += "dynamicColor\n";
		dyncolStr += dynCol;
		dyncolID = world.addDynamicColor( dyncolStr );
	}
	
	/* Material */
	if (mat != "")
	{
		std::string matStr = "material\n";
		matStr += mat;
		matID = world.addMaterial( matStr, textureID, dyncolID );
	}
}
