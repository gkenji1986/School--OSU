TITLE Elementary Arithmetic		(Prog1.asm)

; Author: Grant Nakashima
; Course: CS 271 Assignment 1					Date: 01/07/15
; E-mail: nakashig@onid.oregonstate.edu
; Class: CS 271 400 W2014
; Due Date: 01/18/2014
; Description: This is a simple MASM program that will take two numbers and show the sum, difference, product, quotient, and remainder. 

INCLUDE Irvine32.inc

.data
userNum_1	DWORD	?		; integer to be entered by user
userNum_2	DWORD	?		; integer to be entered by user
intro_0		BYTE	"		Elementary Arithmetic		by Grant Nakashima", 0
intro_1		BYTE	"Input 2 numbers and I'll display the sum, difference, product, quotient, and remainder of the two.", 0
promt_1		BYTE	"What's the first number? ", 0
promt_2		BYTE	"What's the second number? ", 0
sum			DWORD	0		; sum of two numbers 
difference	DWORD	0		; difference of two numbers 
product		DWORD	0		; product of two numbers 
quotient	DWORD	0		; quotient of two numbers 
remainder	DWORD	0		; remainder of two numbers 
plus		BYTE	" + " , 0
minus		BYTE	" - " , 0
times		BYTE	" * " , 0
divide		BYTE	" / " , 0
equal		BYTE	" = " , 0
remain		BYTE	" Remainder ", 0
goodBye		BYTE	"Amazing huh? Good-bye. ", 0

.code
main PROC
; Introdution
	mov		edx, OFFSET intro_0			;used when calling WriteString
	call	WriteString					;"		Elementary Arithmetic		by Grant Nakashima"
	call	CrLF
	call	CrLF
	mov		edx, OFFSET intro_1
	call	WriteString					;"Input 2 numbers and I'll display the sum, difference, product, quotient, and remainder of the two."
	call	CrLF
	call	CrLF

; Get user input
	mov		edx, OFFSET	promt_1
	call	WriteString					;"What's the first number?"
	call	ReadInt						;save input from user for userNum1
	mov		userNum_1, eax
	mov		edx, OFFSET	promt_2
	call	WriteString					;"What's the second number?"
	call	ReadInt						;save input from user for userNum2
	mov		userNum_2, eax
	call	CrLF

; Calculate numbers
; Calculate sum
	mov		eax, userNum_1
	add		eax, userNum_2				
	mov		sum, eax 

; Calculate difference
	mov		eax, userNum_1
	sub		eax, userNum_2				
	mov		difference, eax 

; Calculate product
	mov		eax, userNum_1
	mov		ebx, userNum_2
	mul		ebx							
	mov		product, eax

; Calculate quotient and remainder
	mov		eax, userNum_1
	mov		ebx, userNum_2
	div		ebx
	mov		quotient, eax				;quotient is in eax and remainder is in edx
	mov		remainder, edx

; display results
; display sum
	mov		eax, userNum_1 
	call	WriteDec
	mov		edx, OFFSET plus			
	call	WriteString					;"+"
	mov		eax, userNum_2
	call	WriteDec
	mov		edx, OFFSET equal
	call	WriteString					;"="
	mov		eax, sum
	call	WriteDec
	call	CrLF

; display difference
	mov		eax, userNum_1 
	call	WriteDec
	mov		edx, OFFSET minus
	call	WriteString					;"-"
	mov		eax, userNum_2
	call	WriteDec
	mov		edx, OFFSET equal
	call	WriteString					;"="
	mov		eax, difference
	call	WriteDec
	call	CrLF

; display product
	mov		eax, userNum_1 
	call	WriteDec
	mov		edx, OFFSET times
	call	WriteString					;"*"
	mov		eax, userNum_2
	call	WriteDec
	mov		edx, OFFSET equal
	call	WriteString					;"="
	mov		eax, product
	call	WriteDec
	call	CrLF

; display quotient and remainder
	mov		eax, userNum_1 
	call	WriteDec
	mov		edx, OFFSET divide
	call	WriteString					;"/"
	mov		eax, userNum_2
	call	WriteDec
	mov		edx, OFFSET equal
	call	WriteString					;"="
	mov		eax, quotient
	call	WriteDec
	mov		edx, OFFSET remain
	call	WriteString					;"remainder"
	mov		eax, remainder
	call	WriteDec
	call	CrLF
	call	CrLF	

; Say goodbye			
	mov		edx, OFFSET goodBye
	call	WriteString					;"Amazing huh? Good-bye. "
	call	CrLF
	call	CrLF

	exit	; exit to operating system

main ENDP

END main