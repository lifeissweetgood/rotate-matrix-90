#include <stdio.h>
#include <stdlib.h>

/**
 * Small program to rotate a matrix to 90 degrees to the right in place.
 *
 * Ex:
 *
 * Original:
 * A B C D
 * E F G H
 * I J K L
 * M N O P
 *
 * Rotated 90 degrees:
 * M I E A
 * N J F B
 * O K G C
 * P L H D
 *
 */

void print_matrix(char matrix[4][4])
{
    int i = 0, j = 0;

    for(i=0; i < 4; i++)
    {
        for(j=0; j < 4; j++)
            printf("%c\t", matrix[i][j]);
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int i, j, count = 0;
    char tmp;
    char matrix[4][4];

    char letters[16] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                        'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'};

    // Pre-populate matrix
    for(i=0; i < 4; i++)
    {
        for(j=0;j < 4; j++)
        {
            matrix[i][j] = letters[count];
            count++;
        }
    }

    printf("Original:\n");
    print_matrix(matrix);

    // Reflect matrix down the middle
    for(i=0; i < 4; i++)
    {
        // Switch outer
        tmp = matrix[i][0];
        matrix[i][0] = matrix[i][3];
        matrix[i][3] = tmp;

        // Switch inner
        tmp = matrix[i][1];
        matrix[i][1] = matrix[i][2];
        matrix[i][2] = tmp;
    }
    
    printf("Reflected down the middle y axis:\n");
    print_matrix(matrix);

    // Reflect over right diagonal
    for(i=0; i < 4; i++)
    {
        for(j=3; j >= 0; j--)
        {
            if( i == 0 && j== 2)
            {
                tmp = matrix[1][3];
                matrix[1][3] = matrix[i][j];
                matrix[i][j] = tmp;
            }
            else if( i == 0 && j == 1)
            {
                tmp = matrix[2][3];
                matrix[2][3] = matrix[i][j];
                matrix[i][j] = tmp;
            }
            else if( i == 0 && j == 0)
            {
                tmp = matrix[3][3];
                matrix[3][3] = matrix[i][j];
                matrix[i][j] = tmp;
            }
            else if( i == 1 && j == 1)
            {
                tmp = matrix[2][2];
                matrix[2][2] = matrix[i][j];
                matrix[i][j] = tmp;
            }
            else if( i == 1 && j == 0)
            {
                tmp = matrix[3][2];
                matrix[3][2] = matrix[i][j];
                matrix[i][j] = tmp;
            }
            else if( i == 2 && j == 0)
            {
                tmp = matrix[3][1];
                matrix[3][1] = matrix[i][j];
                matrix[i][j] = tmp;
            }
            else
                continue;
        }
    }
    printf("Reflected over the right diagonal:\n");
    print_matrix(matrix);

    return;
}

