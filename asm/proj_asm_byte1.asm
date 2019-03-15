;*************************************************
;*                                               *
;*    Program evaluates E = z-3 + |x-1 + y/2|    *
;*                                               *
;*            Data is of type BYTE               *
;*                                               *
;*************************************************

.model small

.stack 200h

.data
           
    ;these represent the terms of the expression           
    x DB 01h 
    y DB 06h
    z DB 0Ah           

.code

main proc          
    
    ;boilerplate stuff
    mov AX, @data  
    mov DS, AX    
    
    ;find value of expression inside modulus  
    xor AX, AX   ;clear AX
    mov AL, y    ;AL = y
    mov CL, 02h  ;CL = 2
    div CL       ;AL = AL/CL
    dec x        ;x--
    add AL, x    ;AL = AL + x  
    ;as long as x,y,z>0, expression in modulus 
    ;will always be >0  
    sub z, 03h   ;z = z-3
    add AL, z    ;AL = AL + z   
    
main endp

end main