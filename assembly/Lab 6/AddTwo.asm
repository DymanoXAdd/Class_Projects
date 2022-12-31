TITLE MASM Template						(main.asm)

INCLUDE Irvine32.inc
.data

myNameMsg byte "Enter your Name:",0
myMessage BYTE "Student number ",0
mymessage2 byte ",enter 5 grades",0dh,0ah,0
mymessage3 byte "grade number",0
mymessage4 byte ":  ",0

SimpMess BYTE "B",0ah,0	;0ah is endl in c++
SimpMess2 BYTE "A",0ah,0	;,0 ends the string
SimpMess3 BYTE "C",0ah,0
SimpMess4 BYTE "D",0ah,0
SimpMess5 BYTE "F",0ah,0

Name1 byte "         ",0ah,0
Name2 byte "         ",0ah,0
Name3 byte "         ",0ah,0

;for array
arr dword 3 dup (0)
num dword 0

Sum1 dword 0
Sum2 dword 0
Sum3 dword 0

.Code
;|-------------|
ArrayDis proc

	mov ecx, 5				;init inner loop to 5
	mov edx, 0				;init sum to 0
	L2:

	add esi, 4
	mov eax, [esi]
	call writeint

	loop L2

ret
ArrayDis endp
;|-------------|
;|-------------|
ArrayFun proc

add esi, 4

call readint
mov [esi], eax


ret
ArrayFun endp
;|-------------|
main PROC

	mov esi, offset arr

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
	call crlf
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
		call ArrayFun

		loop L2
		mov ecx, ebx
		loop L1

	sub esi, 60
	call crlf

	mov edx, offset Name1
	call writestring
	call ArrayDis
	call crlf

	mov edx, offset Name2
	call writestring
	call ArrayDis
	call crlf

	mov edx, offset Name3
	call writestring
	call ArrayDis

	call WaitMsg
	
	exit
main ENDP

END main