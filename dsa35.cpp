#include <iostream>
#include <vector>
using namespace std ;

int diagsum(int matrixA[][4],int n){
    int diagsum = 0 ;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            if (i==j){
                diagsum+= matrixA[i][j] ;
            }
            else if (j==n-1-i){
                diagsum+= matrixA[i][j] ;
            }
        }
    }
    return diagsum ;
}

int main () {

    int matrix[4][4] = {{1,2,3,9},{2,3,5,1},{3,5,9,7},{8,7,4,0}} ;
    int n = 4 ;
    cout << diagsum(matrix , n) << endl ;
    //single loop wala aise karo 
    for (int i = 0 ; i<n ; i++){
        sum+= matrixA[i][i] ;
        if (i!=n-1-i){
            sum += matrix[i][n-1-i]; //this will make sure that in a n odd valued matrix there will not be ay repitition in adding the central term which occurs in both the diagonals 
        }
    }
}