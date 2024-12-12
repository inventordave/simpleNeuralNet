// NEURAL_NET_C

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>

#define DEVMODE

#define NN_Ref *(NN+(x*y))

static int * NN;

signed init( unsigned base, unsigned depth	);

char* getstring( char* _ )	{

	char* s = (char*)malloc( (sizeof(char)* strlen(_)) + 1 );

	int i = 0;
	while( *_ != '\0' )	{
		
		s[i++] = *_;
		_++;
	}

	s[i] = '\0';

	return s;
}


int main( int argc, char** argv )	{

	signed result = init( 2, 4 );
	printf( "\nResult code: %d\n", result );
	return 0;
}

signed init( unsigned base, unsigned depth	)	{

	// Build NN Tree.

	int numNodes = pow(base,depth);
	
	NN = (int*) malloc( sizeof(int) * numNodes + 1  );

	int x = 1;
	int y = 1;
	int z;
	char* _1 = (char*) calloc( 1, sizeof(char) * depth + 1 );
	char* _2 = (char*) calloc( 1, sizeof(char) * depth + 1 );

	char* strArray[ numNodes ];
	
	strArray[ 0 ] = "0";

/** 
	// 1. if increment [offset] is n % 2 == 1, last digit is 1

	// 2. if ancestor highest-order digit is 1, then current
	// highest-order digit is 1.

	// 3. if ancestor highest-order digit is 2, then current
	// highest-order digit is 2.

	// 4. if current node is lhs, it's lowest-order digit is 1.
	// 5. if current node is rhs, it's lowest-order digit is 2.
*/
	
	int flag = 0;
	int i = 1;
	while( y <= depth )	{

		// numSibs := 2^y
		// 1/2 start with 1, 1/2 start with 2
		// 2 are 1-based, then 2 2-based, then ...

		char* t1;
		char* t2;
		char* lhs_1 = (char*) calloc( 1,2 );
		lhs_1[0] = '1';
		char* rhs_1 = (char*) calloc( 1,2 );
		rhs_1[0] = '1';
		char* lhs_2 = (char*) calloc( 1,2 );
		lhs_2[0] = '2';
		char* rhs_2 = (char*) calloc( 1,2 );
		rhs_2[0] = '2';
		
		for( int j=0; j< pow(2, y ); j++ )	{

			if( !flag )	{

				flag = 1;

				strcpy( t1, lhs_1 ); free( lhs_1 );
				strcat( t1, "1" );
				strArray[ i++ ] = getstring( t1 );
				lhs_1 = getstring( t1 );

				strcpy( t1, rhs_1 ); free( rhs_1 );
				strcat( t1, "2" );
				strArray[ i++ ] = getstring( t1 );
				rhs_1 = getstring( t1 );
				
			}
			else	{
				
				flag = 0;

				strcpy( t2, lhs_2 ); free( lhs_2 );
				strcat( t2, "1" );
				strArray[ i++ ] = getstring( t2 );
				lhs_2 = getstring( t2 );

				strcpy( t2, rhs_2 ); free( rhs_2 );
				strcat( t2, "2" );
				strArray[ i++ ] = getstring( t2 );
				rhs_2 = getstring( t1 );

			}
		}
			//loop( base(x), exp(y)	) // until exp(y) > depth
	}

	for( i=0; i<numNodes; i++ )	{
		
		printf( "%d:\t%s\n", i, strArray[i] );
		fflush( stdout );
	}
	
	
	return numNodes - z;
}

// end_of_file
