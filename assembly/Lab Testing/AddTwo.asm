include irvine32.inc

.data

message BYTE "Yo my dude",0dh,0ah,0

.code


main proc

	mov eax, 0
	mov ecx, 10
	myloop1:
		inc eax
		loop myloop1

	call writeint

	Call WaitMsg

	exit

main ENDP
END main