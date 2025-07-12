INCLUDE Irvine32.inc

;constants
endl EQU <0Ah, 0Dh>

.data
input BYTE 0h
error BYTE "Invalid Response.", ; variable used for exception handling
			   endl, "Please input a valid response.", endl, 0h
.code
main PROC
start: ; this is to recycle back to the beginning of the program once the user reaches the end of a line
call FindPrimes
call clearRegs ; clearing registers
call clrscr
mov ebx, offset input
call menu

; evaluating user input
cmp input, 1d ; exception handling for if user inputs below options
jb OOR
cmp input, 3d ; valid input
jb valid
cmp input, 3d ; exception handling for if user inputs above options
ja OOR
cmp input, 3d ; exit call
jmp input3

OOR: ; "Out of Range" Exception Handling
push edx
mov edx, offset error
call writeString
call waitMsg
pop edx
jmp start

valid:
cmp al, 2     
jb input1
cmp al, 3     
jb input2
call input3
jmp start

input1:
call in1
jmp start

input2:
call in2
jmp start

input3:
exit
main endp



FindPrimes PROC
maxLength = 10000d
.data
primeArray byte 10000 DUP (0 ) ; max array size of 10 thousand

.code
call ClearRegs
mov ecx, offset primeArray
mov ecx, maxLength
mov ebx, 2d
Loop1:
	cmp ebx, 9998d
	je breakOut
	push ecx
	mov esi, 2d
	mov ecx, 9998d
Loop2:
	cmp ecx, 0
	je success
	mov eax, esi
	mov edx, 0
	div ebx
	cmp dx, 0h
	je check
	inc esi
	dec ecx
	
	jmp Loop2

	success: ; this runs when the program successfully determines a byte is a prime
	inc ebx
	mov esi, ebx
	pop ecx
	dec ecx
	jmp Loop1

	check: ; this runs to evaluate the byte to determine if it is a prime
	cmp [primeArray + esi], 1
	je fail
	cmp esi, ebx
	je fail
	mov [primeArray + esi], 1
	inc esi
	dec ecx
	jmp Loop2

	fail: ; this runs when the program determines this byte is not a prime
	inc esi
	dec ecx
	jmp Loop2

breakOut:
call temporaryPrime
ret
FindPrimes ENDP



ClearRegs PROC
.data
.code
mov eax, 0
mov ebx, 0
mov ecx, 0
mov edx, 0
mov esi, 0
mov edi, 0
ret
Clearregs ENDP



temporaryPrime PROC
.data
temporary word 1229 DUP(5 )

.code
mov esi, 2
mov edi, 0
mov ecx, 9999d
mov edx, offset temporary
Filter: ; This loop is designed to filter out the 0's, which denotes a prime number and adds them to an array
	cmp primeArray[esi], 0h
	jne moveOn
	mov ebx, esi
	mov temporary[edi], bx
	inc edi
	inc edi

	moveOn:
	inc esi
loop Filter
ret
temporaryPrime ENDP



Menu PROC
.data
displayMenu byte "Main Menu", endl,
"----------------------------------------------", endl,
"1. Display all primes between 2 and n (Max of 10,000)", endl,
"2. Euclids Algorithm", endl,
"3. Exit", endl,
"Make Selection (1-3): ", 0h

.code
push edx
mov edx, offset displayMenu
call writeString
call readDec
mov byte ptr[ebx], al
pop edx

ret
Menu ENDP



in1 PROC
.data
num1 byte ?
num2 byte ?
setup1 byte "There are ", 0h
setup2 byte " primes between 2 and n (n = ", 0h
setup3 byte ")", endl,
"----------------------------------------------", 0h

.code
call InputN
call primes
call CRLF
push edx
mov edx, offset setup1 ; The bulk of this code is just to display the text to the screen
call writeString
pop edx
call writedec
push edx
mov edx, offset setup2
call writestring
pop edx
mov ax, userN ; here is where we display the results of the calculations from the input
call WriteDec
push edx
mov edx, offset setup3
call writestring
pop edx
call CRLF
mov dx, userN
mov ebp, edx
call DisplayResults
call waitMsg
ret
in1 ENDP



in2 PROC
.data
menu1 byte "Enter First Non Zero Number : ", 0h ; Lines to use and display menu when called
menu2 byte "Enter Second Non Zero Number: ", 0h
menu3 byte "Number #1", 0h
menu4 byte "Number #2", 0h
menu5 byte "GCD", 0h
menu6 byte "GCD PRIME?", endl, 0h
menu7 byte "----------------------------------------------", endl, 0h
menuError byte "Please enter a VALID number", endl, 0h
numA dword ?
numB dword ?
numGCD dword ?

.code
call Clrscr
ReturnHere: ; return point
push edx
mov edx, offset menu1
call writeString ; Asking the user for 2 numbers to save and use
call ReadInt
cmp eax, 0 ; making sure number entered is not zero
je numError
mov numA, eax
pop edx
push edx
mov edx, offset menu2
call WriteString
call ReadInt
cmp eax, 0 ; making sure number entered is not zero
je ReturnHere
mov numB, eax
pop edx
call GCD
call ClrScr
push edx
mov edx, offset menu3
call WriteString
mov al, tab
call WriteChar
pop edx
push edx
mov edx, offset menu4
call writestring
mov al, tab
call WriteChar
pop edx
push edx
mov edx, offset menu5
call writestring
mov al, tab
call WriteChar
pop edx
push edx
mov edx, offset menu6
call writestring
pop edx
push edx
mov edx, offset menu7
call writestring
pop edx
mov eax, numA
call WriteInt
mov al, tab
call WriteChar
mov al, tab
call WriteChar
mov eax, numB
call WriteInt
mov al, tab
call WriteChar
mov al, tab
call WriteChar
mov eax, numGCD
call WriteDec
mov al, tab
call WriteChar
call checkPrime
jmp endofProcedure

numError:
pop edx
push edx
mov edx, offset menuError
call WriteString
call waitMsg
pop edx
call CRLF
jmp ReturnHere

endofProcedure:
call CRLF
call waitMsg
ret
in2 ENDP



InputN PROC
.data
Nput byte "Enter a number between 2 - 10,000: ", 0h
userN word 0h
errorN byte "Invalid number, please enter a new valid number: ", endl

.code
startN:
call ClrScr
push edx
mov edx, offset Nput
call WriteString ; asking the user for 2 more numbers to use
call readDec
mov userN, ax
pop edx
cmp userN, 2d ; exception handling for inputs under 2
jb invalidN
cmp userN, 10000d ; exception handling for inputs over limit
jbe validN
cmp userN, 10000d
ja invalidN

invalidN:
push edx
mov edx, offset errorN
call WriteString
call WaitMsg
pop edx
jmp startN

validN:
mov userN, ax

ret
InputN ENDP



DisplayResults PROC
.data
row = 7
tab = 9

.code
mov ebx, offset temporary
mov ecx, row
mov esi, 0
push ecx

Layout: ; this will lay out the information according to the given example output
	mov ecx, row
Layout2:
	mov ax, [esi + ebx]
	mov edx, eax
	cmp edx, 0
	je ending
	cmp edx, ebp
	ja ending
	call WriteDec
	add esi, 2
	mov edx, eax
	mov al, tab
	call WriteChar
	mov al, 0
	mov eax, edx
	dec ecx
	cmp ecx, 0
	je blank
	jmp Layout2

Blank: ; jump spot needed to satisfy 9 elements per row stipulation
call CRLF
jmp Layout

ending: ; once counter hits zero, it breaks out of procedure
mov ecx, 0
pop ecx
call CRLF

finishOut:
ret
DisplayResults ENDP



Primes PROC
.data
.code
mov ebx, offset temporary
mov cx, userN
mov esi, 0
mov ebp, 0

numPrime: ; counter that uses the input given in the beginning of the code, for the value of n
	mov ax,[esi + ebx]
	mov edx, eax
	cmp ax, userN
	ja found
	cmp edx, ebp
	jb found
	add esi, 2
	inc ebp
	dec ecx
	cmp ecx, 0
	je found
	jmp numPrime

Found:
mov eax, ebp
ret
Primes ENDP



GCD PROC
.data
.code
call Clearregs ; This will use an insertion sort algorithm to organize the arrray
mov eax, numA
cmp eax, numB
jb continue
cmp eax, numB
ja reverse

continue:
	mov eax, numA
	mov ebx, numB

reverse:
mov eax, numB
mov ebx, numA

calc: ; takes the absolute value of the GCD and tests the remainder to use in the recursive function
	cmp eax, 0
	jl absValue
	cmp ebx, 0
	jl absValue2
	xor edx, edx
	idiv ebx
	cmp edx, 0
	jne remainder
	jmp outcome

remainder: ; shifts entries if there is a remainder
	mov eax, ebx
	mov ebx, edx
	jmp calc

absValue: ; produces the absolute value of the GCD
	neg eax
	jmp calc

absValue2:
	neg ebx
	jmp calc

outcome:
mov numGCD, ebx
ret
GCD ENDP



checkPrime PROC
.data
isTrue byte "Yes", 0h
isFalse byte "No", 0h
isLength = LENGTHOF temporary

.code
call ClearRegs

mov esi, 0
mov ebx, offset temporary
mov edx, numGCD
cmp edx, 1
je yes
	mov ecx, isLength

Validate: ; validates whether the primes we added are within our given range
	cmp temporary[esi], dx
	je yes
	add esi, 2
	loop validate

jmp no

Yes:
	mov edx, offset isTrue
	call WriteString
	jmp finished

No:
	mov edx, offset isFalse
	call Writestring

Finished:
ret
checkPrime ENDP

END main