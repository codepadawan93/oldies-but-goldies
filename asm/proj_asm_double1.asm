;*******************************************
;*                                         *
;* Program evaluates E = z-3 + |x-1 + y/2| *
;*                                         *
;*        Data is of type DOUBLE           *
;*                                         *
;*******************************************

.model small

.stack 200h

.data
           
    ;these represent the terms of the expression           
    x DD 00000000h 
    y DD EEEE2222h
    z DD 22221111h  
     
    ;this will temporarily hold the result of the division
    temp DD 0h          

.code

main proc          
    
    ;boilerplate stuff
    mov AX, @data  
    mov DS, AX    
    
    ;find value of division  
    xor AX, AX                  ;clear AX
    mov AX, word ptr y + 2      ;AX = hi-bits of y
    mov CX, 02h                 ;divide by two
    div CX
    mov word ptr temp + 2, AX   ;move result to hi-bits of temp 
    
    xor AX, AX                  ;clear AX
    mov AX, word ptr y          ;AX = lo-bits of y
    mov CX, 02h                 ;divide again
    div CX                      
    mov word ptr temp, AX       ;move result to lo-bits of temp
    
    ;simplify expression
    dec x                       ;x--
                                
    sub z, 3                    ;x -= 3
    
    ;perform final addition
    mov DX, word ptr temp + 2   ;move the result  of y/2 into DX:AX
    mov AX, word ptr temp,  
    
    add DX, word ptr x + 2      ;add hi-bits of (x-1) to hi-bits of y/2 
    add AX, word ptr x          ;and now the lo-bits
    
    add DX, word ptr z + 2      ;same with (z-3)
    add AX, word ptr z
    ;the result will be in DX:AX
    
main endp

end main