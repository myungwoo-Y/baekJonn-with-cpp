#include <iostream>

using namespace std;

int N;
int colArr[15];
int result = 0;

bool isSafe(int newCol){
    for (int col = 0; col < newCol; ++col) {
        if((colArr[col] == colArr[newCol]) || (abs(colArr[col] - colArr[newCol]) == newCol - col)){
            return false;
        }
    }
    return true;
}


void N_Queen(int col){
    if(col == N){
        ++result;
    }else{
        for (int row = 0; row < N; ++row) {
            colArr[col] = row;
            if(isSafe(col)){
                N_Queen(col + 1);
            }
        }
    }
}

int main()
{
    cin>>N;
    N_Queen(0);
    cout<<result<<endl;
    return 0;
}