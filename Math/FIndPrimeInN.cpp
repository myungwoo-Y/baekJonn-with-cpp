#include<cstdio>
#include<algorithm>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int divide= 2; divide <= n; ++divide) {
        if(n % divide == 0){
            cout << divide <<'\n';
            n /= divide;
            divide--;
        }
    }
    return 0;
}









