/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <bits/stdc++.h> 
using namespace std;

int main()
{
    int n, temp;
    vector<int> loopValue;
    cin >> n;
    
 for (int i = 0; i < n; i++) {
     cin >> temp;
     loopValue.push_back(temp);
 }
 
    sort(loopValue.begin(), loopValue.end());
 
    for (int i = 0; i < n; i++) {
     loopValue[i] = loopValue[i] * (n - i);
    }
 
    
    cout << *max_element(loopValue.begin(), loopValue.end());
        
    
    return 0;
}



