/******************************************************************************
By Alex Peppe
googlecube.cpp
******************************************************************************/

#include "bzlib.h"

int main()
{
	world.setFileName( "googlecube.bzw" );

	Point p1 = Point( -10, -10, 10 );
	Point p2 = Point( 10, 10, 30 );

	Box mirrorCube( p1, p2 );
	mirrorCube.setTexture( "http://perso.wanadoo.fr/fcys14/Image/google.png" );
	mirrorCube.Make();

	return 0;
}
