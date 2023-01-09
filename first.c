#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

 bool truncatablePrime(long* numberPtr);
 bool isPrime(long n);


int main(int argc, char* argv[argc+1]) //check this
{
//printf("%s\n", argv[1]);
FILE *fp = fopen(argv[1], "r"); //open the file to read
long numOfLines; 
fscanf(fp, "%ld\n", &numOfLines); //read first int
//printf("num lines: %d\n", numOfLines);
long number;
for(long i=0; i<numOfLines; i++) //for every number
{
    //printf("hello\n");
    fscanf(fp,"%ld\n", &number); //read the number and store at address of number
    //printf("hello2\n");
    if (truncatablePrime(&number)) //if it is a truncatable prime
     printf("yes\n");
    else{ printf("no\n");}
    //printf("hello3\n");
}
fclose(fp);
return EXIT_SUCCESS;
}


bool truncatablePrime(long* numberPtr)
{
    while( *(numberPtr) > 0)
    {
        if (isPrime(*(numberPtr)))
        {
            *numberPtr= (*(numberPtr)) / 10; 
        }
        else return false;
    }
    return true;

}

bool isPrime(long n)
{
    // one or zero cannot be prime
    if (n <= 1)
        return false;
 
    // Check from 2 to square root of n
    for (long i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
 
    return true;
}
