#include<cstdio>
#include<algorithm>
#include <cstring>
#include <cmath>
#include <climits>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include <string>
#define MAX 10
using namespace std;

int Arr[MAX];
int Select[MAX];
int Length = 0;
int NumOfSelect = 0;
bool IsBroken[10];
int Value;
int Min = INT_MAX;
// 중복 순열 계산
void DFS(int Cnt)
{
    if (Cnt == NumOfSelect)
    {
        int v = Select[0];
        for (int i = 1; i < NumOfSelect; i++)
        {
            v = Select[i] + (v * 10);
        }
        Min = min(Min, (abs(Value - v) + NumOfSelect));
        return;
    }
    for (int i = 0; i < Length; i++)
    {
        Select[Cnt] = Arr[i];
        DFS(Cnt + 1);
    }
}

int main() {
    int n, a;
    scanf("%d %d", &Value, &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        IsBroken[a] = true;
    }
    string vts = to_string(Value);
    // 파괴된 버튼은 수열 리스트에서 제거
    for (int j = 0; j < 10; ++j) {
        if(!IsBroken[j]){
            Arr[Length++] = j;
        }
    }
    // 몇개의 수를 고를지 정한다.
    NumOfSelect = vts.length();
    DFS(0);

    // 0개고르면 오류이기 때문에 체크
    if(vts.length()-1 > 0){
        NumOfSelect = vts.length()-1;
        DFS(0);
    }

    NumOfSelect = vts.length()+1;
    DFS(0);
    printf("%d", min(Min, abs(Value - 100)));
    return 0;
}



