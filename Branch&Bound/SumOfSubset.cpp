//Author infinite-void
#include <iostream>
#include <vector>
using namespace std;

/*  The recusrsive function `bb_subsetSum` takes a starting input vector, the staring index at 0,
    and the expected sum. If expected sum is 0 it returns true as any input vector satisfies the
    property of possessing an empty subset. If the Index exceeds the limit of vector(with non-zero
    expected sum) or index goes below bound, it returns false.

    If the element at currentIndex is greater than expectedSum the element cannot form a part of 
    the subset. So it omits the element and recurses for the greater indices.

    Else 
    1. It recurses omitting the currentIndex 
    2. Including the current Index(expectedSum is reduced when currentIndex is included). We recurse 
        for the greate indices for a expectedSum that is less then current expectedSum by element 
        at currentIndex.
        We return true if either or both these cases are possible. 
 */
bool bb_subsetSum(const vector<int>& inputSet, int expectedSum, int currentIndex) {
    if(expectedSum == 0)
        return true;
    
    if(currentIndex == inputSet.size() || currentIndex < 0) 
        return false;
    
    if(inputSet[currentIndex] > expectedSum)
        return bb_subsetSum(inputSet, expectedSum, currentIndex + 1);

    return bb_subsetSum(inputSet, expectedSum, currentIndex + 1) ||
        bb_subsetSum(inputSet, expectedSum - inputSet[currentIndex], currentIndex + 1);
}
int main() {
    int n, expectedSum;
    cout << "Enter number of elements :";
    cin >> n;

    vector<int> inputSet(n ,0);
    cout << "Enter set: ";
    for(int i = 0; i < n; i++) 
        cin >> inputSet[i]; 

    cout << "Enter expected sum :";
    cin >> expectedSum;

    if(bb_subsetSum(inputSet, expectedSum, 0))
        cout << "such subset exists" << endl;
    else 
        cout << "such subset doesn't exist" << endl;
    return 0;
}