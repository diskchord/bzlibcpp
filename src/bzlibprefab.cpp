/**********************************************************************/
//Author: Alex Peppe
//File: prefab.cpp
//
//Contains prefab functions.
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

/**********************************************************************
 * BZLIB Text                                                         *
 **********************************************************************/

void WriteLetter( char letter, Point p, int flipX, int flipY, int size )
//Precondition:  none
//Function:      Using MeshBoxes, creates a single letter. flipX and
//               flipY give the rotation of the letter, size gives the
//               height of the letter (and, thus, 5/3 of the width). p
//               gives the location of the letter. letter is, of course,
//               the letter itself.
{
	static int letNum = -1;
	letNum++;
	std::string directory = DIRECTORY;
	
	Group letterGroup;
	letterGroup.startGroup();
	ifstream fin;
	fin.open( ( directory + "/letters.rsc" ).c_str() );
	
	int lineNum;
	std::string trash;

	/* Line Numbers */	
	if ( letter == ' ' )
	{
		letterGroup.endGroup();
		return;
	}
	if ( isupper( letter ) )
	{
		lineNum = int( letter ) - 65;
	}
	else if ( islower( letter ) )
	{
		lineNum = int( letter ) - 71;
	}
	else if ( letter == '@' )
	{
		lineNum = 53;
	}
	else if ( letter == '.' )
	{
		lineNum = 54;
	}
	else
	{
		cout << "bzlib: Invalid letter passed to WriteLetter().\n";
		return;
	}
	
	for ( int i = 0; i < lineNum; i++ )
	{
		getline( fin, trash );
	}

	/* Building the letters */
	//This is a complex set of if and for statements designed to
	//take advantage of the object rotation arguments.
	int make;
	for ( int i = 5; i > 0; i-- )
	{
		if ( flipX <= 0 )
		{
			for ( int j = 5; j > 0; j-- )
			{
				fin >> make;	

				if ( make == 1 )
				{
					Box letter;
					if ( flipY == 1 )
						letter.setLocation( Point( 0, ( 5 - j ) * size * .6, i * size), Point( .1, ( ( 5 - j ) + 1 ) * size * .6, ( i + 1 ) * size ) );
					else
						letter.setLocation( Point( j * size * .6, 0, i * size), Point( ( j + 1 ) * size * .6, .1, ( i + 1 ) * size ) );

					letter.setColor( 1, 1, 1 );
					letter.setEmission( 1, 1, 1 );
					letter.setTexture( "mesh" );
					letter.setTexture( NONE );
					letter.Make();
				}
			}
		}
		else
		{
			for ( int j = 0; j < 5; j++ )
			{
				fin >> make;	

				if ( make == 1 )
				{
					Box letter;
					if ( flipY == 1 )
						letter.setLocation( Point( 0, ( 5 - j ) * size * .6, i * size), Point( .1, ( ( 5 - j ) + 1 ) * size * .6, ( i + 1 ) * size ) );
					else
						letter.setLocation( Point( j * size * .6, 0, i * size), Point( ( j + 1 ) * size * .6, .1, ( i + 1 ) * size ) );						
				        letter.setColor( 1, 1, 1 );
                                        letter.setEmission( 1, 1, 1 );
                                        letter.setTexture( "mesh" );
					letter.setTexture( NONE );
					letter.Make();
				}
			}
		}

	}
	
	letterGroup.endGroup();
	letterGroup.setLocation( p );
	letterGroup.Make();

	fin.close();
}

void MakeWord( std::string str, Point p, int flipX, int flipY, int size )
//Precondition:  none
//Function:      Using MeshBoxes, creates a word or sentence. flipX and
//               flipY give the rotation of the letter, size gives the
//               height of the letter (and, thus, 5/3 of the width). p
//               gives the location of the center of the word or sentence. 
//               This function passes the letters to WriteLetter() one
//               at a time.
{
	/* Error Checking */
	if ( ( flipX != 1 ) && ( flipX != 0 ) && ( flipX != -1 ) )
	{
		cout << "bzlib: When defining a word, flipX must be either 1, 0 or -1.\n";
		return;
	}

	if ( ( flipY != 1 ) && ( flipY != 0 ) && ( flipY != -1 ) )
	{
		cout << "bzlib: When defining a word, flipY must be either 1, 0 or -1.\n";
		return;
	}

	/* Midpoint and settings of start location */
	int width = ( str.length() - 1 ) * size * 4;
	int midPoint = width / 2;
	int xDiff = -( flipX * midPoint );
	int yDiff = -( flipY * midPoint );

	/* Loop to pass the letters to WriteLetter() */
	for ( unsigned int i = 0; i < str.length(); i++ )
	{
		p = p + Point( xDiff, yDiff, 0 );
		WriteLetter( str[i], p, flipX, flipY, size );

		xDiff = flipX * size * 4;
		yDiff = flipY * size * 4;
	}
}
