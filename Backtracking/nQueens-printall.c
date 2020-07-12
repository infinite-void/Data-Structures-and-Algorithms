// author: infinite-void

// This program prints out all the
// feasible solutions to a problem of placing n Queens
// in a n * n chess board without any conflict.

#include <stdio.h>
#include <stdlib.h>

static long long count = 0;

void nQueens(unsigned, int, int *);
short checkPlacement(int, int, int *);

int main()  {
    unsigned n, flag = 0, i;

    scanf("%d", &n);
    int *result = (int *)calloc(n, sizeof(int));

    nQueens(n, 0, result);
    fprintf(stdout, "Number of possible solutions = %d for given n = %d\n", count, n);
    return 0;
}

/*  This function tries to find all possible solutions 
 *  by checking the possibility of placing a queen in the
 *  `currentIndex` column by trying out placing a queen in 
 *  all the rows ranging from 0 to n - 1. For example, this 
 *  prints 92 possible solutions for `n` = 8(Though there 
 *  are only 12 fundamental solutions, all other solutions are 
 *  reflections and rotations for these 12 solutions).
 */
void nQueens(unsigned n, int currentIndex, int *result)  {
    unsigned i;
    if (currentIndex == n) {
        count +=  1;
        for (i = 0; i < n; i++)
            fprintf(stdout, "%d ", result[i]);
        fprintf(stdout, "\n");
        return;
    }
        
    for (i = 0; i < n; i++)  {
        if (checkPlacement(currentIndex, i, result))  {
            result[currentIndex] = i;
            nQueens(n, currentIndex + 1, result);
        }
    }
}

/*  This function checks for any conflict
 *  between a queen that has been placed in
 *  previous columns and the queen that is
 *  to be placed in `currentIndex` row at 
 *  `position` column
*/
short checkPlacement(int currentIndex, int position, int *result)  {
    unsigned i;
    for (i = 0; i < currentIndex; i++)  {
        if (result[i] == position || abs(currentIndex - i) == abs(position - result[i]))
            return 0;
    }
    return 1;
}