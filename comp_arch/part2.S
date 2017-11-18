	.globl binary_search
binary_search:					//array "sorted" is X0, size is X1, key is X2
	MOV X3, XZR					//int start = 0; => X3 is gonna be "start"
	SUB X4, X1, #1				//X4 is inputArr.length - 1, or "end"
	B while						//execute while loop
while:
	CMP X3, X4					//compare start to end
	B.GT exit1					//branch to exit condition if start > end
	ADD X19, X3, X4				//add start + end
	MOV X20, #2					//X20 has value 2
	UDIV X21, X19, X20			//(start + end) / 2 => X21 is "mid"
	LSL X10, X21, #3			//multiply mid by 8 to get byte address
	ADD X11, X0, X10			//X11 = inputArr + (mid * 8)
	LDUR X12, [X11, #0]			//X12 = inputArr[mid]
	CMP X2, X12					//compare key to inputArr[mid]
	B.EQ exit					//if key == inputArr[mid]
	B.LT cond1					//if key < inputArr[mid]
	B.GE cond2					//else
cond1:
	SUB X4, X21, #1				//end = mid - 1;
	B while						//repeat while
cond2:
	ADD X3, X21, #1				//start = mid + 1;
	B while						//repeat while
exit:
	MOV X0, X21					//set return value (X0) to mid (for returning position)
	//MOV X0, X12					//set return value (X0) to inputArr[mid] (for returning value)
	BR X30						//branch back to C program
exit1:
	MOV X0, #-1					//set return value to -1
	BR X30						//branch back to C program
