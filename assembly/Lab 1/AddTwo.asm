include Irvine32.inc

.data
SimpMess BYTE "Enter in a number:",0	;0ah is endl in c++
SimpMess2 BYTE "The answer is:",0	;,0 ends the string
SimpMess3 BYTE "Enter in a second number:",0 

.code
main proc
	mov	edx, OFFSET SimpMess
	call WriteString	;display message to screen

	call readint		;receive an int from the keyboard
						;add eax,2	;Will add 2 to eax
	mov ebx, eax

	call readint
	add ebx, eax

	call readint
	add ebx, eax

	call readint
	add ebx, eax

	call readint
	add ebx, eax
	mov eax, ebx
						;mov ebx, eax	;copy contents of eax to ebx

	mov	edx, OFFSET SimpMess2
	call WriteString	;display message2 to screen
	call writeint		;this is to write what is in eax to screen
	call crlf	;this is to go to next line

	call WaitMsg

	exit

main ENDP
END main