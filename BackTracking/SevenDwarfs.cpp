#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#define endl '\n'
#define DWARFS_SIZE 9
#define CORRECT_SIZE 7

using namespace std;

vector<int> dwarfs(9);
vector<bool> isVisit(9);
bool isFind {false};

// 방문한 난쟁이 출력
void print(){
    for (int i = 0; i < DWARFS_SIZE; ++i) {
        if(isVisit[i]){
            cout << dwarfs[i] << endl;
        }
    }
}

void solve(int index, int sum, int count){
    if(isFind) return;
    // 알맞는 케이스 찾았을 경우 출력
    if(sum == 100 && count == CORRECT_SIZE){
        print();
        isFind = true;
        return;
        // 범위 넘어가면 중단
    }else if(index == DWARFS_SIZE){
        return;
    }else if(count < CORRECT_SIZE){
        // index번째 난쟁이 방문
        if(!isVisit[index]){
            isVisit[index] = true;
            solve(index+1, sum+dwarfs[index], count+1);
            isVisit[index] = false;
        }
        // index번째 난쟁이 방문하지 않음
        isVisit[index] = false;
        solve(index+1, sum, count);
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 난쟁이 입력받음
    for (int i = 0; i < DWARFS_SIZE; ++i) {
        cin >> dwarfs[i];
    }
    // 오름차순으로 나오기 위하여 정렬
    sort(dwarfs.begin(), dwarfs.end());
    solve(0, 0, 0);
    return 0;
}