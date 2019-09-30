#include<cstdio>
#include<algorithm>
#include <vector>
#include <iostream>
#include <cmath>
#include <time.h>
#include <stack>
using namespace std;

struct Element{
    int index, value;
};

int arr[1000000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, value;
    cin >> n;

    fill_n(arr, n, -1);
    stack<Element> elementStack;
    for (int i = 0; i < n; ++i) {
        cin >> value;
        if(elementStack.empty()){
            elementStack.push(Element({i, value}));
        }else{
            if(elementStack.top().value < value){
                do{
                    arr[elementStack.top().index] = value;
                    elementStack.pop();
                }while(!elementStack.empty() &&elementStack.top().value < value);
                elementStack.push(Element({i, value}));
            }
            elementStack.push(Element({i, value}));
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }


    return 0;
}









