TITLE Designing low-level I/O procedures       (Prog6.asm)

; Author: Grant Nakashima
; Course: CS 271-400 Assignment 6                    Date: 03/09/15
; Due Date: 03/15/15
; E-mail: nakashig@onid.oregonstate.edu
; Class: CS 271 400 W2015
; Description: The assignment required us to design, implement and call low level I/O procedures and 
; implement macros. We had to had two create two procedures, ReadVal and WriteVal. In my design, I separated
; the writting part for the sum and average because when originally wrote it out, it looked really confusing on
; what was happening. To avoid confusion, I made a separate procedure just for those to make it more readable. 
; The two macros we had to make for these two procedures were, getString and displayString. getString got the input
; from the user while displayString printed the string input. We had to convert the string to an integer and then
; convert it back to a string before we wrote it. We had to use the either/both of the two operators; lodsb and stosb.
; I used lodsb in both coversions but I did not use stosb. 

INCLUDE Irvine32.inc

; defined constant 


.stack				4096

mWriteStr MACRO buffer
	push			edx								; save edx register
	mov				edx, OFFSET buffer				; buffer will be replaced with parameter
	call			WriteString						; write parameter
	call			CrlF
	pop				edx
ENDM

getString MACRO arrayVal, arrayVal1, arrayVal3
	push			edx
    mov				edx, OFFSET arrayVal			; inputMessage
    call            WriteString
    mov				edx, OFFSET arrayVal1			; input
    mov				ecx, (SIZEOF arrayVal1) -1		; get every minus the null
    call            ReadString
    mov				arrayVal3, eax					; array
    mov				ecx, eax
    mov				esi, OFFSET arrayVal1
	pop				edx
    cld
ENDM

displayString MACRO	buffer
	push			edx								; save edx register
	mov				edx, OFFSET buffer				; buffer will be replaced with parameter
	call			WriteString
	pop				edx
	
ENDM

.data
	intro_0			BYTE    "PROGRAMMING ASSIGNMENT 6: Designing low-level I/O procedures ",0 
	intro_1			BYTE	"Written by: Grant Nakashima ", 0
	intro_2			BYTE    "Please provide 10 unsigned decimal integers. ", 0
	intro_3			BYTE    "Each number needs to be small enough to fit inside a 32 bit register. ", 0
	intro_4			BYTE	"After you have finished inputting the raw numbers I will display a list ", 0
	intro_5			BYTE	"of the integers, their sum, and their average value. ", 0
	outOfRange		BYTE    "Out of range. Invalid input. ", 0
	inputMessage	BYTE	"Please enter an unsigned number: ", 0
	numDisplayMes	BYTE	"You entered the following numbers: ", 0 
	sumMessage		BYTE	"The sum of these numbers is: ", 0
	aveMessage		BYTE	"The average is: ",0
	space			BYTE	", ", 0
	farewell		BYTE	"Thank you for playing ", 0
	array			DWORD	10		DUP(?)
	String			BYTE	33		DUP(0)
	input			BYTE	33		DUP(0)		; user input
	sum				DWORD	?
	average			DWORD	?
	sLength			DWORD	10
	counter			DWORD	?


.code
main				PROC

	call			intro						; go to intro procedure
					
	push			OFFSET array				; add array by reference
	call			ReadVal						; go to procedure

	push			OFFSET sum					; pass sum by reference
	push			OFFSET array				; pass array by reference
	call			GetSum						; go to procedure

	push			sum							; pass sum by value
	push			OFFSET average				; pass average by reference
	call			GetAve						; go to procedure

	push			OFFSET counter				; pass counter by reference
	push			OFFSET String				; pass string temp by reference
	push			OFFSET array				; pass array by reference
	call			WriteVal					; go to procedure

	push			OFFSET counter				; pass counter by reference
	push			OFFSET average				; pass average by reference
	push			OFFSET sum					; pass sum by reference
	push			OFFSET String				; pass string temp by reference
	call			averageSum					; go to procedure

	exit										; exit from program
main				ENDP

intro				PROC
; Displays program and programmer name and instructs user what program will do
; receives: intro_0 (ref), intro_1 (ref), intro_2 (ref), intro_3 (ref)
; returns: none
; preconditions: edx initialized
; registers changed: edx
;-------------------------------------------------------------------------
	pushad
	mWriteStr			intro_0					;"PROGRAMMING ASSIGNMENT 6: Designing low-level I/O procedures "
	mWriteStr			intro_1					;"Written by: Grant Nakashima "
	call				Crlf
	mWriteStr			intro_2					;"Please provide 10 unsigned decimal integers. "
	mWriteStr			intro_3					;"Each number needs to be small enough to fit inside a 32 bit register. "
	mWriteStr			intro_4					;"After you have finished inputting the raw numbers I will display a list "
	mWriteStr			intro_5					;"of the integers, their sum, and their average value. "
	popad
	ret
intro				ENDP

ReadVal				PROC
; Gets the user's input, validates their input puts it into an array 
; receives: array
; returns: array filled
; preconditions: receives array as paramter
; registers changed: edx, ecx, eax, edi, ebx, 
;-------------------------------------------------------------------------
	pushad
	mov				ebp, esp
	mov				ecx, 10						; set counter to 10 to get 10 inputs
	mov				ebx, 0
	mov				edi, [ebp+ 36]

nextNum:    
    push			ebx				
	push			ecx							; save loop counter
	push			edx	
	push			eax
    jmp				GetInput
GetInput:
    getString		inputMessage, input, sLength		; get input from user
validate:
	lodsb	
    cmp				al, 48						; check if its a num between 0
    jl				invalid						; less than 0
    cmp				al, 57						; check if its betweeen 9
    jg				invalid						; greater than 9
    jmp				keep
        
keep:
    push			eax
    push			ecx
    mov				eax, ebx					; move total to eax
    mov				ecx, 10						; move 10 to ecx 
    mul				ecx							; multiply eax by 10
    mov				edx, eax					; move total to edx
    pop				ecx
    pop				eax
    sub				al, 48						; used to get the single digit        
    movsx			ebx, al						; move converted to num to ebx
    add				edx, ebx					; add converted total to accumulated total
    mov				ebx, edx					; move total to ebx
    loop			validate					; loop if string not finished
    mov				eax, ebx					; move final integer to eax
	cmp				eax, 4294967295				; check if integer is valid size
	je				invalid						; reinput if too large
    mov				[edi], eax					; move to array if valid
    add				edi, 4						; increment to next array position
    pop				eax
	pop				edx
	pop				ecx
	pop				ebx            
    loop			nextNum						; get next number if not 10th input
	jmp				done						; exit input sequence
	
invalid:
	mWriteStr		OutOfRange					; print error message
	jmp				GetInput					; reinput 
	
done:
	popad			
	ret				8
ReadVal				ENDP

GetSum				PROC
; Adds up the values in the array to get a sum
; receives: sum and array
; returns: the sum of the array of integers
; preconditions: must receive an array of integers to produce the sum
; registers changed: edi,eax ebx, ecx
;-------------------------------------------------------------------------
	pushad
	mov				ebp, esp			
	mov				edi, [ebp+36]				; move sum to edi
	mov				eax, 0						; make eax 0
	mov				ecx, 10						; make ecx 10

	L1:
	add				eax, [edi]					; add number at address of edi to eax 
	add				edi, 4						; move to next array number	
	loop			L1							; loop to start adding array up
	mov				ebx, [ebp+40]				; move sum number to ebx
	mov				[ebx], eax					; move summed number to sum
	popad
	ret				12

GetSum				ENDP

GetAve				PROC
; Takes the sum of the array and finds the average of the array
; receives: sum and average
; returns: the average of the sum
; preconditions: must receive a sum to be able to produce an average
; registers changed: edi,eax ebx, ecx
;-------------------------------------------------------------------------
	pushad
	mov				ebp,esp						
	mov				edx, 0						; initialize edx before dividing
	mov				eax,[ebp+40]				; move sum to eax
	mov				ecx, 10						; divide sum by total inputs of 10
	div				ecx
	mov				ebx, [ebp+36]				; move average variable to ebx
	mov				[ebx], eax					; move result to average
	popad
	ret				12

GetAve				ENDP

WriteVal			PROC
; Converts the integers back to strings and prints them
; receives: array, a temp string and counter
; returns: none, prints the array
; preconditions: must have an array of integers
; registers changed: edx, esi, edi, eax, ecx, ebx
;-------------------------------------------------------------------------
	pushad
	mov				ebp, esp
	mWriteStr		numDisplayMes				; "You entered the following numbers: "
	mov				ecx, 10						; move 10 to ecx loop counter
	mov				esi, [ebp + 36]				; move array to esi register
	mov				edi, esi					; copy array to edi register

newNum:
	cld											; clear direction flag forward direction
	push			ecx							; save counter for main loop
	mov				ecx, 10						; set ecx to 10 to divide num by 10
	xor				ebx, ebx					; set ebx to zero 
	lodsd
divide:
	xor				edx, edx					; set edx to zero
	div				ecx							; divide eax by ecx
	push			edx							; build number back to front
	inc				ebx							; increment to get string size
	test			eax,eax						; check if eax is 0
	jnz				divide						; if zero move on
	mov				ecx,ebx						; move size to ecx
	mov				ebx, [ebp+40]				; move temp to ebx

nextNum:
	pop				eax			
	add				al, 48						; convert to ASCII
	mov				[ebx], al					; write to temp
	cmp				ecx, 1						; check if last input
	jg				L1
	je				L2

L1:
	inc				ebx							; move to next byte
	loop			nextNum						; get next byte 
L2:
	mov				BYTE PTR [ebx +1], 0		; add null to end of string
	loop			nextNum						; add to make ecx 0 to break 
	mov				eax, [ebp + 44]				; add counter to eax
	mov				ebx, 1						; move 1 to ebx
	add				[eax], ebx					; increment counter
	displayString	String						; print string
	mov				ebx, [eax]					; move counter to ebx
	cmp				ebx, 10						; compare to 10 to check if to add comma or not at end
	jl				comma						; add comma if 9 or less
	jge				lastInput					; dont add comma if 10
comma:
	displayString	space						; add comma
lastInput:
	pop				ecx							; pop ecx so loop counter will get decremented
	loop			newNum						; get new number if ecx not 0
	call			CrlF						; add space for readability
	popad
	ret				16
WriteVal			ENDP	

averageSum			PROC
; Converts the integers back to strings and prints the sum and average
; receives: sum, average, a temp string and counter
; returns: none, prints the sum and average 
; preconditions: must have the sum and average value
; registers changed: edx, esi, edi, eax, ecx, ebx
;-------------------------------------------------------------------------
	pushad
	mov				ebp, esp
	mov				eax, [ebp + 48]				; move counter to eax
	mov				ebx, 0						; move 0 to ebx
	mov				[eax], ebx					; reset counter to 0
	mWriteStr		sumMessage					; print sum message
	mov				esi,[ebp+40]				; move sum to esi
	mov				edi, esi					; move esi to edi
	
newNum:
	cld											; clear direction flag forward direction
	mov				ecx, 1						; set loop counter to 1 since only one number
	push			ecx							; save counter for main loop
	mov				ecx, 10						; set ecx to 10 to divide num by 10
	xor				ebx, ebx					; set ebx to zero 
	xor				eax,eax						; set eax to 0
	lodsd
divide:
	xor				edx, edx					; set edx to zero
	div				ecx							; divide eax by ecx
	push			edx							; build number back to front
	inc				ebx							; increment to get string size
	test			eax,eax						; check if eax is 0
	jnz				divide						; if zero move on
	mov				ecx,ebx						; move size to ecx
	mov				ebx, [ebp+36]				; move temp to ebx

nextNum:
	pop				eax			
	add				al, 48						; convert to ASCII
	mov				[ebx], al					; write to temp
	cmp				ecx, 1						; compare ecx to 1 to check if to move to next byte or not
	jg				L1							; jump to get next byte								
	je				L2							; jump to add null

L1:
	inc				ebx							; move to next byte
	loop			nextNum						; loop to convert next part to string
L2:
	mov				BYTE PTR [ebx +1], 0		; add null to end of string
	loop			nextNum						; added to make ecx 0 to break
	mov				eax, [ebp + 48]				; move counter to eax to check if average input done
	mov				ebx, 1						; move 1 to ebx
	add				[eax], ebx					; add 1 to ebx
	displayString	String						; display string
	mov				ebx, [eax]					; move counter to ebx
	cmp				ebx, 2						; compare counter to ebx
	jge				lastInput					; exit if last input
	call			Crlf						; add new line
	mWriteStr		aveMessage					; print average message
	mov				esi,[ebp+ 44]				; move average to esi
	mov				edi, esi					; move average to edi
	pop				edx							; pop edx or it will crash
	jmp				newNum						; jump to new number

lastInput:
	call			Crlf						; add new line
	pop				ecx							; pop ecx
	call			Crlf						; new line
	mWriteStr		farewell					; print farewell message
	popad
	ret				20
averageSum			ENDP

END main