// 알고스팟 와일드카드

#include <bits/stdc++.h>

#define VII vector<vector<int>>
#define VDD vector<vector<double>>
#define VCC vector<vector<char>>
#define VSS vector<vector<string>>
#define VI vector<int>
#define VB vector<bool>
#define VS vector<string>
#define VC vector<char>
#define VD vector<double>
#define SI string::iterator
#define loop(n) for(int x = 0; x < n; ++x)
#include <ctype.h>
using namespace std;

const string endL {"\n"};

int n {};

bool match(SI base, SI str, SI bEnd, SI sEnd){
    if(str == sEnd && base == bEnd){
        return true;
    }else if(str == sEnd || base == bEnd){
        if(base != bEnd && *base == '*'){
            return match(base+1, str, bEnd, sEnd);
        }
        return false;
    }
    if(*base == '*'){
        if(base+1 == bEnd) return true;
        string::iterator prev = str;
        while(str != sEnd){
            if(match(base+1, str, bEnd, sEnd)){
                return true;
            };
            str++;
        }
        return false;
    }else{
        if(*base == '?'){
            return match(base+1, str+1, bEnd, sEnd);
        }else if(*base == *str){
            return match(base+1, str+1, bEnd, sEnd);
        }else{
            return false;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
    #endif


    int testCase {};
    cin >> testCase;

    loop(testCase){
        string base;
        cin >> base >> n;

        VS strs(n);
        for (int i = 0; i < n; ++i) {
            cin >> strs[i];
        }
        VS list;
        for (auto str : strs) {
            if(match(base.begin(), str.begin(), base.end(), str.end())){
                list.push_back(str);
            }
        }
        sort(list.begin(), list.end());
        for(auto item : list){
            cout << item << endL;
        }
    }

    return 0;
}