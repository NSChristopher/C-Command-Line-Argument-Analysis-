# C-Command-Line-Argument-Analysis-

Analysis c command line argumnets as well as how arrays, pointers, and memmory works in c.

## Description

This program alows the user to see visually how c stores command line arguments. command line argumnets in c are stored in an argv array thats passed into the main function when the program is commpiled and run in the terminal. additionally an argc veriable is also passed which holds the value of the number of elements in the array.

## How It Works

* user inputs arguments through the command line when running the program
* the code first prints "argv" along with the memory address it points (the first element in the array argv[0]) to and it's own memory address last.
  * both are printed in hexidecimal but a printHex function is created to print the value which is itself an address one byte at a time.
* next a for loop is used to do the same for each element in the argv array
* Lasty, in order to print the values of each argumnet from memory, the starting address from argv[0] is used and the ending address from argv[i] plus the size of string at argv[i] so that we include all the contents of the last array element.
  * importantly the addresses are 8 Byte alligned using the binarry & opporator and ~0x7 (not 0b111)
* the program then loops from start to end address in 8 byte increments and prints the contents of memory in 1 byte hex chuncks. if the 1 byte of hex is printible it prints the character otherwize it prints the ASCII code.
