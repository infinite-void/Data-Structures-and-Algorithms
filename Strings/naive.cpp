#include <bits/stdc++.h>

using namespace std;

int main()
{
    string main_string,pattern;
    cout<<"Enter the main string";
    cin>>main_string;
    cout<<"Enter the pattern";
    cin>>pattern;
    int main_length = main_string.size();
    int pattern_length = pattern.size();
    for(int i=0;i<=main_length-pattern_length;i++){
        int j;
        for(j=0;j<pattern_length;j++)
            if(main_string[i+j]!=pattern[j])
                break;
        if(j == pattern_length)
            cout<<"Match Found at index "<<i<<endl;
    }
    return 0;
}