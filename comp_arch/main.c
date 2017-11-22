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

	/******************************************************************************************************************************
	*	code for part 3 - part 3 implements quicksort and returns the value in the array at the index provided. The index is in
	*	human speak; for example, index 4 in an array {1, 2, 3, 4, 5} would contain the value 4. In order to meet the line
	*	requirement, I also implemented insertion sort as a redundancy measure.
	*******************************************************************************************************************************/
	long long int arr[20] = {9, 19, 27, 13, 4, 1, 18, 19, 7, 4, 3, 2, 15, 14, 11, 16, 19, 17, 3, 1};
	//sorted array = [1, 1, 2, 3, 3, 4, 4, 7, 9, 11, 13, 14, 15, 16, 17, 18, 19, 19, 19, 27]
	int value = 4;
	long long int returned_part3 = part_three(arr, 20, value);
	printf("The position %d in the sorted array from Part 3 contains the value %ld.\n", value, returned_part3);

	assert(1 == part_three(arr, 20, 1));
	assert(1 == part_three(arr, 20, 2));
	assert(2 == part_three(arr, 20, 3));
	assert(3 == part_three(arr, 20, 4));
	assert(3 == part_three(arr, 20, 5));
	assert(4 == part_three(arr, 20, 6));
	assert(4 == part_three(arr, 20, 7));
	assert(7 == part_three(arr, 20, 8));
	assert(9 == part_three(arr, 20, 9));
	assert(11 == part_three(arr, 20, 10));
	assert(13 == part_three(arr, 20, 11));
	assert(14 == part_three(arr, 20, 12));
	assert(15 == part_three(arr, 20, 13));
	assert(16 == part_three(arr, 20, 14));
	assert(17 == part_three(arr, 20, 15));
	assert(18 == part_three(arr, 20, 16));
	assert(19 == part_three(arr, 20, 17));
	assert(19 == part_three(arr, 20, 18));
	assert(19 == part_three(arr, 20, 19));
	assert(27 == part_three(arr, 20, 20));

	long long int arrTwo[7] = {15, 2, 4, 4, 4, 16, 3};
	value = 2;
	returned_part3 = part_three(arrTwo, 7, value);
    printf("The position %d in the sorted array from Part 3 array 2 contains the value %ld.\n", value, returned_part3);

    assert(2 == part_three(arrTwo, 7, 1));
    assert(3 == part_three(arrTwo, 7, 2));
    assert(4 == part_three(arrTwo, 7, 3));
    assert(4 == part_three(arrTwo, 7, 4));
    assert(4 == part_three(arrTwo, 7, 5));
    assert(15 == part_three(arrTwo, 7, 6));
    assert(16 == part_three(arrTwo, 7, 7));


    return 0;
}
