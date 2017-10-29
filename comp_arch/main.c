/* main.c simple program to test assembler program */

#include <stdio.h>
#include <assert.h>

extern long long int binary_search(long long int sorted[], int, int);

/* ******************************************
 // uncomment this code when you are ready to implement part three.
 // you may need to add parameters to match what is below
extern long long int part_three();
****************************************** */

int main(void)
{
	//code for part 2
	long long int sorted[15] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29};
	long long int value_returned = binary_search(sorted, 15, 29);
	printf("Result of binary search is %ld\n", value_returned);
	/*  ******************************************
	additional code for debugging. You can uncomment this code to test you implementation
	assert( 1 == binary_search(sorted, 15, 1) );
	assert( 3 == binary_search(sorted, 15, 3) );
	assert( 15 == binary_search(sorted, 15, 15) );
	assert( 23 == binary_search(sorted, 15, 23) );
	assert( 29 == binary_search(sorted, 15, 29) );
	assert( -1 == binary_search(sorted, 15, 35) );
	 ****************************************** */


	//code for part 3
	/* ******************************************
	// This code will call part 3. You may choose to add parameters,
	// depending on the nature of your project

    long long int returned_part3 = part_three();
    printf("Result of part_three is %ld\n", returned_part3);
    ****************************************** */

    return 0;
}
