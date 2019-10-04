#include<cstdio>
#include<algorithm>
#include <vector>
#include <iostream>
#include <cmath>
#include <time.h>
#include <stack>
using namespace std;

struct PriorityQueue{
private:
    vector<int> A;

    int PARENT(int i){
        return (i - 1)/ 2;
    }

    int LEFT(int i){
        return i*2 + 1;
    }

    int RIGHT(int i){
        return i*2 + 2;
    }

    void heapify_down(int i){
        int left = LEFT(i);
        int right = RIGHT(i);

        int largest = i;

        if(left < size() && A[left] > A[i]){
            largest = left;
        }

        if(right < size() && A[right] > A[largest]){
            largest = right;
        }

        if(largest != i){
            swap(A[i], A[largest]);
            heapify_down(largest);
        }
    }

    void heapify_up(int i){
        int parent = PARENT(i);
        if(parent >= 0 && A[i] > A[parent]){

            swap(A[i], A[parent]);
            heapify_up(parent);
        }
    }

public:

    unsigned int size() {
        return A.size();
    }

    bool empty(){
        return size() == 0;
    }

    void push(int key){
        A.push_back(key);

        int index = size() - 1;
        heapify_up(index);
    }

    void pop(){
        try{
            if(size() == 0){
                throw out_of_range("no element in heap");
            }else{
                A[0] = A.back();
                A.pop_back();

                heapify_down(0);
            }
        } catch(const out_of_range& oor){
            cout << "\n" << oor.what();
        }
    }


    int top(){
        try{
            if(size() == 0){
                throw out_of_range("no element in heap");
            }
            return A[0];

        } catch (const out_of_range& oor){
            cout << "\n" << oor.what();
        }
    }




};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    PriorityQueue pq;
    int n, type;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> type;
        if(type == 0){
            if(pq.size() == 0){
                cout << 0 << '\n';
            }else{
                cout << pq.top() << "\n";
                pq.pop();
            }
        }else{
            pq.push(type);
        }
    }
    return 0;
}









