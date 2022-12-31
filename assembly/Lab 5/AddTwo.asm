TITLE MASM Template						(main.asm)

INCLUDE Irvine32.inc
.data

myNameMsg byte "Enter your Name:",0
myMessage BYTE "Student number ",0
mymessage2 byte ",enter 5 grades",0dh,0ah,0
mymessage3 byte "grade number",0
mymessage4 byte ":  ",0
mymessage5 byte " Average is a ",0
mymessage6 byte " Letter Grade is a ",0

SimpMess BYTE "B",0ah,0	;0ah is endl in c++
SimpMess2 BYTE "A",0ah,0	;,0 ends the string
SimpMess3 BYTE "C",0ah,0
SimpMess4 BYTE "D",0ah,0
SimpMess5 BYTE "F",0ah,0

Name1 byte "         ",0ah,0
Name2 byte "         ",0ah,0
Name3 byte "         ",0ah,0

Sum1 dword 0
Sum2 dword 0
Sum3 dword 0

.Code
;|-------------|
getAvg proc

	mov edx, 0
	mov ecx, 5
	div ecx

	call writeint

ret
getAvg endp
;|-------------|
;|-------------|
getLetterG proc

	mov ebx, eax
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

ret
getLetterG endp
;|-------------|
main PROC

	mov ecx, sizeof Name1
	mov ebx, offset Name1
	mov edx, offset myNameMsg
	call writestring
	mov edx, ebx
	mov ebx, eax
	call readstring

	mov ecx, sizeof Name2
	mov ebx, offset Name2
	mov edx, offset myNamemsg
	call writestring
	mov edx, ebx
	mov ebx, eax
	call readstring

	mov ecx, sizeof name3
	mov ebx, offset name3
	mov edx, offset myNamemsg
	call writestring
	mov edx, ebx
	mov ebx, eax
	call readstring

	mov ecx, 3					;initialize outer loop
	L1:
	mov ebx, ecx				;store outer loop counter in ebx
	mov edx, offset mymessage
	call writestring
	mov eax, 4
	sub eax, ecx
	call writeint				;display student number
	mov edx, offset mymessage2
	call writestring
		mov ecx, 5				;init inner loop to 5
		mov edx, 0				;init sum to 0
		L2:
		mov eax, edx			;move sum to eax
		mov edx, offset mymessage3
		call writestring
		mov edx, eax			;move sum back to edx
		mov eax, 6
		sub eax, ecx
		call writeint
		mov eax, edx			;move sum back to eax
		mov edx, offset mymessage4
		call writestring
		mov edx, eax			;move sum back to edx
		call readint
		add edx, eax			;add to sum

		loop L2
		mov eax, edx			;sum is in eax

		cmp ebx, 3
		je S1
		cmp ebx, 2
		je S2
		cmp ebx, 1
		je S3
		S1:
		mov Sum1, eax
		mov ecx, ebx
		loop L1
		Sm1:
		mov ecx, ebx
		loop L1
		S2:
		mov Sum2, eax
		mov ecx, ebx
		jmp Sm1
		S3:
		mov Sum3, eax
		jmp out1
		call crlf
		call crlf				;outer loop moved back to ecx
	out1:

	mov edx, offset Name1
	call writestring
	mov edx, offset mymessage5
	call writestring
	mov eax, Sum1
	call getAvg
	mov edx, offset mymessage6
	call writestring
	call getLetterG

	mov edx, offset Name2
	call writestring
	mov edx, offset mymessage5
	call writestring
	mov eax, Sum2
	call getAvg
	mov edx, offset mymessage6
	call writestring
	call getLetterG

	mov edx, offset Name3
	call writestring
	mov edx, offset mymessage5
	call writestring
	mov eax, Sum3
	call getAvg
	mov edx, offset mymessage6
	call writestring
	call getLetterG

	call WaitMsg
	
	exit
main ENDP

END main