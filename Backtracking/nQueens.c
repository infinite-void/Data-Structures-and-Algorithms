// author: infinite-void

// This program finds a single feasible solution to 
// place n queens in a n * n chess board without any
// conflict using the `Back Tracking` Approach
#include <stdio.h>
#include <stdlib.h>

short nQueens(unsigned, int, int*);
short checkPlacement(int, int, int*);


int main() {
    unsigned n, flag = 0, i;

    scanf("%d", &n);
    int* result = (int*) calloc(n, sizeof(int));

    flag = nQueens(n, 0, result);
    if(flag) 
        for(i = 0; i < n; i++) 
            fprintf(stdout, "%d ", result[i]);
    else
        fprintf(stdout, "Solution doesnot exist for given value of n");
    fprintf(stdout, "\n");
    return 0;
}

/*  This function checks for a suitable `i` row 
 *  to place the queen in the  `currentIndex` column
 *  Once it finds a suitable row to recurses to place
 *  the queen on the next column. When the function reaches 
 *  nth column the function returns completeley. The result 
 *  array is printed in the main() function.
 *  While going across from 0th to 7th column for `n` = 8 the first solution
 *  that the program comes across is `0 4 7 5 2 6 1 3` and 
 *  program terminates after this solution though there exists
 *  92 total solutions and 12 fundamental solutions for `n` = 8. 
 *  For all values of 
 *  `n` the program terminates after it finds the first
 *  feasible solution. 
 */
short nQueens(unsigned n, int currentIndex, int* result) {
    if(currentIndex == n) 
        return 1;
    unsigned i;
    for(i = 0; i < n; i++) {
        if(checkPlacement(currentIndex, i, result)) {
            result[currentIndex] = i;
            if(nQueens(n, currentIndex + 1, result))
                return 1;
        }
    }
    return 0;   
}

/*  This function checks for any conflict
 *  between a queen that has been placed in
 *  previous columns and the queen that is
 *  to be placed in `currentIndex` row at 
 *  `position` column
*/
short checkPlacement(int currentIndex, int position, int* result) {
    unsigned i;
    for(i = 0; i < currentIndex; i++) {
        if(result[i] == position || abs(currentIndex - i) == abs(position - result[i]))
            return 0;
    }
    return 1;
}