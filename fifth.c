#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

long find_det(long numOfLines, long** matrix);
long det_of_matrix_one(long** matrix);
long det_of_matrix_two(long** matrix);
long** make_submatrix(long n, long** matrix, long columnCurrent);
long det_of_matrix_n(long n, long** matrix);


int main(int argc, char* argv[argc+1]) //check this
{
FILE*fp = fopen(argv[1], "r");
long n;
fscanf(fp, "%ld\n", &n);
if(n<=0)
{
    printf("error\n");
    return EXIT_SUCCESS;
}

long value;
long** matrix = malloc(n*(sizeof(long*))); //make 2d array
    for(long i=0; i<n; i++)
    {
        matrix[i] = malloc(n*(sizeof(long)));
    }



for(long i=0; i<n; i++)
{
    for(long j=0; j<n; j++)
    {
        if(j==n-1)
        {
            fscanf(fp, "%ld\n", &value);
        }
        else
        {
            fscanf(fp, "%ld\t", &value);
        }

        matrix[i][j]=value;
    }
    
}

printf("%ld\n", find_det(n, matrix));
for(long i=0; i<n; i++)
    {
        free(matrix[i]);
    }
    free(matrix);


     fclose(fp);
    EXIT_SUCCESS;

}

long find_det(long n, long** matrix)
{
    if(n==1)
    return det_of_matrix_one(matrix);
    else if (n==2)
    return det_of_matrix_two(matrix);
    else
    { 
        return det_of_matrix_n(n, matrix);
    }

}

long det_of_matrix_one(long** matrix)
{
   return matrix[0][0];
}

long det_of_matrix_two(long** matrix)
{
    return ((matrix[0][0]*matrix[1][1]) - (matrix[0][1]*matrix[1][0]));

}

long** make_submatrix(long n, long** matrix, long columnCurrent)
{
    long** submatrix;
    submatrix=malloc((n-1)*sizeof(long*)); //make submatrix
    for(long i=0; i<n-1; i++)
    {
        submatrix[i] = malloc((n-1)*sizeof(long));
    }

    
     for(long row=1; row<n; row++)
     {

        for(long col=0; col<n; col++)
        {
            if(col!=columnCurrent)
            {
             if(col<columnCurrent)
            submatrix[row-1][col] = matrix[row][col];

             else
             submatrix[row-1][col-1] = matrix[row][col]; //submatrix equals matrix with offset
            }
        }

     }

     return submatrix;
        
    

}

long det_of_matrix_n(long n, long** matrix)
{
    long det=0;
    long sign;
    for(long currentColumn=0; currentColumn<n; currentColumn++)
    {
        if(currentColumn%2==0)
        {
            sign = 1;
        }
        else
        {
            sign= -1;
        }
        long** submatrix = make_submatrix(n, matrix, currentColumn);
        long factor = matrix[0][currentColumn];
        det = det + sign*factor*find_det(n-1, submatrix);

        for(long i=0; i<n-1; i++)
        {
            free(submatrix[i]);
        }
        free(submatrix);
    }
    
    return det;

}
