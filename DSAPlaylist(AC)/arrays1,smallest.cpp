#include <iostream>
using namespace std ;

int main () {
    // printing the smallest value in an array 
    int nums[] = {15,46,75,-90,-110,56} ;
    int smallest = INT_MAX ;
    int size = 6 ;
    for (int i = 0 ; i<size ; i++){
        if (nums[i]<smallest) {
            smallest = nums[i] ;
        }
    }
    cout << "smallest = " << smallest << endl ;
    return 0 ;
}

