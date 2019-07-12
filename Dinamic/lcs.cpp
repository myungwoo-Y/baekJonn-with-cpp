#include <iostream>
#include <algorithm>
#include "ostream"

using namespace std;


int lsc() {
    ios_base::sync_with_stdio(false);
    string a;
    string b;
    string result = "";
    cin >> a >> b;
    auto dp = new int[1005][1005];
    int lengthA = a.length();
    int lengthB = b.length();

    for(int i = 1; i < lengthB + 1; i++){
        for(int j = 1; j < lengthA + 1; j++){
            dp[i][j] = std::max({dp[i-1][j], dp[i][j-1], dp[i-1][j-1] + (a[j-1] == b[i-1])});
        }
    }

//    for(int i = 1; i < lengthB + 1; i++) {
//        for (int j = 1; j < lengthA + 1; j++) {
//            cout << dp[i][j] << " ";
//        }
//        cout << "\n";
//    }

    int count = dp[lengthB][lengthA];
    string insertStr;

    int i = lengthB;
    for(int j = lengthA; j > 0; j--){

        while(dp[i-1][j] == count){
            i--;
        };

        while(dp[i][j-1] == count){
            j--;
        };
        insertStr = b[i-1];
        result.insert(0, insertStr);

        count--;

        if(count == 0){
            break;
        }
        i--;
    }

    if(count == 1){
        insertStr =  a.at(0);
        result.insert(0, insertStr);
    }
    cout << dp[lengthB][lengthA] << "\n";

    cout << result;
    return 0;
}