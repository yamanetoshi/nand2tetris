// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

// Put your code here.
// int R3 = 0;
// int R2 = 0;
// while (R3 < R1) { // R1 - R3 > 0
//   R2 = R0 + R2;
//   R3 += 1
// }
    @3
    M=0
    @2
    M=0
(LOOP)
	@1
	D=M
    @3
    D=D-M
    @END
    D;JLE
    @2
    D=M
    @0
    D=D+M
    @2
    M=D
    @3
    M=M+1
    @LOOP
    0;JMP
(END)
    @END
    0;JMP