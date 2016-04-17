TITLE Integer Accumulator       (Prog3.asm)

; Author: Grant Nakashima
; Course: CS 271-400 Assignment 3                    Date: 02/01/15
; Due Date: 02/08/15
; E-mail: nakashig@onid.oregonstate.edu
; Class: CS 271 400 W2015
; Description: This program get the user's input for numbers and add them up and takes the average.
; Constants are used for the upper limits of the numbers they can input and the lower limit of inputs.
; Although floating points would be better for computing the average, integers are used. The rounded
; averaged compares the remainder to half of the total numbers inputted. For example, if 8 numbers were
; inputted, we would compare the remainder to 4. The reason behind it is if the remainder is half of the 
; number of inputs, it will translate to 0.5. If it is 0.5 we would round up. If there aren't any numbers
; inputted, the user will get told there is no sum and to redo it. 

INCLUDE Irvine32.inc

; defined constant 
TOP = 101
ZERO = 0

.data
	userNum_1		DWORD    ?	; integer to be entered by user
	userName		BYTE	33 DUP(0)	;string entered by user
	intro_0			BYTE    "        Welcome to Integer Accumulator by Grant Nakashima", 0
	intro_1			BYTE    "Enter in a set of numbers less than or equal to 100. ", 0
	intro_2			BYTE    "Enter in a negative number to stop and see results. ", 0
	greet_1			BYTE	"Hello ", 0	
	prompt_1		BYTE    "What's your name? ", 0
	prompt_2		BYTE    "Number ", 0
	prompt_2_1		BYTE	": ", 0
	prompt_3		BYTE	"Out of range. Enter a number between [0-100].", 0
	prompt_4		BYTE	"You entered ", 0
	prompt_5		BYTE	" numbers.",0
	prompt_6		BYTE	"The sum of your numbers was: ", 0
	prompt_7		BYTE	"The rounded average was: ", 0
	special_m		BYTE	"There is no sum. Please redo with numbers. ", 0
	previous_num	DWORD	?
	current_num		DWORD	?
	counter			DWORD	0
	sum_num			DWORD	?
	div_num			DWORD	?
	remainder		DWORD	?
	divisor			DWORD	?
	goodBye_0		BYTE    "Good-bye ", 0
	goodBye_1		BYTE	"That's a lot of numbers?", 0

.code
main PROC

; Introdution
    mov		edx, OFFSET intro_0			; used when calling WriteString
    call    WriteString					; "        Welcome to Integer Accumulator by Grant Nakashima",
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
	call	WriteString					;"Enter in a set of numbers less than or equal to 100. "
	call	CrLF
	mov		edx, OFFSET intro_2
	call	WriteString					;"Enter in a negative number to stop and see results. ",
  
;Get number
GetNum:
	mov		ecx, 2
	mov     edx, OFFSET prompt_2		;"Number "
	call	CrLF
    call    WriteString					
	mov		eax, counter				; to display numbers
	add		eax, 1						; increments counter
	mov		counter, eax
	call	WriteDec
	mov		edx, OFFSET prompt_2_1		; ": "
	call	WriteString
    call    ReadInt						; save input from user for userNum1
	mov		userNum_1, eax
	mov		ebx, userNum_1
	cmp		ebx, TOP					; checks if greater than 101
    jge		validate
	cmp		ebx, ZERO					; checks if less than 0
	jl		break
	mov		ebx, previous_num 			; a = 0 on first loop
    add		ebx, userNum_1				; b = user's input
	mov		sum_num, ebx
	mov		previous_num, ebx			; set to sum to get accumulated
	jmp		GetNum						; goes to get added up

; Validate user's input
validate:	
	mov		edx, OFFSET prompt_3		;"Out of range. Enter a number between [0-100]."
	call	WriteString
	call	CrLF
	mov     edx, OFFSET prompt_2		;"Number ? "
	call	CrLF
	call    WriteString					
	mov		eax, counter				; display number
	add		eax, 1						; increment the counter
	mov		counter, eax
	call	WriteDec
	mov		edx, OFFSET prompt_2_1		; ": "
	call	WriteString
    call    ReadInt						; save input from user for userNum1
	mov		userNum_1, eax
	mov		ebx, userNum_1
	cmp		ebx, TOP					; compare to upper limit
    jge		validate
	cmp		ebx, ZERO					; compare to lower limit 
	jl		break						; user quits if negative
	mov		ebx, previous_num 			; a = 0
    add		ebx, userNum_1				; b = user's input
	mov		sum_num, ebx
	mov		previous_num, ebx			; set to sum to get accumulated
	jmp		GetNum

; display result
break:
	mov		ebx, previous_num
	cmp		ebx, ZERO
	je		Special						; check if sum is 0 to display special message
	mov		ecx, 0
	mov		edx, OFFSET prompt_4		; "You entered "
	call	CrLF
    call    WriteString	
	mov		eax, counter
	sub		eax, 1						; subtract to get actual numbers entered
	mov		counter, eax			
	call	WriteDec					; display numbers entered
	mov		edx, OFFSET prompt_5		; " numbers."
	call	WriteString
	call	CrLF
	mov		edx, OFFSET prompt_6		;"The sum of your numbers was: "
	call	WriteString
	mov		eax, previous_num
	call	WriteDec					; sum
	call	CrLF
	mov		edx, OFFSET prompt_7		;"The rounded average was: "
	call	WriteString

; get average
	mov		edx, 0
	mov		eax, previous_num
	mov		ebx, counter				; divide sum by number of inputs
	div		ebx
	mov		div_num, eax				; quotient is in eax and remainder is in edx
	mov		remainder, edx				; compare remainder to div num to get rounded average
	mov		eax, div_num

; round average
	mov		edx, 0
	mov		eax, counter				; get half of counter
	mov		ebx, 2
	div		ebx
	mov		divisor, ebx				; compare counter remainder
	mov		eax, div_num
	mov		edx, remainder

	.if		edx >= divisor				; if equal or greater it's like 0.5
			inc eax
	.endif

	call	WriteDec
	call	CrLF

Special:
	mov		edx, OFFSET special_m			;"There is no sum. Please redo with numbers. "
	call	WriteString
	call	CrLF
	exit									; exit to operating system

; Say goodbye            
    mov     edx, OFFSET goodBye_1
    call    WriteString                    ;"That's a lot of numbers? "
	call	CrLF
	mov     edx, OFFSET goodBye_0
    call    WriteString                    ;"Good-bye "
	mov		edx, OFFSET userName
	call	WriteString						 ;User's name
    call    CrLF
    call    CrLF

    exit									; exit to operating system
		
main ENDP

END main