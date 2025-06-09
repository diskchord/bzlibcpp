/**********************************************************************/
//Author: Alex Peppe
//File: bzlibmeshobject.h
//
//Contains the MeshObject definition.
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

#ifndef __MESHOBJECT_CLASS
#define __MESHOBJECT_CLASS

#include <iostream>
#include <fstream>
#include <string>

#include "bzlibworld.h"
#include "bzlibpoint.h"
#include "bzlibobjects.h"
#include "bzlibshared.h"

class MeshObject : public Object
{
public:
	MeshObject();
	MeshObject( Point, Point );

	std::string getPhysics();
	//Precondition:  none
	//Function:      Returns the physics string.

	void setSide( std::string, MeshObject );
	//Precondition:  none
	//Function:      Makes a face.

	void setEmission( double, double, double );
        //Precondition:  r, g, b, and a are non-negative doubles.
        //Function:      Sets an object's emissive color.

	void setEmission( double, double, double, double );
        //Precondition:  r, g, b, and a are non-negative doubles.
        //Function:      Sets an object's emissive color.

        void setAmbiance( double, double, double );
        //Precondition:  r, g, b, and a are non-negative doubles.
        //Function:      Sets an object's ambient color.

        void setAmbiance( double, double, double, double );
        //Precondition:  r, g, b, and a are non-negative doubles.
        //Function:      Sets an object's ambient color.

        void setSpecular( double, double, double );
        //Precondition:  r, g, b, and a are non-negative doubles.
        //Function:      Sets an object's specular color.

        void setSpecular( double, double, double, double );
        //Precondition:  r, g, b, and a are non-negative doubles.
        //Function:      Sets an object's specular color.

	void setColor( double, double, double, double );
	//Precondition:  r, g, b, and a are non-negative doubles.
	//Function:      Sets an object's color.
	
	void setColor( double, double, double );
	//Precondition:  r, g, b, and a are non-negative doubles.
	//Function:      Sets an object's color. This function does so
	//		 without requesting an alpha value from the user.

	void setTexture( std::string );
	//Precondition:  none
	//Function:      Takes in a texture and uses addMaterial to insert
	//               it.

	void setTexture( std::string, std::string );
	//Precondition:  none
	//Function:      Takes in a texture and uses addMaterial to insert
	//               it.
	
	void addSphereMap();
	//Precondition:  none
	//Function:      Adds spheremap to an object.
	
	void addPhysicsRotation( double, Point );
	//Precondition:  none
	//Function:      Adds a physics setting to the future physics driver.

	void addPhysicsSlide( double );
	//Precondition:  speed is expected to be non-negative.
	//Function:      Adds a physics setting to the future physics driver.

	void addPhysicsDeath( std::string );
	//Precondition:  none
	//Function:      Adds a physics setting to the future physics driver.

	void addPhysicsLinear( double, double, double );
	//Precondition:  none
	//Function:      Adds a physics setting to the future physics driver.

	void addDynamicTexture( std::string );
	//Precondition:  none
	//Function:      Sets the dynTex variable.
	
	void addDynamicColor( std::string );
	//Precondition:  none
	//Function:      Sets the dynCol variable.

	void addMaterial( std::string );
	//Precondition:  none
	//Function:      Sets the mat variable. This is not wise. It is far
	//               better to use an already available addition command.
	//               This should ONLY be used when the necessary device
	//               had not yet been implemented.

	void useMaterial( std::string );
	//Precondition:  none
	//Function:      Allows the user to "force" a material on an object.
	//		 This is not recommended. The internal systems do
	//		 a much better job, and are much more reliable.

	void setTexSize( double, double, double, double );
	//Precondition:  none
	//Function:      Allows the user to "force" a texture size.
	
	void makeSetup( std::string& physicsID, std::string& textureID, std::string& dyncolID, std::string& matID );
	//Precondition:  none
	//Function:      A group of commands used by all MeshObjects in
	//               their Make() functions.
	               
protected:
	std::string physics;
	std::string physicsID[4];
	std::string dynTex;
	std::string dynTexID;
	std::string dynCol;
	std::string dynColID;
	std::string mat;
	std::string matTemp;
	std::string col;
	std::string emi;
	std::string amb;
	std::string tex;
	std::string spec;
	bool spheremap;
	bool texSizeAdded;
	bool topTex;
	bool bottomTex;
	bool outsideTex;
	bool insideTex;
	bool startTex;
	bool endTex;
	std::string topTexID;
	std::string bottomTexID;
	std::string outsideTexID;
	std::string insideTexID;
	std::string startTexID;
	std::string endTexID;
};

#endif
