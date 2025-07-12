TITLE HWK_2_nichols.asm
; CSCI 2525 H01
; Due: 9 / 23 / 2022
Include Irvine32.inc
SECONDS_IN_DAY TEXTEQU <mov edx, SECONDS_IN_DAY1> ; for convenience

.data
; Declaring Variables
equation word (2 * 3 * 4 * 5 * 6 * 7) ; note: calculating beforehand
carrier1 byte 0ffh
carrier2 byte 1h
carrier3 byte 01111111b
carrier4 byte 01111111b
SECONDS_IN_DAY1 dword (60d * 60d * 24d) ; product comes out to 86400 or 15180 in hex
numA word 132d
numB word 01101001b
numC word 0AF5h
numD word 85d

.code
main PROC
mov eax, 0 ; clearing all registers
mov ebx, 0
mov ecx, 0
mov edx, 0
mov esi, 0
mov edi, 0

; Question 1 ; used register (EAX)
; Move answer to register
mov ax, equation

; Question 2 ; used register (EBX)
mov bl, carrier1 ; Set carrier flags
add bl, carrier2
call dumpregs
mov cl, carrier3 ; set Overflow flags
add cl, carrier4

;Question 3 ; register used (EDX)
SECONDS_IN_DAY ; variable was computed on initialization
call dumpregs ; just displaying answer, converted to hex

;Question 4 used registers (EAX & EBX)
mov eax, 0 ; Zeroing previously used registers
mov ebx, 0
mov ax, numA ; Part 1
sub ax, numB
mov bx, numC ; Part 2
sub bx, numD
add eax, ebx ; combine register values
mov [numA], ax ; loading final value to new register
mov eax, 0 ; clearing original register
mov ax, numA ; moving final value back to original register
call WriteInt
call dumpregs

exit
main ENDP ;
END main ;