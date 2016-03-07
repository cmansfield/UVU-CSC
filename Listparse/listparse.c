/*
listparse was created by Chris Mansfield
iterates through a list of words and 
concatenates them together as long as
their total char length equals the 
targetSize specified.

Example:
test.txt contains:
test
home
howdy
joy

./listparse 9 test.txt
will generate:
testhowdy
homehowdy
howdytest
howdyhome

Useful if you have a collection of info
and you want to concatenate them together
to a specific password length
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// constants

int main( int argc, char *argv[] ) {
	FILE *fp = stdin;
	FILE *fp2 = stdin;
	FILE *fsave = fopen( "STARTlist.txt", "w" );
	char firstString[20];
	char secondString[20];
	int targetSize = 0;
	int firstCount = 0;
	int secondCount = 0;

	if ( fsave == NULL ) {
		printf( "Trouble saving the file\n" );
		return -1;
	}

	if ( argc != 3 ) {
		printf( "\nlistparse <Target Element Size> <File with keywords>\n\n" );
		return -1;
	}
	
	if ( argc > 2 ) {
		targetSize = atoi( argv[1] );
		fp = fopen( argv[2], "r" );
		if ( fp == NULL ) {
			printf ( "File name %s not found.\n", argv[2] );
			return -1;
		}

		while ( fscanf( fp, "%s", firstString ) == 1 )
		{
			fp2 = fopen( argv[2], "r" );

			firstCount = 0;
			while( firstString[firstCount] != '\0' )
			{
				firstCount++;
			}

			if ( firstCount < targetSize ) {
				// my main code for concatinating goes here
				while ( fscanf( fp2, "%s", secondString ) == 1 )
				{
					secondCount = 0;
					while( secondString[secondCount] != '\0' )
					{
						secondCount++;
					}

					if ( firstCount + secondCount == targetSize ) {
					// if they are equal to then continue
						fprintf( fsave, "%s%s\n", firstString, secondString );
					}
				}
			}
		
			fclose( fp2 );
			//printf( "testing: %s CharCount: %d\n", firstString, firstCount );
		}
	}

	fclose( fp );
	fclose( fsave );

	return 0;
}
