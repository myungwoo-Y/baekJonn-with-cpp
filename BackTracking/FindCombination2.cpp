//https://www.acmicpc.net/problem/15650
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int size;
void choseNumber(bool choosen[9], int n, string buf, int start){
    if(n == 0){
        cout << buf << "\n";
        return;
    }
    string temp;
    for (int i = start; i <= size; ++i) {
        if(!choosen[i]){
            temp = buf;
            buf += to_string(i) + " ";
            choosen[i] = true;
            choseNumber(choosen, n-1, buf, i);
            choosen[i] = false;
            buf = temp;
        }
    }
}

int main()	{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    size = n;

    bool choosen[9];

    fill_n(choosen, 9 , false);

    choseNumber(choosen, m, "", 1);

    return 0;
}