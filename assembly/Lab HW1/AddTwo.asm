include Irvine32.inc

.data
SimpMess BYTE "B",0	;0ah is endl in c++
SimpMess2 BYTE "A",0	;,0 ends the string
SimpMess3 BYTE "C",0
SimpMess4 BYTE "D",0
SimpMess5 BYTE "F",0
SimpNum BYTE "Enter the Grade:",0
name1 BYTE "                         ",0ah,0ah,0
SimpEM BYTE " in the class.",0
SimpM BYTE "Please Enter Student Name:",0
SimpS1 BYTE " ,you got a ",0

.code
main proc

	mov edx, offset SimpM
	call writestring
	mov edx, offset name1
	mov ecx, sizeof name1
	call readstring

	mov edx, offset SimpNum
	call writestring
	call readint
	mov ebx, eax

	call crlf
	mov edx, offset name1
	mov ecx, sizeof name1
	call writestring
	mov edx, offset SimpS1
	call writestring

	mov eax, 90		;Grade Checker Start
	cmp eax, ebx
	jg label2
	jl label1
label1:
	mov edx, offset SimpMess2
	jmp label9
label2:
	mov eax, 80
	cmp eax, ebx
	jg label4
	jl label3
label3:
	mov edx, offset SimpMess
	jmp label9
label4:
	mov eax, 70
	cmp eax, ebx
	jg label6
	jl label5
label5:
	mov edx, offset SimpMess3
	jmp label9
label6:
	mov eax, 60
	cmp eax, ebx
	jg label8
	jl label7
label7:
	mov edx, offset SimpMess4
	jmp label9
label8:
	mov edx, offset SimpMess5
	jmp label9
label9:
	call writestring	;Grade Checker End

	mov edx, offset SimpEM
	call writestring
	call crlf

	call WaitMsg

	exit

main ENDP
END main