include irvine32.inc

.data
;message BYTE "Enter five numbers to add",0dh,0ah,0                  ;0ah is endl in c++
msg2 byte "Thanks for sorting using bubble sort!",0dh,0ah,0
msg1 byte "Please enter 4 numbers",0dh,0ah,0
num dword 0
.code
main proc

	;mov eax, 21  ;i
	;mov ebx, 7 ;j
	;mov ecx, 3
	;mov edx, 4
	
	;div ebx
	;call writeint
	;call crlf

	;call dumpregs
	;sub ebx, eax
	;sub ebx, (eax)
	;neg ebx		;one way to change negative sign
	;not ebx			;twos complement
	;add ebx, 1
	;imul ebx, -1	;multiply by -1
	;xchg eax, ebx   ;swat eax and ebx
	;xor can be used too, but it used 3 lines
	;sub eax, ebx
	;call dumpregs

	mov edx, offset msg1
	call writestring
	
	call readint
	mov edx, eax
	call readint
	cmp eax, edx
	jg swap1
	mov ecx, eax
	jmp  section2

swap1:
	mov ecx, edx
	mov edx, eax
	
section2:  ;already done with the first 2 numbers in ecx, edx  (low to high)
	call readint
	cmp eax, ecx
	jg swap2
	mov ebx, eax
	jmp section3

swap2:
	mov ebx, ecx
	mov ecx, eax
	cmp ecx, edx
	jg swap3
	jmp section3

swap3:
	mov eax, edx
	mov edx, ecx
	mov ecx, eax		;swap ecx and edx using eax as the temp

section3:				;ebx, ecx and edx are sorted smallest to largest.
	call readint
	call dumpregs
	cmp eax, ebx
	jl swap4			
	add eax, ebx
	sub ebx, eax
	add eax, ebx
	call writeint  ;smallest displays on the screen!!
	sub eax, ebx
	add ebx, eax
	sub eax, ebx
	mov ebx, eax   ;we do not know if ebx is smallest, so continue to compare.
	jmp jumponce
swap4:					;all 4 are in order!!  display them all.
	call writeint
	mov eax, ebx
	call writeint
	mov eax, ecx
	call writeint
	mov eax, edx
	call writeint
	jmp section4

jumponce:
	cmp ebx, ecx
	jg swap5
	mov eax, ebx
	call writeint			;display the smaller one which is ebx
	mov eax, ecx
	call writeint
	mov eax, edx
	call writeint			;yay we are done displaying all 4.
	jmp section4
swap5:
	mov eax, ecx
	call writeint
	mov ecx, ebx
	
	cmp ecx, edx
	jg swap6
	mov eax, ecx
	call writeint
	mov eax, edx
	call writeint
	jmp section4

swap6:
	mov eax, edx
	call writeint
	mov eax, ecx
	call writeint

	section4:				;this is the end!

	mov edx, offset msg2
	call writestring
	Call WaitMsg

	exit

main ENDP
END main