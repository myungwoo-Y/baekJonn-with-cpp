#include<cstdio>
#include<algorithm>
#include <vector>
#include <iostream>
#include <cmath>
#include <time.h>
#include <stack>
using namespace std;

struct Task{
    int taskInA, taskInB;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<Task> tasks;
    int aMax = 0, bMax = 0, taskInA, taskInB;


    for (int i = 0; i < n; ++i) {
        cin >> taskInA >> taskInB;
        tasks.push_back(Task({taskInA, taskInB}));
    }

    sort(tasks.begin(), tasks.end(),
         [](const Task & a, const Task & b){
             if(abs(a.taskInA - a.taskInB) == 0 && abs(b.taskInA - b.taskInB) == 0){
                    return a.taskInA >  b.taskInA;
             }else{
                 return abs(a.taskInA - a.taskInB) > abs(b.taskInA - b.taskInB);
             }});

    for (int i = 0; i < n; ++i) {
        if(aMax + tasks[i].taskInA < bMax + tasks[i].taskInB){
            aMax += tasks[i].taskInA;
        }else{
            bMax += tasks[i].taskInB;
        }
    }

    cout << max(aMax, bMax);

    return 0;
}









