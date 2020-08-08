#include <iostream>
#include <vector>
using namespace std;

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