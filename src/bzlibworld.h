/**********************************************************************/
//Author: Alex Peppe
//File: bzlibworld.h
//
//Contains the World class prototypes.
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

#ifndef __WORLD_CLASS
#define __WORLD_CLASS

#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <vector>
#include <string>
#include <time.h>

using namespace std;

#include "bzlibmaterial.h"

class World
{
public:
	World();
	~World();
	
	void setSize( double );
	//Precondition:  none
	//Function:	 Sets the size variable.

	void setGroundTexture( std::string );
	//Precondition:  none
	//Function:	 Sets the groundTexture variable.

	void setGroundColor( double, double, double );
	//Precondition:  none
	//Function:	 Sets the groundColor variable.

	void setWaterLevel( double );
	//Precondition:  none
	//Function:	 Sets the waterLevel variable.

	void addOption( std::string );
	//Precondition:  none
	//Function:	 Adds to the options variable.

	void addSetting( std::string );
	//Precondition:  none
	//Function:	 Adds a setting to the options variable.

	void addRain( std::string type, std::string texture, int density );
	//Precondition:  none
	//Function:	 Adds rain.

	void addMessage( std::string, std::string );
	//Precondition:  none
	//Function:	 Adds srvmsg or admsg to the options variable.

	void setFileName( std::string );
	//Precondition:  none
	//Function:	 Sets the filename that the map will be written to.

	void addHelp( std::string, std::string );
	//Precondition:  none
	//Function:	 Adds a page to help.

	std::string addPhysics( std::string );
	//Precondition:  none
	//Function:	 Adds to the physics variable.

	std::string addTexture( std::string );
	//Precondition:  none
	//Function:	 Adds to the textures variable.

	std::string addDynamicColor( std::string );
	//Precondition:  none
	//Function:	 Adds dynamic color.

	void addFlag( std::string, int, int );
	//Precondition:  none
	//Function:	 Adds a flag to the options variable. Requests max
	//		 number of shots.

	void addFlag( std::string, int );
	//Precondition:  none
	//Function:	 Adds a flag to the options variable.

	std::string addMaterial( std::string, std::string, std::string );
	//Precondition:  none
	//Function:	 Adds a material for an object.
	
	int Make();
	//Precondition:  none
	//Function:      Adds the world. Also adds any drivers, materials, 
	//		 or dynamic colors that the objects in the world need.

	std::string workingDir;
	std::string divider;

private:
	double size;	
	std::string help;
	std::string fileName;
	std::string groundTexture;
	std::string groundColor;
	std::string options;
	std::string physics;			//Deprecated (?)
	std::string textures;			//Deprecated (?)
	std::string flagList;	
	std::string dynamicColor;               //Deprecated (?)
	std::vector<Material> materials;     
	std::vector<Material> materialsPreFeatures;
	std::vector<string> MATtexList;
	std::vector<string> MATdyncolList;
	std::vector<string> physicsList; 
	std::vector<string> physicsListPreFeatures; 
	std::vector<string> textureList;         
	std::vector<string> textureListPreFeatures;
	std::vector<string> dyncolList;           
	std::vector<string> dyncolListPreFeatures;
	double startTime;
	int flagCount;
	double waterLevel;
	bool ground;
};

#endif
