TITLE Sorting Random Integers       (Prog5.asm)

; Author: Grant Nakashima
; Course: CS 271-400 Assignment 5                    Date: 02/20/15
; Due Date: 03/01/15
; E-mail: nakashig@onid.oregonstate.edu
; Class: CS 271 400 W2015
; Description: This program will get the users input on how many random integers they want to print
; and display the unsorted x amount of random integers (that are pushed ino, the median of the numbers and then the sorted
; numbers. In order to do this, procedures and passing the variables as parameters are required for this assignment. 
; display list method and random range taken from Lecture 19. exchange borrowed from 
; http://stackoverflow.com/questions/13407151/select-sort-proceedure-in-assembly 
; 



INCLUDE Irvine32.inc

; defined constant 
MIN = 10
MAX = 200
HI = 999
LO = 100

.stack				4096

.data
	intro_0			BYTE    "        Sorting Random Integers  by Grant Nakashima",0 
	intro_1			BYTE    "This program makes random numbers from 100 to 999, ", 0dh, 0ah 
					BYTE    "displays the orginal list, sorts the list and finds the median. ", 0dh, 0ah
					BYTE	"It will show the list in decending order. ", 0
	getNumString	BYTE    "How many numbers should be generated? [10- 200]: ", 0
	outOfRange		BYTE    "Out of range. Invalid input. ", 0
	unsortMessage	BYTE	"The unsorted random numbers are: ", 0
	medianMessage	BYTE	"The median is: ", 0
	sortMessage		BYTE	"The sorted numbers are:  ", 0
	array			DWORD	MAX			DUP(?)
	count			DWORD	0
	request			DWORD	?

.code
main			PROC
	push			OFFSET intro_0			; parameter by reference title
	push			OFFSET intro_1			; parameter by reference instructions
	call			intro					; go to intro procedure
		
	push			OFFSET outOfRange		; parameter by reference error message
	push			OFFSET getNumString		; parameter by reference number request string
	push			OFFSET request			; parameter by reference size of array
	call			getUserData				; go to get user data procedure
	
	call			Randomize				; print random numbers
	push			OFFSET	array			; parameter by reference array
	push			request					; parameter by value size of array
	call			fillArray				; go to fill array procedure

	push			OFFSET array			; parameter by reference array
	push			request					; parameter by value size of array
	push			OFFSET unsortMessage	; parameter by reference message
	call			displayList				; go to procedure

	push			OFFSET array			; parameter by reference array
	push			request					; parameter by value size of array
	call			sortList				; go to display procedure
	
	push			OFFSET array			; parameter by reference array
	push			request					; parameter by value size of array
	push			OFFSET medianMessage	; parameter by reference median message
	call			displayMedian			; go to median procedure

	push			OFFSET array			; parameter by reference array
	push			request					; parameter by value size of array
	push			OFFSET sortMessage		; parameter by reference message for sorted numbers
	call			displayList				; go to display procedure

	exit
main			ENDP

intro			PROC
; Displays program and programmer name and instructs user what program will do
; receives: intro_0 (ref), intro_1 (ref), intro_2 (ref), intro_3 (ref)
; returns: none
; preconditions: edx initialized
; registers changed: edx
;-------------------------------------------------------------------------
    pushad		
	mov			ebp, esp
	mov			edx, [ebp + 40]		; intro 0
	call		WriteString
	call		CrlF
	mov			edx, [ebp + 36]		; intro 1
	call		WriteString
	call		CrlF
	popad
	ret			8
intro			ENDP
	 
getUserData		PROC
; This procedure prompts user to enter an integer in [10..200].
; receives: receives outOfRange (ref) userNum (ref) and getNumString (ref)
; returns: userNum_1 with user input
; preconditions: userNum_1 in range [100..999], edx initialized
; registers changed: edx
;-------------------------------------------------------------------------
	pushad		
	mov			ebp, esp
	mov			edi, [ebp + 36]

GetNum:
	mov			edx,[ebp + 40]	; setting getNumString to edx
	call		WriteString		; print out string
	call		ReadDec			; get input from user
	cmp			eax,MAX			; compare number to maximum
	jg			Validate		; jump if greater than max
	cmp			eax, MIN		; compare to minimum
	jl			Validate		; jump if less than min
	jmp			goodNum			; jump if in range

Validate:
	mov			edx, [ebp + 44]	; set validate message
	call		WriteString		; print validate
	call		Crlf
	jmp			GetNum			; jump back to getnum to get number

goodNum:
	mov			[edi], eax		; store value in edi
	popad
	ret			12

getUserData		ENDP 

fillArray		PROC
; This procedure fills the array with the called set of random numbers
; between the set low and high range
; receives: array(by reference), request (by value)
; returns: array of random numbers
; preconditions: userNum_1 in range [100..999], edx initialized
; registers changed: eax, ecx, edi
;-------------------------------------------------------------------------
	pushad	
	mov			ebp, esp
	mov			ecx, [ebp + 36]		; get array size
	mov			edi, [ebp + 40]		; set edi to the array
L1:
	mov			eax, HI				; set high to eax
	sub			eax, LO				; subtract from high with low
	inc			eax					; increment eax by 1
	call		RandomRange			; gets a number in range
	add			eax, LO				; adds 100 to get new number
	mov			[edi], eax			; list[0] to eax
	add			edi, 4				; increment to list[1]
	loop		L1
	jmp			finishFill

finishFill:
	popad
	ret			8

fillArray		ENDP 

sortList		PROC
; This procedure sorts the array of random numbers
; receives: array(by reference), request (by value)
; returns: array of random numbers that are sorted
; preconditions: received an array of random integers
; registers changed: eax, ecx, edi, ebx
;-------------------------------------------------------------------------

	pushad		
	mov			ebp, esp
	mov			edi, [ebp + 40]			; array 
	mov			ecx, [ebp + 36]			; counter used in for loop
	mov			ebx, 0					; ebx will be i so make i = 0
	dec			ecx						; make result - 1 as listed in assignment sheet

firstForLoop:
	mov			eax, ebx				; make i = k statement
	mov			edx, eax				; move eax to edx to make j for next for loop
	inc			edx						; set j = k +1
	push		ecx						; save counter for ecx
	mov			ecx, [ebp + 36]			; get old request number

secondForLoop:
	mov			esi, [edi + edx * 4]	; get current number and set to esi array[j] >array[i]
	cmp			esi, [edi + eax * 4]	; compare next number with esi
	jle			nextNum					; jump if less or equal
	mov			eax, edx				; set edx to eax
	
nextNum:
	inc			edx						; increment to get next number
	cmp			edx, [ebp +36]			; check if edx goes out of bounds
	jge			exchange				; swap if equal
	loop		secondForLoop			; loop to compare next number

exchange: 
	lea			esi, [edi + ebx * 4]	; set the address of the value to esi
	push		esi						; push address to stack
	lea			esi, [edi + eax * 4]	; set address of number being used to swap to esi
	push		esi						; push address to stack
	call		swap					; swap numbers
	pop			ecx						; bring back first loops count
	inc			ebx						; increment i
	loop		firstForLoop			; repeat
	popad
	ret			8

sortList		ENDP

swap			PROC
; This procedure swaps the numbers with each other
; returns: nothing. Numbers are just swapped
; preconditions: must get numbers
; registers changed: eax, ecx, edx, ebx
;-------------------------------------------------------------------------
	pushad
	mov			ebp, esp
	mov			esi, [esp + 40]			; gets position currently on
	mov			eax, [esi]				; sets eax to value esi is pointing to
	mov			edi, [esp + 36]			; sets next high numbers position to edi
	mov			ebx, [edi]				; set ebx to value edi is pointing to
	mov			[esi], ebx				; set esi to point to ebx
	mov			[edi], eax				; set edi to point to eax
	popad
	ret			8

swap			ENDP

displayMedian	PROC
; This procedure finds and displays the median of the array
; receives: array(by reference), request (by value)
; returns: median of the array
; preconditions: receives a valid sorted array
; registers changed: eax, ecx, edi, ebx
;-------------------------------------------------------------------------
	pushad		
	mov			ebp, esp
	mov			esi, [ebp + 44]		; move array to edi
	mov			edx, [ebp + 36]		; median message
	call		WriteString
	call		CrlF
	
	mov			edx, 0				; intialize edx for divide
	mov			eax, [ebp + 40]		; move request number to eax to have it divided
	mov			ebx, 2				; divide request number by 2
	div			ebx					; divide
	cmp			edx, 0				; compare remainder to 0
	je			evenNum				; if equal it means even number
	mov			ebx, 4				; multiply by 4 cause dword 4 bytes
	mul			ebx					; getting location address of middle number
	add			esi, eax			; add eax to esi to get location of middle number
	mov			eax, [esi]			; odd number so display middle number
	call		WriteDec			; print number
	call		CrlF				; new line
	jmp			finishMedian		; exit 

evenNum:
	mov			ebx, 4				; multiply by 4 to get right middle
	mul			ebx					; get number
	add			esi, eax			; add to esi to get numbers location in memory
	mov			eax, [esi]			; move number to eax 
	sub			esi, 4				; subtract 4 from esi to get left middle numbers address
	add			eax, [esi]			; add right middle and left middle together
	mov			ebx, 2				; divide them in half to get average
	div			ebx					; divide
	call		WriteDec			; print average
	call		CrlF

finishMedian:
	popad
	call		CrlF
	ret			12
displayMedian	ENDP

displayList		PROC
; This procedure displays the array sorted or not sorted
; receives: array(by reference), request (by value), title(by reference)
; returns: array of random numbers
; preconditions: receives array
; registers changed: eax, ecx, edi, ebx
;-------------------------------------------------------------------------
	pushad		
	mov			ebp,esp
	mov			edx, [ebp + 36]		; title
	call		WriteString
	call		CrlF
	mov			ecx, [ebp + 40]		; request 
	mov			esi, [ebp + 44]		; array
	mov			ebx, 0

L1:
	inc			ebx					; counter for number of prints
	mov			eax, [esi]			; move number in array to eax 
	call		WriteDec			; print the number
	add			esi, 4				; add 4 to esi to get next numbers address location
	cmp			ebx, 10				; check if 10 numbers printed
	jge			newLine				; if greater than or equal jump to newLine
	mov			al, TAB				; print space
	call		WriteChar			
	loop		L1					; loop
	jmp			finishDisplay		; if ecx = 0 then exit

newLine:
	call		CrlF
	mov			ebx, 0				; reset ebx to 0
	loop		L1					; loop until ecx = 0

finishDisplay:
	call		CrlF
	popad
	call		CrlF
	ret			12

displayList		ENDP


END main