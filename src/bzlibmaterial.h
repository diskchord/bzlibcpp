/**********************************************************************/
//Author: Alex Peppe
//File: bzlibmaterial.h
//
//Contains the Material class.
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

#ifndef __MATERIAL_CLASS
#define __MATERIAL_CLASS

#include <iostream>
#include <fstream>
#include <string>

class Material
{
public:
	Material();
	Material( std::string );
	
	void setContents( std::string );
	//Precondition:  none
	//Function:	 Adds to the contents variable.
	
	/**********FIXME**********/
	void addColor(std::string);
	void addTexture(std::string);
	/**********\FIXME**********/	

	std::string getContents();
	//Precondition:  none
	//Function:	 Returns the "contents" variable.

	bool operator==( Material );
	//Precondition:  none
	//Function:	 Tests to see if two Materials are equal. Returns 1 if
	//		 this is the case, and 0 otherwise.
	//		 
private:
	std::string color;
	std::string texture;
	std::string contents;
};

#endif
