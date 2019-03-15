.model small 							;ES register - defines the memory model, in this case small

.stack 100h 							;define a stack of memory of 100h <=> 256

.data 									;DS data segment, where we define the variables of our program

	mesaj DB "Hello, ASM from 1024 $" 	;the initialisation of our message with value Hello, ASM from 1024

.code 									;CS code segment, where our code goes

;procedure for display the message
main proc
	;sequence of code which set the register DS to refer to DS register which begins with .DATA
	mov AX, @data 						;copy to AX the memory reference of data (the address of the message)
	mov DS, AX 						    ;copy to DS what we got in .data
	LEA DX, mesaj 						;copy into DX the effective address of message (mov and lea means copy, but mov copy the 	
				  						;reference of an address, and lea copy exactly the effective address)
	MOV AX, 09H 						;display function 0x09 - 9h
	INT 21H								; DOS 21 functions library
	MOV AH,4CH 							;return control to the operating system (stop program).
	INT 21H
main endp 								;
end main 								;end of the program