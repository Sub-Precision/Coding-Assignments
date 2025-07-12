TITLE HWK_2_nichols.asm
; CSCI 2525 H01
; Due: 9 / 23 / 2022
Include Irvine32.inc

.data
MyArray word 5767h, 2132h, 4798h ; Given array
arraySize = ($-MyArray) / 2 ; Number of Variables

.code
main PROC
mov eax, 0 ; clearing all registers
mov ebx, 0
mov ecx, 0
mov edx, 0
mov esi, 0
mov edi, 0

mov ax, MyArray ; moving bytes into ax register
xchg MyArray + 4, ax ; swapping the values into the required order
xchg MyArray + 2, ax
xchg MyArray, ax

mov esi, offset MyArray
mov ecx, arraySize ; storing array list size
mov ebx, type MyArray
call dumpmem

exit
main ENDP ;
END main ;