	.globl binary_search
binary_search:					//array "sorted" is X0, size is X1, key is X2
	MOV X19, XZR				//int start = 0; => X19 is gonna be "start"
	SUB X20, X1, #1				//X20 is size - 1
	MOV X21, X20				//int end = inputArr.length - 1; => X21 is gonna be "end"
	B while						//execute while loop
while:
	CMPS X19, X21				//compare start to end
	B.GT exit					//branch to exit condition if start > end
	ADD X22, X19, X21			//add start + end
	MOV X23, #2					//X23 has value 2
	UDIV X24, X22, X23			//(start + end) / 2 => X24 is "mid"
	LSL X10, X24, #3			//multiply mid by 8 to get byte address
	ADD X11, X0, X10			//X11 = inputArr + (mid * 8)
	LDUR X12, [X11, #0]			//X12 = inputArr[mid]
	CMP X2, X12					//compare key to inputArr[mid]
	B.EQ exit					//if key == inputArr[mid]
	B.LT cond1					//if key < inputArr[mid]
	B.GE cond2					//else
cond1:
	SUB X21, X24, #1			//end = mid - 1;
	B while						//repeat while
cond2:
	ADD X19, X24, #1			//start = mid + 1;
	B while						//repeat while
exit:
	br X24						//return mid
exit1:
	MOV X30, #-1				//set X30 to -1
	br X30						//return -1
