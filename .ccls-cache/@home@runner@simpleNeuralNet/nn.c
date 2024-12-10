// NEURAL_NET_C

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

#define DEVMODE

static uint32_t *** NN;
signed init( unsigned base, unsigned depth	);

int main( int argc, char** argv )	{

	signed result = init( 2, 4 );
	printf( "\nResult code: %d\n", result );
	return 0;
}

signed init( unsigned base, unsigned depth	)	{

	// Build NN Tree.

	int numNodes = pow(base,depth);
	
	NN = (uint32_t***) malloc( sizeof(uint32_t) * numNodes  );

	uint32_t x = base;
	uint32_t y = depth;

	for( y; y>0; y-- )	{

		for( x; x>0; x-- )	{

			uint32_t* val = (uint32_t*)malloc( sizeof( uint32_t) );
			*val = (uint32_t)y * (uint32_t)x;
			
			//*(NN + (y*x) ) = val;
			*NN[y][x] = *val;
		}
	}

	assert( x==0 );
	assert( y==0 );
	
	int z=0;
	while( 1 )	{

		while( y<depth )	{
			
			printf( "[%d]:", (int)y );
			
			while( x<base )	{
				
				printf( " %d: %d,", base-x, (int)*(NN[x][y]) );
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

	return z - numNodes;
}



// end_of_file
