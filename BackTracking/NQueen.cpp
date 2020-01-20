//N-Queens Problem.....Enter no. less than 15...because greater no. than this takes much time.
/** N-Queen -- Using 1D Array, backtracking
 *  N-Queen.cpp
 *
 *  Fall, 2011
 *
 *  Problem: N-Queen Problem
 *     The eight queens puzzle is the problem of placing eight chess queens on an 8�8 chessboard so
 *     that no two queens attack each other. Thus, a solution requires that no two queens share the same row,
 *	   column, or diagonal. The eight queens puzzle is an example of the more general n-queens problem of placing
 *	   n queens on an n�n chessboard, where solutions exist for all natural numbers n with the exception of 2 and 3.
 *
 *  For More Description & Example of Problem:
 *     Check Link: http://en.wikipedia.org/wiki/Eight_queens_puzzle
 *
 *  Input Format:
 *      Enter the value of N. i.e. Enter the number of Queens for which you want to find the number of solutions
 *
 *  OutPut Format:
 *      This program will output the total no. of Solutions possible for N Queens.
 *
 * @Compiler version on which Program is Last Run before uploading to Github: Dev-C++ 5.4.1, Date: 1st July, 2013
 * @author Gurpreet Singh
 */
#include <iostream>
#include<cstdlib>
#include <cmath>
using namespace std;

bool ok(int q[], int col){

    for(int i=0;i<col;i++){
        if((q[i] == q[col]) || (abs(q[col] - q[i]) == (col - i)))
        {   return false;
        }
    }
    return true;
}

void backtrack(int &col, int m, int n1){
    col--;

    if(col==-1){
        cout<<"There are "<<m<<" solutions of "<<n1<<" queens problem."<<endl;
        system("pause");
        exit(1);
    }
}


int main(){

    int n;
    cout<<"Enter the number of Queens for the solution: ";
    cin>>n;
    cout<<endl;
    int*  q = new int[n];
    int c=1,count=0;
    q[0]=0;
    //delete[]q;
    // from_backtrack keeps track if we need to reset the row to the
    // top of the current colum or not.

    bool from_backtrack=false;
    // The outer loop keep looking for solutions
    // The program terminates from function backtrack
    // when we are forced to backtack into column -1
    while(1){
        while(c<n){ //this loop goes across columns
            // if we just returned from backtrack, use current value of row
            // otherwise get ready to start at the top of this column
            if(!from_backtrack) // we did not just return from backtrack
                q[c]=-1;   //check here
            from_backtrack=false;
            while(q[c]<n){ // place queen in this column
                q[c]++;
                // if row=8, there is no valid square in this column
                // so backtrack and continue the loop in the previous column


                while(q[c]==n)
                { backtrack(c, count, n);
                    q[c]++;

                }
                //if this position is ok, place the queen
                // and move on (break) to the next column,
                // otherwise keep looking in this column

                if(ok(q, c))
                    break;

            }// while q[c]<8
            c++; // placed ok, move to the next column
        }//while(c<8)
        // one complete solution found, print it.
        //print(q); // board completed, print it out
        count++;

        backtrack(c, count, n);
        from_backtrack=true;
    }//while(1)

}//main method
