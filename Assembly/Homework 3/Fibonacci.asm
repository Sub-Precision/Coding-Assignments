TITLE HWK_2_nichols.asm
; CSCI 2525 H01
; Due: 9 / 23 / 2022
Include Irvine32.inc

.data
fib1 byte 0 ; declaring variables
fib2 byte 1
fibonacci byte 9 DUP (?) ; creating array for the 9 outputs

.code
main PROC
mov eax, 0 ; clearing all registers
mov ebx, 0
mov ecx, 0
mov edx, 0
mov esi, 0
mov edi, 0

mov ecx, 9d ; Counter register variable

mov al, fib1 ; moving variables into registers
mov dl, fib2
mov bl, fibonacci
mov [fibonacci + 0], al ; putting f(0) and f(1) into memory manually
mov [fibonacci + 1], bl
Loop1: ; starting the loop
add al, dl ; add the 2 existing numbers
mov [fibonacci + (esi + 1)], al ; move number into next bit of memory
mov al, [fibonacci + (esi + 0)] ; save the previous number in memory in al
mov dl, [fibonacci + (esi + 1)] ; save current number in dl

inc esi
loop Loop1

mov ecx, 0
mov esi, 10d

mov ebx, 0
mov ebx, dword PTR [fibonacci + 5] ; setting pointer and printing remainder of array into ebx
call dumpregs

exit
main ENDP ;
END main ;