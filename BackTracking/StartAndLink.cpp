#include <iostream>
#include <vector>

using namespace std;

int Size;
int Differ = {INT32_MAX};
void dfs(vector<bool> choosen, vector<vector<int>> table, int start, int count){
    if(count == Size/2){
        int choosenSum {0}, notChoosenSum{0};

        for (int base = 0; base < Size; ++base) {
            for (int other = 0; other < Size; ++other) {
                if(choosen[other] && choosen[base]){
                    choosenSum += table[base][other];
                }else if(!choosen[other] && !choosen[base]){
                    notChoosenSum += table[base][other];
                }
            }
        }
        Differ = min(Differ, abs(choosenSum - notChoosenSum));
    }else if(start < Size){
        for (int i = start; i < Size; ++i) {
            choosen[i] = true;
            dfs(choosen, table, i+1, count+1);
            choosen[i] = false;
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> Size;

    vector<vector<int>> table(Size);

    vector<bool> choosen(Size);

    for (int i = 0; i < Size; ++i) {
        table[i] = vector<int>(Size);
    }

    for (int i = 0; i < Size; ++i) {
        for (int j = 0; j < Size; ++j) {
            cin >> table[i][j];
        }
    }

    dfs(choosen, table, 0, 0);

    cout << Differ;


    return 0;
}