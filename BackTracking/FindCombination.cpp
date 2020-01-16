#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int size;
void choseNumber(bool choosen[9], int n, string buf){
    if(n == 0){
        cout << buf << "\n";
        return;
    }
    string temp;
    for (int i = 1; i <= size; ++i) {
        if(!choosen[i]){
            temp = buf;
            buf += to_string(i) + " ";
            choosen[i] = true;
            choseNumber(choosen, n-1, buf);
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

    choseNumber(choosen, m, "");

    return 0;
}