
CPU simuliator

version 1.0.0

This project simulates execution of simple assmebly code.
Like this:

mov r1 7
mov r2 8
add r2 r1
mov r3 r2
jmp Next
Next:
sub r2 r1
cnd:
cmp r2 r3
je display
jl inc
inc:
add r2 1
jmp cnd
display:
print r2

