//Author: infinite-void
#include <iostream>
#include <vector>
using namespace std;

/*  This is a simple example of dynamic programming where find nth member of 
    fibonacci series by the previous memebers. (bottom-up)
 */
void fill_up(vector<int>& fibonacci, const int end) {
    if(fibonacci.size() >= end) 
        return;
    
    while(fibonacci.size() < end) {
        fibonacci.push_back(*(fibonacci.end() - 1) + *(fibonacci.end() - 2));
    }
}

int main(int argc, char* argv[]) {
    int init_count;
    if(argc > 1) {
        init_count = atoi(argv[1]);
        if(init_count < 1) {
            cerr << "Invalid Input. Enter series position :";
            cin >> init_count;
        } 
    }
    else {
        cout << "Enter series position : ";
        cin >> init_count;
    }
    vector<int> fibonacci = {0, 1};
    fill_up(fibonacci, init_count);
    for(auto it = fibonacci.begin(); it != fibonacci.end(); ++it)
        cout << *it << " ";
    cout << endl;
    return 0;
}