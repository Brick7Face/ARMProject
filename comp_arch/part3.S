	.globl part_three
part_three:										//takes an array, the array size, and an integer to search for in the array once it is sorted
	CMP X1, XZR									//compare X1 (the array length) to zero; if zero, branch to exit1
	B.EQ exit1
	SUB X3, X2, #1								//subtract 1 from the array length for array.length-1; X3 will represent high value in quicksort
	MOV X4, XZR									//X4 will represent low value in quicksort
	MOV X19, X4									//X19 will represent i in quicksort
	MOV X20, X3									//X20 will represent j in quicksort
	SUB X21, X3, X4								//high - low
	MOV X24, #2
	UDIV X22, X21, X24							//(high-low)/2
	ADD X23, X4, X22							//low + (high-low)/2 --> X23 is pivot index
	LSL X10, X23, #3							//multiply the index by 8 to get byte address
	ADD X11, X0, X10							//access pivot in array
	LDUR X12, [X11, #0]							//load the pivot value into X12	--> X12 is pivot
	B quicksort									//begin quicksort function
quicksort:
	CMP X19, X20								//compare i and j
	B.GT recur									//branch to recursion step if i is greater than j
	B while1									//branch to first while loop
while1:
	LSL X13, X19, #3							//multiply i by 8 to get byte address
	ADD X14, X0, X13							//access index i in array
	LDUR X15, [X14, #0]							//load array[i] into X15
	CMP X15, X12								//compare array[i] to pivot
	B.GE while2									//if greater than or equal to pivot, branch to second while loop
	ADD X19, X19, #1							//i++
	B while1									//repeat loop
while2:
	LSL X16, X20, #3							//multiply j by 8 to get byte address
	ADD X17, X0, X16							//access index j in array
	LDUR X18, [X17, #0]							//load array[j] into X18
	CMP X18, X12								//compare array[j] to pivot
	B.LE comp									//if less than or equal to pivot, branch to i j compare step
	SUB X20, X20, #1							//otherwise enter while loop, j--
	B while2									//repeat loop
comp:
	CMP X19, X20								//compare i to j
	B.GT quicksort								//branch to top of outer while loop if i is greater than j
	B exchange									//otherwise branch to exchange step
exchange:
	LSL X10, X19, #3							//multiply i by 8 to get byte address
	ADD X11, X0, X10							//access array[i]
	LDUR X12, [X11, #0]							//load array[i] into X12
	MOV X25, X12								//int temp = array[i] --> X25 is now temp
	LSL X13, X20, #3							//multiply j by 8 to get byte address
	ADD X14, X0, X10							//access array[j]
	LDUR X15, [X14, #0]							//load array[j] into X15
	STUR X15, [X11, #0]							//store value of array[j] in array[i]
	STUR X25, [X14, #0]  						//store value of temp in array[j]
	ADD X19, X19, #1							//i++
	SUB X20, X20, #1							//j--
	B quicksort									//return to top of outer while loop
recur:
	CMP X4, X20									//compare low to j
	B.GE recur2									//if low >= j, move to next recursion check
	MOV X3, X20									//if low < j, move j into the high value spot
	MOV X19, X4									//X19 will represent i
	MOV X20, X3									//X20 will represent j
	B quicksort									//perform quicksort with these new parameters
recur2:
	CMP X19, X3									//compare i to high
	B.GE exit									//if i >= high, then program is done
	MOV X4, X19									//if i < high, move i into low value spot
	MOV X19, X4									//X19 will represent i
	MOV X20, X3									//X20 will represent j
	B quicksort									//perform quicksort with these new parameters
exit1:											//returns an error if array is of length 0 to begin
	MOV X0, #-1
	BR	X30
exit:
	//MOV X0, location of X2 value in array
	BR X30
