#include <iostream>
#include<vector>
#include<string>
#include<algorithm>

#define endl '\n'
using namespace std;


int getGcd(int a, int b){
    int r;
    while(b != 0){
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, a, b, gcd;

    cin >> t;

    while(t > 0){
        cin >> a >> b;
        gcd = getGcd(a, b);
        cout << a*b / gcd << " " << gcd << endl;
        t--;
    }




    return 0;
}
