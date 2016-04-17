TITLE Prime Number       (Prog4.asm)

; Author: Grant Nakashima
; Course: CS 271-400 Assignment 4                    Date: 02/01/15
; Due Date: 02/15/15
; E-mail: nakashig@onid.oregonstate.edu
; Class: CS 271 400 W2015
; Description: This program will calculate prime numbers. The user will input a number
; and the program will print out the specified number of prime numbers. For example,
; if the user inputs 10, the program will output 10 prime numbers. There will be a set
; range from 0-200. If the user goes out of that range, they will be prompted to input
; a number inbetween that range. 
;Extra Credit: Columns aligned
;
INCLUDE Irvine32.inc

; defined constant 

TOP = 201
BOT = 1

.data
	userNum_1		DWORD    ?	; integer to be entered by user
	intro_0			BYTE    "        Prime Numbers by Grant Nakashima", 0
	intro_1			BYTE    "Enter the number of prime numbers you want to see. ", 0
	intro_2			BYTE    "Enter in number between 1 and 200.  Nothing over 200", 0
	prompt_1		BYTE    "What's your name? ", 0
	prompt_2		BYTE    "What's your number? ", 0
	prompt_3		BYTE	"Out of range. Enter a number between [0-200].", 0
	prompt_4		BYTE	"You entered ", 0
	prompt_5		BYTE	" numbers.",0
	prompt_6		BYTE	"The sum of your numbers was: ", 0
	prompt_7		BYTE	"The rounded average was: ", 0
	boolPrime		DWORD	0
	current_num		DWORD	1
	upper			DWORD	?
	p_num			DWORD	2
	sum_num			DWORD	?
	div_num			DWORD	?
	remainder		DWORD	?
	goodBye_0		BYTE    "Good-bye ", 0
	goodBye_1		BYTE	"That's a lot of numbers?", 0

.code
main PROC
	call			intro
	call			getUserData
	call			showPrimes
	call			farewell
	exit
main ENDP

intro		PROC
; Displays program and programmer name and instructs user what program will do
; receives: intro_0, prompt_1, prompt_1
; returns: none
; preconditions: edx initialized
; registers changed: edx
;-------------------------------------------------------------------------
    mov		edx, OFFSET intro_0			; used when calling WriteString
    call    WriteString					; "        Prime Numbers by Grant Nakashima",
    call    CrLF
    call    CrLF
	mov		edx, OFFSET intro_1
	call	WriteString					;"Enter the number of prime numbers you want to see. "
	call	CrLF
	mov		edx, OFFSET intro_2			;"Enter in number between 1 and 200.  Nothing over 200"
	call	WriteString					
	call	CrLF
	ret
intro		ENDP
	 
getUserData	PROC
; This procedure prompts user to enter an integer in [1..200].
; receives: receives user's input
; returns: userNum_1 with user input
; preconditions: userNum_1 in range [1..200], edx initialized
; registers changed: edx
;-------------------------------------------------------------------------
GetNum:
	mov     edx, OFFSET prompt_2		;"What's the number?"
	call	CrLF
    call    WriteString					
    call    ReadInt						; save input from user for userNum1
	call	validate
	ret

getUserData	ENDP 

validate	PROC
; This procedure validates the users input using a bottom and upper limit
; receives: receives user's input
; returns: userNum_1 with user input that is valid
; preconditions: userNum_1 in range [1..200], edx initialized
; registers changed: edx, ecx, ebx, eax
;-------------------------------------------------------------------------
validNum:	
	mov		userNum_1, eax				; set usernum_1 to eax
	mov		ebx, userNum_1				; set ebx to usernum_1
	cmp		ebx, TOP					; compare to 201
    jge		getVal						; jump if 201 or greater
	cmp		ebx, BOT					; check with 0
	jl		getVal						; loop again if less than 0
	mov		userNum_1, eax				; if valid set userNum_1
	mov		ecx, userNum_1				; set ecx to userNum_1
	ret

getVal:
	mov		edx, OFFSET prompt_3		;"Out of range. Enter a number between [1-200]."
	call	WriteString
	call	CrLF
	mov     edx, OFFSET prompt_2		;"What's your number? "
	call	CrLF
	call    WriteString					;"What's the number?"
    call    ReadInt						; save input from user for userNum1
	jmp		validNum					; jump to get check if valid
	
validate	ENDP

showPrimes	PROC
; Calculates and displays all of the prime numbers up to and including the
; prime to the user input
; receives: userNum_1, p_num, boolPrime
; returns: none
; preconditions: userNum_1 is in [1..200], count = 0, pnum = 2
; registers changed: eax, ebx, ecx, al
;-------------------------------------------------------------------------
Prime:
	inc		current_num					; increments next number to be checked
	mov		p_num, 2					; divisor reset to 2 will be used to check if prime
	mov		eax, current_num			; used to print 2
	mov		ebx, current_num			; checking to see if it is 2
	cmp		ebx, 2						; if two print
	je		L1							; only used to print 2
	call	isPrime						; sub procedure to check primes
	cmp		boolPrime, 1				; checks if it is prime
	je		L1							; goes to get pushed onto stack
	jmp		Prime						; jumps back to prime to not change ecs


L1:
	push	eax							; push eax onto stack
	jmp		print						; jump to print

print:
	pop		eax		
	call	WriteDec					; print the prim number
	mov		al, TAB						; adds tabs to organize the print
	call	WriteChar					; print the tab
	mov		boolPrime, 0				; back to 0 so can check for primes
	loop	Prime						; increment ecx
	call	CrLF
	ret									; exit procedure

showPrimes	ENDP

isPrime		PROC
; Calculates which numbers are prime
; receives: current_num, p_num, boolPrime
; returns: boolPrime
; preconditions: userNum_1 is in [1..200], count = 0, pnum = 2
; registers changed: eax, ebx, ecx, edx
;-------------------------------------------------------------------------
CheckPrime:
	mov		edx, 0						; initialize edx
	mov		eax, current_num			; call current number to be checked
	mov		ebx, p_num					; sees if current number has factor
	div		ebx							; divide numbers
	cmp		edx, 0						; if 0 divides evenly
	je		badPrime					; jumps back to prime if even not prime
	inc		p_num						; remainder found increment to divide next number
	mov		ebx, p_num					; check if the same as current num
	cmp		ebx, current_num			; if all numbers except 1 and 7 have remainder it is prime
	jl		CheckPrime					; if less than 7 loop again
	mov		eax, current_num			; move to eax
	jmp		goodPrime					; jumps when prime found

badPrime:
	mov		boolPrime, 0				; indicate not a prime
	ret
goodPrime:
	mov		boolPrime, 1				; indicate is a prime
	ret

isPrime		ENDP

farewell	PROC 
;Displays a farewell message
;receives: goodBye_1 and 0
;returns: string message
;preconditions: edx initialized
;registers changed: edx
;-------------------------------------------------------------------------
goodBye:
	call	CrLF           
    mov     edx, OFFSET goodBye_1
    call    WriteString                    ;"That's a lot of numbers? "
	call	CrLF
	mov     edx, OFFSET goodBye_0
    call    WriteString                    ;"Good-bye "
    call    CrLF
    call    CrLF
	ret
farewell	ENDP

END main