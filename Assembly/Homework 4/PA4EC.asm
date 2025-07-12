; TITLE PA4.asm
; CSCI 2525 H01
; Due: 10 / 14 / 2022
Include Irvine32.inc

.data
userInput BYTE "Enter some an unsigned integer: " ;creating variables
arrayString BYTE 37 DUP (? ) ; making room for potential answer from user
recievedString DWORD ? ; where to store answer


.code							; Procedure User_In
User_In PROC ; registers used: EDX, EAX
mov EDX, offset userInput ; putting responce in edx register
call writestring ; displaying prompt
call readint ; recieve answer
mov recievedString, EAX ; move answer into variable for later use
ret
User_In ENDP


.code							; Procedure Strings
Strings PROC ; Registers used: EAX ECX EDX ESI
push ECX ; moving counter for later use
Call StringLen ; calling function from part 3
Loop1:
	mov ECX, EAX
	mov ESI,OFFSET arrayString
Loop2:
	call CapitalLetters ; Calling function from part 4
	call StringColor ; Call function from extra credit
loop Loop2
mov EDX, OFFSET arrayString
call WriteString
call Crlf
pop ECX
ret
Strings ENDP


.data
lengthOfString DWORD ?


.code							; Procedure StringLen
StringLen PROC ; Registers used: EAX
mov EAX, 19h ; setting upper threshold of string length
call RandomRange ; Calling Randomizer function
add EAX, 0Ah ; setting lower threshold of string length
mov lengthOfString, EAX
mov EAX, lengthOfString
ret
StringLen ENDP


.code							; Procedure HowMany
HowMany PROC ; Registers used: ECX
mov ECX, recievedString ; setting string to counter
Loop3:
	push ECX
	call Strings
	call ClrString
	pop ECX
loop Loop3
ret
HowMany ENDP


.code							; Procedure CapitalLetters
CapitalLetters PROC ; Registers Used: EAX, ESI
mov EAX, 19h ; 19h is 25d for the 26 letters in alphabet
call RandomRange
add EAX, 'A' ; setting EAX to first letter
mov [ESI], al ; moving that byte to ESI
inc ESI ; move to the next letter
sub EAX, 20h 
ret
CapitalLetters ENDP


.code							; Procedure ClrString
ClrString PROC ; Registers used: EAX, ECX, ESI
mov EAX, LengthOfString
Loop1:
	mov ECX, EAX
	mov ESI,OFFSET arrayString
Loop2:
	mov EAX, 0h
	mov [ESI], al
	inc ESI
loop Loop2
ret
ClrString ENDP

.code							; Procedure StringColor
StringColor PROC ; Registers used: EAX
push EAX
mov EAX, 15d ; calling 1 of 15 numbers to set as potential colors
call RandomRange
add EAX, 1d
call SetTextColor ; setting colors
pop EAX
ret
StringColor ENDP


.code 
main PROC
call Randomize
call User_In
call HowMany
call WaitMsg

exit
main ENDP
END main