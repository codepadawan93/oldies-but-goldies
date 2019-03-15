; /---------------------------------------\
; | Program evaluates E= z-3+(x-1 + y/2); |
; | x,y,z are of type WORD                |
; \---------------------------------------/                                                                    
.model small

.stack 200h

.data
           
;these represent the terms of the expression           
x DW 0001h 
y DW 0006h
z DW 0010h           

result DW ?

.code

main proc          
    
    mov AX, @data ;boilerplate stuff 
    mov DS, AX    
    
    mov BX, x   ;BX = x
    sub BX, 1h  ;BX = x-1
    mov AX, y   ;AX = y
    mov CL, 2h  ;move the /2 part in CL for div operation (CL = 2)
    div CL      ;AX = AX/CL      
    add AX, BX  ;add x-1 and y/2
    mov BX, z   ;BX = z
    sub BX, 3h  ;BX = z-3
    add AX, BX  ;add z-3 to the paranthesis
    ;result will be in AL  
            
    mov result, AX ;if needed, move it to variable result in main memory  
    
main endp

end main