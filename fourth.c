#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void make_magic_square(long n, long** matrix);
bool does_value_exist(long i, long j, long n, long** matrix);

int main(int argc, char* argv[]) //check this
{
    
    long n = atol(argv[1]);
    //printf("hi\n");

    if((n % 2)==0 || n<=0)
    {
        printf("error\n");
      
        EXIT_SUCCESS;
    }
    else
    {
        //printf("hi");
        long** matrix = malloc(n*(sizeof(long*))); //make 2d array
        for(long i=0; i<n; i++)
        {
            matrix[i] = malloc(n*(sizeof(long)));
        }

        //printf("hi2\n");
        make_magic_square(n, matrix);
        
        
    }
   

   return EXIT_SUCCESS;
}

void make_magic_square(long n, long** matrix)
{
    //printf("hello\n");
       
    for(long i=0; i<n; i++)
    {
        for(long j=0; j<n; j++)
        {
            matrix[i][j] =0;
            // array[i][j] = 0; //all tiles are 0
        }
    }
    // printf("hello1\n");

    long tileIndex = n*n;

    //get to center of first row
    long i = 0;
    long j = n/2;
    long count=1;
    matrix[i][j] = count;
    //printf("tileIndex: %d\n", n);

 
    while(count<tileIndex) //if we are not past the end of the matrix
    {
         //printf("hello2\n");
         count++; //increase count
        bool value_exists = does_value_exist(i, j, n, matrix);
        if(i-1<0 && j+1>n-1 && !value_exists) 
        {
            //printf("hello3\n");
            i=n-1;
            j=0;

            matrix[i][j]=count;

        }
        else if(i-1<0 && !value_exists)//if the value up is out of bounds
        {
           // printf("hello4\n");
            i=n-1;
            j++;
            matrix[i][j]=count;
        }
        else if(j+1>n-1 && !value_exists)// value to the right is out of bounds
        {
            //printf("hello5\n");
            i--;
            j=0;
            matrix[i][j]=count;
        }
        else if(value_exists) //if the value up and right is filled
        {
            //printf("hello6\n");
            i++;
            //printf("i: %d\t j: %d\t count: %d\n", i, j, count);
            matrix[i][j]=count; //go to next row and fill
        }
        else
        {
           // printf("hello7\n");
            i--;
            j++;
            matrix[i][j]=count; //go up and right and fill
        }
        
    

        
    }
    
    for(long i=0; i<n; i++)
    {
        
        for(long j=0; j<n; j++)
        {
             printf("%ld\t", matrix[i][j]);
        }
        printf("\n");
    }

    for(long i=0; i<n; i++)
    {
        free(matrix[i]);
    }
    free(matrix);



}

bool does_value_exist(long i, long j, long n, long** matrix)
{
    long a=i;
    long b=j;
    if(a-1<0 && b+1>n-1) //wrap up and right
        {
            
            a=n-1;
            b=0;

           return matrix[a][b]!=0;

        }
        else if(a-1<0) //if the value up is out of bounds
        {
            
            a=n-1;
            b++;
            return matrix[a][b]!=0;
        }
        else if(b+1>n-1)// value to the right is out of bounds
        {
            
            a--;
            b=0;
            return matrix[a][b]!=0;
        }
        else
        {
            
            a--;
            b++;
           return matrix[a][b]!=0;
        }

    // if(array[i-1][j+1]!=0) //if the value up and right is filled
    //     {
    //         printf("hello6\n");
    //         i++;
    //         array[i][j]=count; //go to next row and fill
    //     }

}