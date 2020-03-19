//1105번 팔

#include <vector>
#include <iostream>
#include <algorithm>
#define LL long long int
using namespace std;

static string endLine = "\n";

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string a {""}, b {""};

    cin >> a >> b;

    int count {0};

    if(a.compare(b) == 0){
        for (int i = 0; i < a.length(); ++i) {
            if(a.at(i)=='8' && b.at(i)=='8'){
                count++;
            }
        }
        cout << count;
    }else if(a.length() == b.length()){
        for (int i = 0; i < a.length(); ++i) {
            if(a.at(i)==b.at(i)){
                if(a.at(i)=='8' && b.at(i)=='8'){
                    count++;
                }
            }else{
                break;
            }
        }
        cout << count;
    }else{
        cout << 0;
    }

    return 0;
}