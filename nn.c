// NEURAL_NET_C

#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include "../aplib/aplib.c"
#include "../stringy/stringy.c"
#include "../gcollect/gc.h"

#define DEVMODE

static uint32_t *** NN;

int main( int argc, char** argv )	{

	printf( "\nResult code: %d\n", init( 2, 4 ) );
	return 0;
}

signed init( unsigned base, unsigned depth	)	{

	// Build NN Tree.

	int numNodes = pow(base,depth);
	
	NN = (uint32***) g( malloc( sizeof(uint32_t) * numNodes ) );

	int x = base;
	int y = depth;

	for( y; y>0; y-- )	{

		for( x; x>0; x-- )	{

			NN[y][x] = y*x;
		}
	}

	#ifdef DEVMODE
		int z=0;
	
		while( 1 )	{

			z++;
			
			while( (y++)<depth )	{
				
				printf( "[%d]:" );
				while( (x++)<base )	{
					
					printf( " %d: %d,", base-x, NN[y][x] );
				}
				x=0;
				printf( "\n\n" );
			}

			printf( "Should have printed %d entries. Printed %d nodes.\n", numNodes, z );

			break;
		}
	#endif

	return z - numNodes;
}



// end_of_file
