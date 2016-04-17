TITLE Fibonacci Number       (Prog2.asm)

; Author: Grant Nakashima
; Course: CS 271-400 Assignment 2                    Date: 01/15/15
; Due Date: 01/25/15
; E-mail: nakashig@onid.oregonstate.edu
; Class: CS 271 400 W2015
; Description: This program will calculate Fibonacci numbers. The program will get the user's name 
; and then greet/display their name. It will then ask for was Fibonacci number they want
; to display. The program will get and validate their input before calculating and displaying
; the Fibonacci number. It will end with a farewell message before ending. 

INCLUDE Irvine32.inc

; defined constant 
FIBNUM = 47
ZERO = 0

.data
	userNum_1		DWORD    ?						; integer to be entered by user
	userName		BYTE	33 DUP(0)				;string entered by user
	intro_0			BYTE    "        Fibonacci Numbers        by Grant Nakashima", 0
	intro_1			BYTE    "Input a number and the Fibonacci number of that number will get displayed. ", 0
	intro_2			BYTE    "Give the number as an integer in the range [1-46]. ", 0
	greet_1			BYTE	"Hello ", 0	
	prompt_1		BYTE    "What's your name? ", 0
	prompt_2		BYTE    "What's your number? ", 0
	prompt_3		BYTE	"Out of range. Enter a number between [1-46]. ", 0
	previous_num	DWORD	?
	current_num		DWORD	?
	next_num		DWORD	?
	sum_num			DWORD	?
	counter			DWORD	?
	finish			DWORD	?
	print_check		DWORD	?
	goodBye_0		BYTE    "Good-bye ", 0
	goodBye_1		BYTE	"That's a lot of numbers?", 0

.code
main PROC
; Introdution
    mov		edx, OFFSET intro_0			;used when calling WriteString
    call    WriteString					;"        Fibonacci Numbers        by Grant Nakashima"
    call    CrLF
    call    CrLF

; Get user name
    mov     edx, OFFSET prompt_1
    call    WriteString					;"What's your name?."
	mov		edx, OFFSET userName
	mov		ecx, 32						
    call    ReadString

; Greet user
	mov		edx, OFFSET	greet_1
	call	WriteString					;"Hello "
	mov		edx, OFFSET userName
	call	WriteString					;user's name'
    call    CrLF

; Get user input
	mov		edx, OFFSET intro_1
	call	WriteString					;"Input a number and the Fibonacci number of that number will get displayed"
	call	CrLF

;Get number
	mov		edx, OFFSET intro_2
	call	WriteString					;"Give the number as an integer in the range [1-46]"
	mov     edx, OFFSET prompt_2
	call	CrLF
    call    WriteString					;"What's the number?"
    call    ReadInt						; save input from user for userNum1
	mov		userNum_1, eax
	mov		ebx, userNum_1
	cmp		ebx, FIBNUM					; checks if greater than 46
    jge		validate
	cmp		ebx, ZERO					; checks if less than 0
	jl		validate
	jmp		Start

;make post-test loop until valid
validate:	
	mov		edx, OFFSET prompt_3
	call	WriteString
	call	CrLF
	mov     edx, OFFSET prompt_2
	call	CrLF
	call    WriteString					;"What's the number?"
    call    ReadInt						; save input from user for userNum1
	mov		userNum_1, eax
	mov		ebx, userNum_1
	cmp		ebx, FIBNUM
    jge		validate
	cmp		ebx, ZERO
	jl		validate
	jmp		Start

; Set up numbers
Start:
	mov		previous_num, -1			; a = -1
    mov		current_num, 1				; b = 1
	mov		eax,1
	mov		ecx, userNum_1				; set loop counter to users input
	mov		userNum_1, ecx 
	mov		ebx, current_num			
	add		ebx, previous_num			
	mov		sum_num, ebx				; sum_num is 0 to start off as
	mov		ebx, current_num			; sets ebx to 1
	mov		previous_num, ebx			; set to previous number so we can start with 1
	mov		eax, sum_num				; sum is 0 will allow two prints of 1
	mov		current_num, eax
	call	CrLF
	call	CrLF
	jle		L1

;loop for fibonacci number
L1:
    mov		userNum_1, ecx				; set loop
	mov		ebx, current_num			; current is 0 on first loop
	add		ebx, previous_num			; previous stays 0 on second loop
	mov		sum_num, ebx
	mov		ebx, current_num
	mov		previous_num, ebx
	mov		eax, sum_num
	mov		current_num, eax
    call    WriteDec					; prints
	jmp		Print_Counter

;check number of prints
Print_Counter:
	inc		counter						;increments counter
	cmp		counter, 5					; compares to 5
	je		Reset_Counter				; will reset if equal to 5
	inc		print_check
	cmp		print_check, 29				; anything above 29 will get aligned oddly
	jge		Print1
	mov		al, TAB						; adds tabs to organize the print
	call	WriteChar
	call	WriteChar
	jmp		Continue_Loop				;decrements loop counter

; make new line when 5 numbers have been printed
Reset_Counter:
	call	CrLF						; makes new line
	mov		counter, 0					; resets counter to 0
	jmp		Continue_Loop				;decrements loop counter

;loop decrementer
Continue_Loop:
	loop	L1
	cmp		finish, 0					; make sure it breaks when ecx is 0
	je		Goodbye						

; tab for large numbers
Print1:		
	mov		al, TAB						; adds tabs to organize the print
	call	WriteChar
	jmp		Continue_Loop				;decrements loop counter

; Say goodbye
Goodbye:
	call	CrLF       
	call	CrLF     
    mov     edx, OFFSET goodBye_1
    call    WriteString					;"That's a lot of numbers? "
	call	CrLF
	mov     edx, OFFSET goodBye_0
    call    WriteString					;"Good-bye "
	mov		edx, OFFSET userName
	call	WriteString					;User's name
    call    CrLF
    call    CrLF

    exit								 ; exit to operating system

main ENDP

END main