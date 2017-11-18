/* main.c simple program to test assembler program */

#include <stdio.h>
#include <assert.h>

extern long long int binary_search(long long int sorted[], int, int);
extern long long int part_three(long long int arr[], int, int);

int main(void)
{
	//code for part 2
	long long int sorted[15] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29};
	long long int value_returned = binary_search(sorted, 15, 29);
	printf("The value 29 is located at position %ld in the array.\n", value_returned);

	assert( 0 == binary_search(sorted, 15, 1) );
	assert( 1 == binary_search(sorted, 15, 3) );
	assert( 7 == binary_search(sorted, 15, 15) );
	assert( 11 == binary_search(sorted, 15, 23) );
	assert( 14 == binary_search(sorted, 15, 29) );
	assert( -1 == binary_search(sorted, 15, 35) );


	//code for part 3 - part 3 implements quicksort and returns the first index of the value of the 3rd parameter
	//for example, 15 as the 3rd parameter should return 12, as it will be sorted to be in position 12 of this array
	long long int arr[20] = {9, 19, 27, 13, 4, 1, 18, 19, 7, 4, 3, 2, 15, 14, 11, 16, 19, 17, 3, 1};
	int value = 15;
    long long int returned_part3 = part_three(arr, 20, value);
    printf("The value %f is located at %ld in the sorted array from part 3.\n", value, returned_part3);

    //sorted array = [1, 1, 2, 3, 4, 4, 4, 7, 9, 11, 13, 14, 15, 16, 17, 18, 19, 19, 19, 27]

    return 0;
}
