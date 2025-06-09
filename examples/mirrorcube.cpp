/******************************************************************************
By Alex Peppe
mirrorcube.cpp
******************************************************************************/

#include "bzlib.h"

int main()
{
	world.setFileName( "mirrorcube.bzw" );

	Point p1 = Point( -10, -10, 10 );
	Point p2 = Point( 10, 10, 30 );

	Box mirrorCube( p1, p2 );
	mirrorCube.setTexture( "mountain1" );
	mirrorCube.addSphereMap();
	mirrorCube.Make();

	return 0;
}
