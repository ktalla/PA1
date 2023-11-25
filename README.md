# Programming Assignment 1 in C
There are 5 files, each file is a different program.

## First.c : Prime Numbers
Write a program that will read an array from a file and print if the numbers in the file are right truncatable primes. A right truncatable prime is a prime number, where if you truncate any numbers from the right, the resulting number is still prime. For example, 3797 is a truncatable prime number number because 3797, 379, 37, and 3 are all primes.

### Input-Output format: 
Your program will take the file name as input. The first line in the file provides the total number of values in the array. The subsequent lines will contain an integer value. For example a sample input file “file1.txt” is:
3 <br>
397<br>
73<br>
47<br>

The output will contain the same number of lines as the number of lines in the input file. Each line
will either say yes if the corresponding integer is a truncatable prime or no if the corresponding
integer is not a truncatable prime.

## Second.c : Ordered Linked List
Implement a linked list that maintains a list of integers in sorted order.
For example, if a list already contains 2, 5 and 8, then 1 will be inserted at the start of the list, 3 will be inserted between 2 and 5 and 10 will be inserted at the end.

### Input-Output format: 
This program takes a file name as an argument from the command line. The file
contains successive lines of input. Each line contains a string, either INSERT or DELETE, followed by a space and then an integer. For each of the lines that starts with INSERT, your program should insert that number in the linked list in sorted order if it is not already there. Your program should not insert any duplicate values. If the line starts with a DELETE, your program should delete the value if it is present in the linked list. Your program should silently ignore the line if the requested value is not present in the linked list. After every INSERT and DELETE, your program should print the content of the linked list. The values should be printed in a single line separated by a single space. There should be no leading or trailing white spaces in each line of the output. You should print EMPTY if the linked list is empty.

At the end of the execution, your program should have printed the content of the linked list after each INSERT or DELETE operation. Each time the content is printed, the values should be on a single line separated by a single space. There should be no leading or trailing white spaces in each line of the output.You should print EMPTY if the linked list is empty. Your program should print “error” (and nothing else) if the file does not exist. You can assume that there will be at least one INSERT or DELETE in each file.


## third.c : Stack and Queue
Implement a linked list that supports both stack and queue. The idea is to have a single linked list that supports three operations:
• ENQUEUE: Queues a value at the end of the linked list
• PUSH: Pushes a value at the beginning of the linked list
• POP: Pops and removes the value at the beginning of the linked list.

### Input-Output format: 
This program takes a file name as an argument from the command line. The file contains successive lines of input. Each line contains a string, either ENQUEUE or PUSH followed by a space and then an integer OR just the word POP without anything following it. For each line that starts with ENQUEUE, your program should insert that number at the end of the linked list (like a queue). If the line starts with a PUSH, your program should insert that number at the beginning of the linked list (like a stack). If the line says POP, your program should pop and delete the first value at the beginning of the linked list. After every ENQUEUE, PUSH, and POP, your program should print the content of the linked list. The values should be printed in a single line separated by a single space. There should be no leading or trailing white spaces in each line of the output. You should print EMPTY if the linked list is empty. Output format: At the end of the execution, your program should have printed the content of the linked list after each ENQUEUE, PUSH, or POP operation. Each time the content is printed, the values should be on a single line separated by a single space. There should be no leading or trailing white spaces in each line of the output.You should print EMPTY if the linked list is empty. Your program should print “error” (and nothing else) if the file does not exist. You can assume that there will be at least one ENQUEUE, PUSH, or POP operation in each file.

## fourth.c : Magic Square
A magic square is an arrangement of the numbers from 1 to n2 in an (n x n) matrix, with each number occurring exactly once, and such that the sum of the entries of any row, any column, or any main diagonal is the same.
An example of a Magic Square is as such: <br>
8 1 6 <br>
3 5 7<br>
4 9 2<br>
In this case, the sum of all entries in a given row, column or main diagonal is equal to 15. In this part, you will create a program that automatically creates a magic square for an odd-ordered matrix, i.e. n × n matrix where n is an odd number. There is a famous method for creating magic squares for matrix of odd order: https://en.wikipedia.org/wiki/Magic_square#A_method_for_constructing_a_magic_square_of_odd_order

### Method: 
This method is applicable for all odd-ordered matrix. We illustrate the method by creating a 3 × 3 magic square.
(1) The first step starts with a number 1 at the center column of the first row:
(2) After that, we fill incrementally larger number to the cell diagonally up and right, one at a time. If the new cell goes outside of the matrix, we wrap around to the other side. For example, since there is no cell above and to the right of our 1, we fill the bottom right cell with a 2. It can also be considered that the sides of the matrices are connected to the opposite side when traversing the cells.
(3), If the cell diagonally up and right of the current cell is already filled with a number, then we move one cell vertically down and fill that cell with the next number
It is important to remember that step (2) takes precedence over step (3)
### Input/Output format:
Your program will accept a positive number n as a command line argument. You can assume that we will give a positive number n as the one and only command line argument, but n may be an even number or an odd number. If n is an odd number, then your program should output the magic square created using the above method. The matrix should be produced with each rows separated by a line and each cell in a row separated by a tab. If n is an even number, then your program should print “error” (and nothing else).

Example Execution:
Here is an example of the input and the expected result:
$ ./fourth 3
8 1 6 <br>
3 5 7<br>
4 9 2<br>

$ ./fourth 4
error

## fifth.c : Matrix Determinant
In linear algebra, the determinant is a value that can be computed with a square matrix. The determinant describes some properties about the square matrix. Determinants are used for solving linear equations, computing inverses, etc, and is an important concept in linear algebra. In the fifth part of the assignment, you will write a program that computes the determinant of any n × n matrix. You will have to carefully manage malloc and free instructions to successfully compute the determinants.

### Input-Output format:
Your program should accept a file as command line input. The format of a sample file test3.txt is shown below:
3<br>
2 7 6<br>
9 5 1<br>
4 3 8<br>
The first number (3) corresponds to the size of the square matrix (n). The dimensions of the matrix will be n x n. You can assume that n will not be greater than 20. The rest of the file contains the content of the matrix. Each line contains a row of the matrix, where each element is separated by a tab. You can assume that there will be no malformed input and the matrices will always contain valid integers. Your program should output the determinant of the n × n matrix provided by the file.


