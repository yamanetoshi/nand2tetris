// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input. 
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel. When no key is pressed, the
// program clears the screen, i.e. writes "white" in every pixel.

// Put your code here.
(INIT)
    @1
    M=0 //state
    
(FILL-FALSE)
    @1
    D=M
    @LOOP
    D;JEQ

    @0
    M=0 // index

    @1
    M=0

(FILL-FALSE-LOOP)
    @8192
    D=A
    @0
    D=M-D
    @LOOP
    D;JGE

    @0
    D=M
    @16384
    A=A+D
    M=0

    @0
    M=M+1
    @FILL-FALSE-LOOP
    0;JMP

(FILL-TRUE)
    @1
    D=M
    @LOOP
    D;JNE

    @0
    M=0 // index

    @1
    M=1

(FILL-TRUE-LOOP)
    @8192
    D=A
    @0
    D=M-D
    @LOOP
    D;JGE

    @0
    D=M
    @16384
    A=A+D
    D=0
    M=!D 

    @0
    M=M+1
    @FILL-TRUE-LOOP
    0;JMP

(LOOP)
    @24576
    D=M
    @GOINIT
    D;JEQ

    @FILL-TRUE
    0;JMP
(END)
    @END
    0;JMP
(GOINIT)
    @FILL-FALSE
    0;JMP