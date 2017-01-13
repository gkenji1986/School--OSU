#!/usr/bin/python

# Assignment 5
# CS344-400
# By: Grant Nakashima
# Due Date: 03/07/2016
#
# Description:
# Creates 3 files in the same directory as the script
# Each of these 3 files will contain exactly 10 random characters from the lower-case alphabet
# Prints out on screen the contents of the 3 files it is creating.
# Print out two random integers (whose range is from 1 to 42), and print out the product of the two numbers.

import random
import string
from random import randint

#reference: http://learnpythonthehardway.org/book/ex5.html
#reference: http://stackoverflow.com/questions/2967194/open-in-python-does-not-create-a-file-if-it-doesnt-exist
#reference: http://stackoverflow.com/questions/2823316/generate-a-random-letter-in-python
#reference: http://stackoverflow.com/questions/12377473/python-write-versus-writelines-and-concatenated-strings
#reference: http://stackoverflow.com/questions/112970/python-when-to-use-file-vs-open
#reference: http://stackoverflow.com/questions/8287167/python-generate-random-number-between-x-and-y-which-is-a-multiple-of-5

print ("Making file_1 file_2 file_3.")
file_open1 = open ("file_1", 'w')
file_open2 = open ("file_2", 'w')
file_open3 = open ("file_3", 'w')
print ("file_1 file_2 file_3. created")

for x in range (0, 10):
    file_open1.writelines(random.choice(string.ascii_lowercase))
    file_open2.writelines(random.choice(string.ascii_lowercase))
    file_open3.writelines(random.choice(string.ascii_lowercase))

file_open1.close()
file_open2.close()
file_open3.close()

print ("Wrote content files")

file_1 = open("file_1")
file_2 = open("file_2")
file_3 = open("file_3")

print ("The files of file_1 file_2 and file_3 will get printed.")
print ("File_1:")
print (file_1.read())
print ("File_2:")
print (file_2.read())
print ("File_3:")
print (file_3.read())

file_1.close()
file_2.close()
file_3.close()

#print two random numbers
random_number1 = randint(1,42)
random_number2 = randint(1,42)
rand_num_product= random_number1 * random_number2

print ("Random number 1 is %d:" % random_number1)
print ("Random number 1 is %d:" % random_number2)
print ("Product of the numbers is %d:" % rand_num_product)