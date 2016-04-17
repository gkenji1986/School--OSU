Compile Program
Run "make" in the project root. You can optionally check the correctness or runtimes by removing the "//"

To Run Program (in vim: input in the follow order *minus the text in the ())
1) make mss
2) mss (the program will create the text file with the results. You will have to go manually open the text file to see the results)

The program expects MSS_Problems.txt to be in the same directory as the executable. It will gracefully exit if this file is not found.

Program Output
The program will output a MSS_Results.txt file that will contain output for each algorithm as defined in the spec.
    This is the main application source file.
*If the comment "//" are removed in the mss.cpp file, it will print the array and/or times. 
