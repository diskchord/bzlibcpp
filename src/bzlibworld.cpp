/**********************************************************************/
//Author: Alex Peppe
//File: bzlibworld.cpp
//
//Contains the World definitions.
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

World::World()
{
	#ifdef RUNTIME_OUTPUT
		cout << VERSION << "\n";
	#endif

	/**********************************************************************
	Initialize time and random numbers.
	**********************************************************************/	
	startTime = double( time( NULL ) );
	srand( time( NULL ) );
	setSize( 600 );
	
	/**********************************************************************
	Set variables to defaults. 
	**********************************************************************/
	groundTexture = "";
	groundColor = "";
	fileName = "map.bzw";
	options = "";
	help = "";
	workingDir = ".";
	divider = "/";
	physics = "";
	textures = "";
	flagCount = 0;
        flagList = "";
        dynamicColor = "";
        waterLevel = -1;
	ground = false;

	/**********************************************************************
	Make sure that all temporary files are absolutely empty.
	**********************************************************************/ 
	std::ofstream fout;
	fout.open( HELPFILE );
	fout.close();
	fout.open( NAMEFILE );
	fout.close();
	fout.open( TEMPFILE );
	fout.close();
	fout.open( LINKFILE );
	fout.close();
	fout.open( LISTFILE );
	fout.close();
}

World::~World()
{
	/**********************************************************************
	Put it all into the map file.
	**********************************************************************/	
	Make();

	/**********************************************************************
	Remove all of the temporary files.
	**********************************************************************/
	remove( HELPFILE );
	remove( NAMEFILE );
	remove( TEMPFILE );
	remove( LINKFILE );
	remove( LISTFILE );
}

void World::setSize( double size )
//Precondition:  none
//Function:	 Sets the size variable.
{
	this->size = size;
}

void World::setGroundTexture( std::string groundTexture )
//Precondition:  none
//Function:	 Sets the groundTexture variable.
{
	this->groundTexture = groundTexture;
}

void World::setGroundColor( double r, double g, double b )
//Precondition:  none
//Function:	 Sets the groundColor variable.
{
	/* Error Detection */
	if ( ( r < 0 ) || ( g < 0 ) || ( b < 0 ) )
	{
		cout << "bzlib: Invalid Color: " << r << " " << g << " " << b << endl;
		cout << "     : All values must be non-negative." << endl;
		exit(1);
	}
	
	/* Set ground color */
	groundColor = "";
	strdbla( groundColor, r );
	groundColor += " ";
	strdbla( groundColor, g );
	groundColor += " ";
	strdbla( groundColor, b );
	groundColor += " ";
	strinta( groundColor, 1 );
}

void World::addOption( std::string newOption )
//Precondition:  none
//Function:	 Adds to the options variable.
{
	options += "  " + newOption + "\n";
}

void World::addSetting( std::string newSetting )
//Precondition:  none
//Function:	 Adds a setting to the options variable.
{
	options += "  -set " + trim( newSetting ) + "\n";
}

void World::addRain( std::string type, std::string texture, int density )
//Precondition:  none
//Function:	 Adds rain.
{
	/* Check size */
	#ifndef DO_NOT_WATCH_FOR_BZFLAG_BUGS
		if ( ( size / density ) < 1.5 )
		{
			cout << "bzlib: You have added a very large amount of rain. Are" << endl;
			cout << "     : you sure you want to do this? (May cause performance" << endl;
			cout << "     : issues.)" << endl;
		}
	#endif

	/* Add to options */
	options += "  -set _rainType " + trim( type ) + "\n";
	options += "  -set _rainTexture " + trim( texture ) + "\n";
	options += "  -set _rainDensity ";
        strinta( options, density );
	options += "\n";
}

void World::addMessage( std::string type, std::string contents )
//Precondition:  none
//Function:	 Adds srvmsg or admsg to the options variable.
{
	if ( type == "admsg" )
		options += "  -admsg \"" + contents + "\"\n";
	else if ( type == "srvmsg" )
		options += "  -srvmsg \"" + contents + "\"\n";
	else
	{
		cout << "bzlib: Invalid type for addMessage(): " << type << endl;
		cout << "     : Acceptable terms are \"admsg\" and \"srvmsg\"" << endl;
		exit(1);
	}
}

void World::setFileName( std::string fileName )
//Precondition:  none
//Function:      Sets the filename that the map will be written to.
{
	this->fileName = fileName;
}

void World::addHelp( std::string pageName, std::string page )
//Precondition:  none
//Function:      Adds a page to help.
{
	/* Insert help file name */
	std::string helpFileName = workingDir;
	if ( workingDir[ workingDir.length() - 1 ] != '/' )
	        helpFileName += divider;
        helpFileName += pageName;
        helpFileName += ".txt";
	std::ofstream fout;

	/* Output text to file */
	fout.open( helpFileName.c_str() );
	fout << page;
	fout.close();

	/* Output page names to help file */
	fout.open( HELPFILE, std::ios::app );
	fout << helpFileName << " " << pageName << "\n";
	fout.close();
}	

std::string World::addPhysics( std::string physicsToAdd )
//Precondition:  none
//Function:      Adds to the physics variable.
{
	for( int i = 0; i < numOfPhysics; i++ )
		if ( physicsListPreFeatures[i] == physicsToAdd )
		{
			std::string returnStr = "phy";
			strinta( returnStr, i );
			return returnStr;
		}

	physicsListPreFeatures.push_back( physicsToAdd );

	std::string returnStr;
	
	returnStr = "phy";
	strinta( returnStr, numOfPhysics );
	physicsToAdd += "  name " + returnStr + "\n";
	physicsToAdd += "end\n\n";
	physicsList.push_back( physicsToAdd );
	numOfPhysics++;
	
	return returnStr;
}

std::string World::addTexture( std::string textureToAdd )
//Precondition:  none
//Function:      Adds to the textures variable.
{
	for( int i = 0; i < numOfTextures; i++ )
		if ( textureListPreFeatures[i] == textureToAdd )
		{
			std::string returnStr = "tex";
			strinta( returnStr, i );
			return returnStr;
		}

	textureListPreFeatures.push_back( textureToAdd );
	
	std::string returnStr;

	returnStr = "tex";
	strinta( returnStr, numOfTextures );
	textureToAdd += "  name " + returnStr + "\n";
	textureToAdd += "end\n\n";
	textureList.push_back( textureToAdd );
	numOfTextures++;
	
	return returnStr;
}

std::string World::addDynamicColor( std::string colToAdd )
//Precondition:  none
//Function:	 Adds dynamic color.
{
	for( int i = 0; i < numOfDynCols; i++ )
		if ( dyncolListPreFeatures[i] == colToAdd )
		{
			std::string returnStr = "dyn";
			strinta( returnStr, i );
			return returnStr;
		}

	std::string returnStr;
	
	dyncolListPreFeatures.push_back( colToAdd );
	
	returnStr = "dyn";
	strinta( returnStr, numOfDynCols );
	colToAdd += "  name " + returnStr + "\n";
	colToAdd += "end\n\n";
	dyncolList.push_back( colToAdd );
	numOfDynCols++;
	
	return returnStr;
}

void World::addFlag( std::string flag, int num, int max )
//Precondition:  none
//Function:      Adds a flag to the options variable.
{
	static bool questionValue = true;
	options += "  +f " + flag + "{";
	strinta( options, num );
	options += "}\n  -sl " + flag + " ";
	strinta( options, max );
	options += "\n";
	flagList += flag + " ";

	#ifndef DO_NOT_WATCH_FOR_BZFLAG_BUGS
		if ( num >= 40 && questionValue )
		{
			std::cout << "bzlib: Please be aware that adding 40 flags or more of a particular\n";
			std::cout << "       type may prevent this map from being served on some platforms.\n";
			std::cout << "       Please note that this is not our fault.\n";
			questionValue = false;
		}
	#endif

	flagCount += num;
}

void World::addFlag( std::string flag, int num )
//Precondition:  none
//Function:      Adds a flag to the options variable.
{
	static bool questionValue = true;
	options += "  +f " + flag + "{";
	strinta( options, num );
	options += "}\n";
	
	#ifndef DO_NOT_WATCH_FOR_BZFLAG_BUGS
		if ( num >= 40 && questionValue )
		{
			std::cout << "bzlib: Please be aware that adding 40 flags or more of a particular\n";
			std::cout << "       type may prevent this map from being served on some platforms.\n";
	                std::cout << "       Please note that this is not our fault.\n";
			questionValue = false;
		}
	#endif
	
	flagCount += num;
}

std::string World::addMaterial( std::string materialToAdd, std::string tex, std::string dyncol )
//Precondition:  none
//Function:	 Adds a material for an object.
{
	/* If the material already exists, it uses it. This is very
	   important, since materials with the same contents and
	   different names are not allowed by BZFS. */

	if ( tex != "" )
		materialToAdd += "  texmat " + tex + "\n";
	if ( dyncol != "" )
		materialToAdd += "  dyncol " + dyncol + "\n";
	
	for( int i = 0; i < numOfMaterials; i++ )
		if ( materialsPreFeatures[i].getContents() == materialToAdd )
		{
			if (!ground)
			{
				std::string returnStr = "mat";
				strinta( returnStr, i );
				return returnStr;
			}
			else
			{
				cout << "bzlib: Invalid ground material. Conflicts with others. Change settings.\n";
				exit(1);
			}
		}

	std::string returnStr = "mat";

	/**********************************************************************
	Add to the materialsPreFeatures vector.
	**********************************************************************/
	Material newMaterial;
	newMaterial.setContents( materialToAdd );
	materialsPreFeatures.push_back( newMaterial );

	/**********************************************************************
	Add to texture and dynamic color lists
	**********************************************************************/
	MATtexList.push_back( tex );
	MATdyncolList.push_back( dyncol );

	numOfMaterials++;
	strinta( returnStr, numOfMaterials - 1 );

	/**********************************************************************
	Do the ground texture
	**********************************************************************/
	if (!ground)
		materialToAdd += "  name " + returnStr + "\n";
	else
		materialToAdd += "  name GroundMaterial\n";
	materialToAdd += "end\n\n";
	
	/**********************************************************************
	Add to the materials vector.
	**********************************************************************/
	newMaterial.setContents( materialToAdd );
	materials.push_back( newMaterial );
	
	return returnStr;
}

void World::setWaterLevel( double waterLevel )
//Precondition:  none
//Function:	 Sets the waterLevel variable.
{
	this->waterLevel = waterLevel;
}

int World::Make()
//Precondition:  none
//Function:      Adds the world. Also adds any drivers, materials, 
//		 or dynamic colors that the objects in the world need.
{
	std::ofstream fout;
	std::ifstream fin;
	std::string toOpen;
	std::string page;

	/**********************************************************************
	Help Files
	**********************************************************************/
	fin.open( HELPFILE );
	fin >> toOpen;
	fin >> page;
	while( fin )
	{
	        std::string optionString = "-helpmsg ";
		optionString += "\"" + toOpen + "\"";
		optionString += " ";
		optionString += page;
		addOption( optionString );
		fin >> toOpen;
		fin >> page;
	}
	fin.close();

	/**********************************************************************
	Look for bugs
	**********************************************************************/

	#ifndef DO_NOT_WATCH_FOR_BZFLAG_BUGS
		if ( flagCount > 400 )
		{
			std::cout << "bzlib: You have WAY too many flags. BZFS probably won't\n";
			std::cout << "       let people sign in.\n";
		}
		else if ( flagCount > 200 )
		{
			std::cout << "bzlib: This is an awful lot of flags for BZFlag to handle.\n";
			std::cout << "       You should probably cut your number.\n";
		}
	#endif

	/**********************************************************************
	Grab the filename
	**********************************************************************/
	fout.open( NAMEFILE );
	fout << fileName;
	fout.close();
    
	fout.open( fileName.c_str() );

	fout << "################################################################\n";
	fout << "#Made with                                                     #\n";
        fout << "#                                                              #\n";
        fout << "#          ____ _______      _ _                               #\n";
        fout << "#         |  _ \\___  / |    (_) |     _____                    #\n";
        fout << "#         | |_) | / /| |     _| |__  / ____|     _             #\n";
        fout << "#         |  _ < / / | |    | | '_ \\| |  _| |_ _| |_           #\n";
        fout << "#         | |_) / /__| |____| | |_) | | |_   _|_   _|          #\n";
        fout << "#         |____/_____|______|_|_.__/| |___|_|   |_|            #\n";
        fout << "#                                    \\_____|                   #\n";
        fout << "#                                                              #\n";
	fout << "#The latest copy of BZLib may be obtained by contacting its    #\n";
	fout << "#creator, Alex Peppe. His email address is                     #\n";
	fout << "#peppe@cs.usm.maine.edu.                                       #\n";
	fout << "#                                                              #\n";
	fout << "#Information about the total number of objects and other       #\n";
	fout << "#statistics may be found at the bottom of the document.        #\n";
	fout << "################################################################\n\n";
	
	fout << "################################################################\n";	
        fout << "#                  ___       _   _                             #\n";
        fout << "#                 / _ \\ _ __| |_(_)___ _ _  ___                #\n";
        fout << "#                | (_) | '_ \\  _| / _ \\ ' \\(_-<                #\n";
        fout << "#                 \\___/| .__/\\__|_\\___/_||_/__/                #\n";
        fout << "#                      |_|                                     #\n";
        fout << "#                                                              #\n";
	fout << "################################################################\n";
			  
	/**********************************************************************
	Options
	**********************************************************************/
	if ( options != "" )
	{
		fout << "options\n";
		fout << options;
		fout << "end\n\n";
	}

	/**********************************************************************
	World
	**********************************************************************/
	fout << "world\n";
	fout << "  size " << size << "\n";
	fout << "end\n\n";
	
	/**********************************************************************
	Water
	**********************************************************************/
	if ( waterLevel >= 0 )
	{
		fout << "waterLevel\n";
		fout << "  name water\n";
		fout << "  height " << waterLevel << "\n";
		fout << "end\n\n";
	}
	
	/**********************************************************************
	Physics
	**********************************************************************/
	if ( numOfPhysics != 0 )
	{
		fout << "#################################################################\n";
	        fout << "#                    ___ _           _                          #\n";
	        fout << "#                   | _ \\ |_ _  _ __(_)__ ___                   #\n";
	        fout << "#                   |  _/ ' \\ || (_-< / _(_-<                   #\n";
	        fout << "#                   |_| |_||_\\_, /__/_\\__/__/                   #\n";
	        fout << "#                            |__/                               #\n";
	 	fout << "#                                                               #\n";
		fout << "#################################################################\n\n";
	}
	for( int i = 0; i < numOfPhysics; i++ )
		fout << physicsList[i];

	/**********************************************************************
	Dynamic Colors
	**********************************************************************/
	if ( numOfDynCols != 0 )
	{
		fout << "#################################################################\n";
	        fout << "#                ___                       _                    #\n";
	        fout << "#               |   \\ _  _ _ _  __ _ _ __ (_)__                 #\n";
	        fout << "#               | |) | || | ' \\/ _` | '  \\| / _|                #\n";
	        fout << "#               |___/ \\_, |_||_\\__,_|_|_|_|_\\__|                #\n";
	        fout << "#                     |__/     _                                #\n";
	        fout << "#                     / __|___| |___ _ _ ___                    #\n";
        	fout << "#                    | (__/ _ \\ / _ \\ '_(_-<                    #\n";
	        fout << "#                     \\___\\___/_\\___/_| /__/                    #\n";
	 	fout << "#                                                               #\n";
		fout << "#################################################################\n\n";
	}
	for( int i = 0; i < numOfDynCols; i++ )
		fout << dyncolList[i];

	/**********************************************************************
	Texture Matrices
	**********************************************************************/
	if ( numOfTextures != 0 )
	{
		fout << "#################################################################\n";
        	fout << "#                 _____        _                                #\n";
	        fout << "#                |_   _|____ _| |_ _  _ _ _ ___                 #\n";
	        fout << "#                  | |/ -_) \\ /  _| || | '_/ -_)                #\n";
	        fout << "#                __|_|\\___/_\\_\\\\__|\\_,_|_| \\___|                #\n";
	        fout << "#               |  \\/  |__ _| |_ _ _(_)__ ___ ___               #\n";
	        fout << "#               | |\\/| / _` |  _| '_| / _/ -_|_-<               #\n";
	        fout << "#               |_|  |_\\__,_|\\__|_| |_\\__\\___/__/               #\n";
		fout << "#                                                               #\n";
		fout << "#################################################################\n\n";
	}
	for( int i = 0; i < numOfTextures; i++ )
		fout << textureList[i];
	
	/**********************************************************************
	Materials
	**********************************************************************/
	if ( numOfMaterials != 0 )
	{
		fout << "################################################################\n";
	        fout << "#              __  __      _           _      _                #\n";
	        fout << "#             |  \\/  |__ _| |_ ___ _ _(_)__ _| |___            #\n";
	        fout << "#             | |\\/| / _` |  _/ -_) '_| / _` | (_-<            #\n";
	        fout << "#             |_|  |_\\__,_|\\__\\___|_| |_\\__,_|_/__/            #\n";
		fout << "#                                                              #\n";
		fout << "################################################################\n\n";
	}

	/* GROUND MATERIAL */	
	if ( ( groundTexture != "" ) || ( groundColor != "" ) )
	{
		std::string groundMat = "material\n";
		if ( groundTexture != "" )
			groundMat += "  texture " + groundTexture + "\n";
		if ( groundColor != "" )
			groundMat += "  color " + groundColor + "\n";
		ground = true;
		addMaterial( groundMat, "", "" );
	}

	for( int i = 0; i < numOfMaterials; i++ )
		fout << materials[i].getContents();
	
	/**********************************************************************
	Objects
	**********************************************************************/

	fout << "################################################################\n";
        fout << "#                   ___  _     _        _                      #\n";
        fout << "#                  / _ \\| |__ (_)___ __| |_ ___                #\n";
        fout << "#                 | (_) | '_ \\| / -_) _|  _(_-<                #\n";
        fout << "#                  \\___/|_.__// \\___\\__|\\__/__/                #\n";
        fout << "#                           |__/                               #\n";
	fout << "#                                                              #\n";
	fout << "################################################################\n\n";
				   
	std::ifstream objectStream;
	std::string tempFile = TEMPFILE;
	std::string transfer = "";
	
	objectStream.open( tempFile.c_str() );
	while( objectStream )
	{
		getline( objectStream, transfer );
		fout << transfer << "\n";
	}
	objectStream.close();

	/* Links */
	std::ifstream linkStream;
	std::string LINKFile = LINKFILE;
	transfer = "";
	
	linkStream.open( LINKFile.c_str() );
	while( linkStream )
	{
		getline( linkStream, transfer );
		fout << transfer << "\n";
	}
	linkStream.close();

	fout << "################################################################\n";
        fout << "#                 #####                                        #\n";
        fout << "#                #     # #####   ##   #####  ####              #\n"; 
        fout << "#                #         #    #  #    #   #                  #\n";
        fout << "#                 #####    #   #    #   #    ####              #\n";
        fout << "#                      #   #   ######   #        #             #\n";
        fout << "#                #     #   #   #    #   #   #    #             #\n";
        fout << "#                 #####    #   #    #   #    ####              #\n";
	fout << "################################################################\n";
	fout << "#There are " << objects << " total objects on this map.\n";
	fout << "#                                                               \n";
	fout << "#Objects                                                        \n";
	fout << "#    Arcs: " << arcs << endl;
	fout << "#    Boxes: " << boxes << endl;
	fout << "#    Cones: " << cones << endl;
	fout << "#    Flags: " << flagCount << endl;
	fout << "#    OldBoxes: " << oldboxes << endl;
	fout << "#    OldPyramids: " << oldpyramids << endl;
	fout << "#    Pyramids: " << pyramids << endl;
	fout << "#    Spheres: " << spheres << endl;
	fout << "#    Teleporters: " << teleporters << endl;
	fout << "#    Zones: " << zones << endl;
	fout << "#Non-Objects                                                      \n";
	fout << "#    Dynamic Colors: " << numOfDynCols << endl;
	fout << "#    Materials: " << numOfMaterials << endl;
	fout << "#    Physics Drivers: " << numOfPhysics << endl;
	fout << "#    Texture Matrices: " << numOfTextures << endl;
	fout << "#                                                                    \n";
	fout << "#Map generation has taken " << double( time( NULL ) ) - startTime << " seconds.\n";
	fout << "################################################################\n";
	fout << "#This map was generated with the C++ BZLib Library, which was  #\n";
	fout << "#created and is run by Alex Peppe. You may email him at        #\n";
	fout << "#peppe@cs.usm.maine.edu for information on where the latest    #\n";
	fout << "#version may be obtained.                                      #\n";
	fout << "################################################################\n";
	
	fout.close();

	FILE * pFile;
	long lSize;
	pFile = fopen ( fileName.c_str(), "rb" );
	if ( pFile == NULL ) 
		exit (1);
	fseek( pFile, 0, SEEK_END );
	lSize = ftell( pFile );
	fclose( pFile );

	std::string fileSize = "";
	strinta( fileSize, int( lSize/1000 ) );

	fileSize += " kilobytes";

	#ifdef RUNTIME_OUTPUT	
		cout << "Map Completed!                                            " << endl;
		cout << "Number of objects: " << objects << endl;
		cout << "File size: " << fileSize << endl;
	#endif
	
	return 0;
}

/******************************************************************************
THIS IS THE
DEFINITION OF THE
WORLD OBJECT!

THIS MUST BE DEFINED
BEFORE THE USE OF
SEVERAL OTHER 
OF THE BZLIB
CLASSES.
******************************************************************************/

World world;
