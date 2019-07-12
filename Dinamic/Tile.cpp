//
//#include <iostream>
//#include <vector>
//#include "algorithm"
//#include "math.h"
//
//using namespace std;
//
//int **temp() {
//    int row = 3, col = 3;
//    int **arr = new int *[row]; // row 할당
//    // col 할당
//    for (int i = 0; i < row; i++) {
//        arr[i] = new int[col];
//    }
//
//    return arr;
//}
//
//int dp[1000001] = {1, 1, 2};
//
//int main() {
//    int n, zeroCount, temp, sum = 0;
//    bool isPrint;
//    scanf("%d", &n);
//    for (int i = 0; i < pow(2, n) - 1; i++) {
//        zeroCount = 0;
//        for (int j = 0; j < n; j++) {
//            if ((1 & (i >> j)) == 0) {
//                zeroCount++;
//            } else if (zeroCount % 2 != 0) {
//                break;
//            }
//        }
//        if (zeroCount % 2 == 0) {
//            sum++;
//            temp = i;
//            for (int k = 0; k < n; k++) {
//                if (temp & 1)
//                    printf("1");
//                else
//                    printf("0");
//                temp >>= 1;
//            }
//            printf("\n");
//        }
//    }
//    printf("%d", sum + 1);
//    return 0;
//}


#include <iostream>
#include <vector>
#include "algorithm"
#include "math.h"

using namespace std;

int arr[1000001] = {1, 1 ,2};
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 3; i <= n; i++){
        arr[i] = (arr[i-1] + arr[i-2]) %  15746;
    }
    printf("%d", arr[n]);
    return 0;
}

