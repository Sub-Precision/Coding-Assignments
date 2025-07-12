INCLUDE Irvine32.inc
;constants
maxStrLen = 51d
newLine EQU<0ah, 0dh>
.data
theString BYTE maxStrLen DUP(0h)
tempString BYTE maxStrLen DUP(0h)
realStrLen BYTE maxStrLen
userOption BYTE 0h
errorMsg BYTE "You have selected an invalid option.", 
			   newline, "Please try again.", newline, 0h
.code
main PROC

call clearRegs
startHere:
	call clrscr
	mov EBX, OFFSET userOption
	call DisplayMenu
	;is option legal
	cmp userOption, 1d
	jb invalid
	cmp userOption, 6d
	jb driver
	cmp userOption, 6d
	je done
invalid:
	push EDX
	mov EDX, OFFSET errorMsg
	call WriteString
	call WaitMsg
driver:
	movzx ECX, realStrLen
	mov EDX, OFFSET theString
	mov EBP, OFFSET tempString
	mov EDI, OFFSET realStrLen
	call pickAProc
jmp StartHere
done:

exit
main ENDP

clearRegs PROC 
	
	mov EAX, 0h
	mov EBX, 0h
	mov ECX, 0h
	mov EDX, 0h
	mov ESI, 0h
	mov EDI, 0h

	ret 
clearRegs ENDP

displayMenu PROC
	.data
	MainMenu BYTE "Main Menu", newline, 
	"1.  Enter a string", newline, 
	"2.  Convert the string to lower case", newline, 
	"3.  Remove all non-alphanumeric characters", newline,
	"4.  Display only the numbers in the string" , newline, 
	"5.  Print the string", newline, 
	"6.  Quit", newline, 
	"         Please make a selection ==>   ", 0h

	.code
	push EDX
	mov EDX, OFFSET MainMenu
	call WriteString
	call ReadDec
	mov BYTE PTR[EBX], AL
	pop EDX
	ret
displayMenu ENDP

pickAProc PROC
	cmp AL, 2d
	jb option1

	cmp AL, 3d
	jb option2

	cmp AL, 4d
	jb option3

	cmp Al, 5d
	jb option4
	call OPT5
	jmp QuitIt

	option1:
		call OPT1
		jmp QuitIt
	option2:
		call OPT2
		jmp QuitIt
	option3:
		call OPT3
		jmp QuitIt
	option4:
		call OPT4
		jmp QuitIt
	QuitIt:
	ret
pickAProc ENDP

Opt1 PROC
	.data
	opt1Prompt byte "Please enter a string up to 50 characters long", newLine,
				    "     ==>    ",0h
	.code
	push EDX
	mov EDX, OFFSET opt1Prompt
	call WriteString
	pop EDX
	call ReadString
	mov BYTE PTR[EDI], AL
	mov ECX, EAX
	ret
Opt1 ENDP

Opt2 PROC
	push ESI
	push ECX

	opt2Loop:
	mov bl, byte ptr [edx + esi]

	cmp bl, 41h
	jb cont
	cmp bl, 5Ah
	ja cont
	or byte ptr [edx + esi], 20h

	cont:
		inc esi
		loop opt2Loop
	;//NEEDS COPY STRING PROC
	
	pop ECX
	pop ESI
	ret
Opt2 ENDP

Opt3 PROC ; Registers Used: ebx, esi, edi, ebp
	push esi
	push edi ; saving values already placed in both registers
	mov edi, 0
	opt3Loop:
	mov bl, byte ptr [ esi + edx] ; starting spot for array
	cmp bl, 30h ; below ASCII letter and number values
	jb invalidCharacter
	cmp bl, 7Ah ; above ASCII letter and number values
	ja invalidCharacter
	cmp bl, 39h ; numbers in ASCII
	jbe validCharacter
	cmp bl, 40h ; invalidating characters between numbers and uppercase letters in ASCII
	jb invalidCharacter
	cmp bl, 5Ah ; capital letters in ASCII
	jbe validCharacter
	cmp bl, 61h ; invalidating characters between uppercase and lowercase letters in ASCII
	jb invalidCharacter
	cmp bl, 7Ah ; lowercase letters in ASCII
	jbe validCharacter

	validCharacter:
	mov byte ptr [edi + ebp], bl ; copying characters to temporary string
	inc edi ; increment index of temporary string

	invalidCharacter:
	inc esi
	loop opt3Loop

	call clearstring ; clears the string
	call copyString ; copying the temporary string to the string
	call clearTemporaryString ; clears temporary string for next available use
	pop esi
	pop edi ; restore used registers to original values
	ret
Opt3 ENDP

Opt4 PROC
     push esi
	push edi ; saving values already placed in both registers
	mov edi, 0
	opt4Loop:
	mov bl, byte ptr [ esi + edx] ; starting spot for array
	cmp bl, 30h ; below ASCII letter and number values
	jb invalidCharacter
	cmp bl, 39h ; above numbers in ASCII
	ja invalidCharacter
	cmp bl, 39h ; numbers in ASCII
	jbe validCharacter

	validCharacter:
	mov byte ptr [edi + ebp], bl ; copying characters to temporary string
	inc edi ; increment index of temporary string

	invalidCharacter:
	inc esi
	loop opt4Loop

	cmp edi, 0 ; comparing edi to 0 to test if any numbers were found
	je message

	message:
	messageString BYTE "There are no numbers in the string", newline
	push EDX
	mov EDX, OFFSET messageString
	call WriteString
	call ReadDec
	mov BYTE PTR[EBX], AL
	pop EDX

	call clearstring ; clears the string
	call copyString ; copying the temporary string to the string
	call clearTemporaryString ; clears temporary string for next available use
	pop esi
	pop edi ; restore used registers to original values
	ret
Opt4 ENDP

Opt5 PROC
	.data
	op5Prompt BYTE "the string is: ",0h
	.code
	push EDX
	mov EDX, OFFSET op5Prompt
	call WriteString
	pop EDX
	call WriteString
	call crlf
	call WaitMsg
	ret
Opt5 ENDP

copyString PROC
LoopC:
	mov al, [ebp]
	mov [edx], al
	inc edx
	inc ebp
	cmp byte ptr [ebp], 0
	jne LoopC
ret
copyString ENDP

clearString PROC
push esi
Loop1:
	mov esi, OFFSET theString
	mov cl, realStrLen
Loop2:
	mov eax, 0
	mov [esi], al
	inc esi
loop Loop2
pop esi
ret
clearString ENDP

clearTemporaryString PROC
push ecx
push esi
Loop3:
	mov esi, OFFSET tempString
	mov cl, maxStrLen
Loop4:
	mov eax, 0h
	mov [esi], al
	inc esi
loop Loop4
pop esi
pop ecx
ret
clearTemporaryString ENDP

END main