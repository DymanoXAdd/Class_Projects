include Irvine32.inc

.data
SimpMess BYTE "Second Number is greater",0ah,0	;0ah is endl in c++
SimpMess2 BYTE "First Number is greater",0ah,0	;,0 ends the string
SimpMess3 BYTE "They are Same",0ah,0
name1 BYTE "                         ",0ah,0ah,0
SimpMess4 BYTE "Please Enter Name:",0

.code
main proc

	mov edx, offset SimpMess4
	call writestring
	mov edx, offset name1
	mov ecx, sizeof name1
	call readstring
	call writestring
	call crlf

	call readint
	mov ebx, eax
	call readint

	cmp eax, ebx
	jg label1
	jl label2
	mov edx, offset SimpMess3
	jmp label5
label1:
	mov edx, offset SimpMess
	jmp label5
label2:
	mov edx, offset SimpMess2
label5:
	call writestring

	call WaitMsg

	exit

main ENDP
END main