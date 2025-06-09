/******************************************************************************************/
//Author: Alex Peppe
//File: laser.cpp
//
//The BZLazer map.
/******************************************************************************************/

#include <iostream>
#include <fstream>

#include "bzlib.h"

using namespace std;

void Help( World& );
//Precondition:  none
//Function:      Creates server help files.

void ServerMessages( World& );
//Precondition:  none
//Function:      Creates server messages.

const int randomJumpCount = ( rand() % 1000 ) + 10;
std::string randomJumpCountStr = "";

int main( int argc, char* argv[] )
{
       	cout << "BZLAZER Tag\n\tby Alex Peppe\n\n";
        world.setFileName( "bzlasertag.bzw" );

	Help( world );

        srand( time(NULL) );
        int randomJumpCount = ( rand() % 1000 ) + 10;
        strinta( randomJumpCountStr, randomJumpCount );

        /* Settings */
        world.addSetting( "_tankSpeed 25" );
        world.addSetting( "_wingsJumpCount " + randomJumpCountStr );
        world.addSetting( "_radarLimit 1200" );
        world.addSetting( "_wallHeight 0" );
        world.addSetting( "_rejoinTime 0" );
	world.addSetting( "_radarLimit 0" );
	world.addSetting( "_tankExplosionSize 250" );
        world.addSetting( "_tankAngVel 1.2" );
        world.addSetting( "_maxFlagGrabs 1" );

	/* Options */
	world.addOption( "-j" );
	world.addOption( "-disableBots" );
	world.addOption( "-ms 3" );
	world.addOption( "-st 5" );
	world.addOption( "-mp 0,10,0,10,0,5" );
	world.addOption( "-maxidle 90" );
	world.setSize( 400 );

	/* Flags       Flag Num Max */
	world.addFlag( "L" ,  200 );
	ServerMessages( world );

	world.setGroundTexture( "std_ground" );
	world.setGroundColor( 0, 0, 0 );

	int type = 0;	
	int mapOfChoice = rand() % 2;
	cout << "Lasertag Map of Choice: " << mapOfChoice << endl;
	int count = 0;
	std::ifstream map;
	std::string fileName;

	if ( argc > 0 )
		fileName = argv[1];
	else
		fileName = "./";	//Assume current directory

	fileName += "lasermap";
	strinta( fileName, mapOfChoice );
	fileName += ".txt";
	map.open( fileName.c_str() );
	
	/* Roof */
	Point p1r( -400, -400, 50 );
	Point p2r(  400, 400, 51 );
	Point p1R( -800, -800, 50 );
	Point p2R(  800, 800, 51 );
	Pyramid roof( p1R, p2R );
	roof.setColor( 0, 0, 0 );
	roof.Make();
	Point p2(  685, 685, 0 );

	/* Walls */
	Box wall1( Point( -440, -420, 0 ), Point( 440, -440, 200 ) );
	wall1.setColor( .05, .05, .05 );
	wall1.repeatMakeRotate90( Point( 0, 0, 0 ) );
	Box wall3( Point( -400.1, -400, 0 ), Point( 400.1, -400.1, 200 ) );
	wall3.setTexture( "blue_laser" );
	wall3.addPhysicsDeath( "Don't touch the pretty lights!" );
	wall3.addDynamicTexture( "shift 1 0" );
	wall3.repeatMakeRotate90( Point( 0, 0, 0 ) );
	Box wall2( Point( -480, -440, 0 ), Point( 480, -480, 200 ) );
	wall2.setColor( 0, 0, 0 );
	wall2.repeatMakeRotate90( Point( 0, 0, 0 ) );

	if (!map)
	{
		cout << "Failure to read map file " + fileName + ".";
		exit(1);
	}
	for ( int i = 0; i < 40; i++ )
	{
		for ( int j = 0; j < 40; j++ )
		{
			map >> type;
			
			if (type == 0)
				continue;
			else if (type == 1)
			{
				//Wall
				Point pillarP1( p1r.x + ( 20 ) * j, p1r.y + ( 20 ) * i, p2.z );
				Point pillarP2( p1r.x + ( 20 ) * ( j + 1 ), p1r.y + ( 20 ) * ( i + 1 ), p1r.z );
				Box pillar( pillarP1, pillarP2 );
				pillar.setTexture( "mesh" );
				pillar.setColor( double( rand() % 20 ) / 100, double( rand() % 20 ) / 100, double( rand() % 20 ) / 100 );
				pillar.Make();
				count++;
                        }
			else if (type == 2)
			{
				//Wall
				Point pillarP1( p1r.x + ( 20 ) * ( j + .25 ), p1r.y + ( 20 ) * ( i + .25 ), p2.z );
				Point pillarP2( p1r.x + ( 20 ) * ( j + .75 ), p1r.y + ( 20 ) * ( i + .75 ), p1r.z );
				Box pillar( pillarP1, pillarP2 );
				pillar.setTexture( "mesh" );
				pillar.setColor( double( rand() % 20 ) / 100, double( rand() % 20 ) / 100, double( rand() % 20 ) / 100 );
				pillar.Make();
				count++;
			}
			else if (type == 3)
			{
				//Wall
				Point pillarP1( p1r.x + ( 20 ) * j, p1r.y + ( 20 ) * i, p2.z );
				Point pillarP2( p1r.x + ( 20 ) * ( j + 1 ), p1r.y + ( 20 ) * ( i + 1 ), p1r.z );
				Box pillar( pillarP1, pillarP2 );
				pillar.setTexture( "mesh" );
				pillar.setDriveThrough();
				pillar.setColor( double( rand() % 50 ) / 100, double( rand() % 50 ) / 100, double( rand() % 50 ) / 100, .8 );
				pillar.Make();
				count++;
                        }	
			else
			{
				cout << "bzlasertag: Invalid Maze Object Type (" << type << ").\n";
				cout << "          : Allowed: 0, 1, 2, or 3.\n";
			}	
		}
	}
	
	map.close();

	return 0;
}

void Help( World& world )
//Precondition:  none
//Function:      Creates server help files.
{
	world.addHelp( "general", "=== GENERAL ===================================================================\nThis map is based on real life lasertag, only it uses tanks. All flags are\nlasers and there isn't any radar. Good for being sneaky.\n===============================================================================" );
	
}

void ServerMessages( World& world )
//Precondition:  none
//Function:      Creates server messages.
{
	std::string admsgStr = "No swearing or cheating. Please stay polite. Enjoy laser tag!";

	std::string srvmsgStr = "#                                   #######\\n#         ##    ####  ###### #####     #      ##    ####\\n#        #  #  #      #      #    #    #     #  #  #    #\\n#       #    #  ####  #####  #    #    #    #    # #\\n#       ######      # #      #####     #    ###### #  ###\\n#       #    # #    # #      #   #     #    #    # #    #\\n####### #    #  ####  ###### #    #    #    #    #  ####\\n";

	world.addMessage( "srvmsg", srvmsgStr );
	world.addMessage( "admsg", admsgStr );
}
