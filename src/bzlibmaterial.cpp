/**********************************************************************/
//Author: Alex Peppe
//File: bzlibmaterial.cpp
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

#include "bzlib.h"

Material::Material()
{
	contents = "";
}

Material::Material( std::string toAddContents )
{
	contents = "";
	setContents( toAddContents );
}

/**********FIXME**********/
void Material::addColor(std::string newColor)
{
	color = newColor;
}
void Material::addTexture( std::string newTexture )
{
	texture = newTexture;
}
/**********\FIXME*********/

void Material::setContents( std::string toAddContents )
//Precondition:  none
//Function:	 Adds to the contents variable.
{
	contents = toAddContents;
}

std::string Material::getContents()
//Precondition:  none
//Function:	 Returns the "contents" variable.
{
	return contents;
}

bool Material::operator==( Material toTest )
//Precondition:  none
//Function:	 Tests to see if two Materials are equal. Returns 1 if
//		 this is the case, and 0 otherwise.
{
	if ( ( contents == toTest.contents ) && ( texture == toTest.texture ) && ( color == toTest.color ) )
		return 1;
	else
		return 0;
}
