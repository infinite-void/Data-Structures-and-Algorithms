//Author: Niranjan008
#include <iostream>
#include <string>
using namespace std;

int main() {
    
    string main_string, pattern;
    
    cout << "Enter the main string :";
    cin >> main_string;
    
    cout << "Enter the pattern :";
    cin >> pattern;
    
    int main_length = main_string.size();
    int pattern_length = pattern.size();
    
/* The variable i always denotes the starting index of a substring
 * when when search for a pattern over a string.
 * 
 * The variable j is used to traverse over the maximum length of the 
 * substring pattern upto which the pattern is present in the 
 * substring that starts with the corresponding i.
 * 
 * If j == pattern_length the substring itself resembles the pattern
 * and the pattern is present starting at index i
 */
    for(int i = 0; i <= main_length - pattern_length; i++) {
        int j;
        for(j = 0; j < pattern_length; j++)
            if(main_string[i+j]!=pattern[j])
                break;
        if(j == pattern_length)
            cout << "Match Found at index " << i << endl;
    }
    return 0;
}
