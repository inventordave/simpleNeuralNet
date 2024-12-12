// NEURAL_NET_C

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

#define DEVMODE

#define NN_Ref *(NN+(x*y))

static int * NN;

signed init( unsigned base, unsigned depth	);

int main( int argc, char** argv )	{

	signed result = init( 2, 4 );
	printf( "\nResult code: %d\n", result );
	return 0;
}

signed init( unsigned base, unsigned depth	)	{

	// Build NN Tree.

	int numNodes = pow(base,depth);
	
	NN = (int*) malloc( sizeof(int) * numNodes  );

	int x = base;
	int y = depth;

	for( y; y>0; y-- )	{

		for( x; x>0; x-- )	{

			int val = y * x;
			NN_Ref = val;
		}
	}

	int z=0;
	while( 1 )	{

		while( y<depth )	{
			
			printf( "[%d]\n\n", y );
			
			while( x<base )	{
				
				printf( "%d: %d,", base-x, NN_Ref );
				x++;
				z++;
			}
			x=0;
			y++;
			printf( "\n\n" );
		}

		printf( "Should have printed %d entries. Printed %d nodes.\n", numNodes, z );

		break;
	}

	return numNodes - z;
}

// end_of_file
