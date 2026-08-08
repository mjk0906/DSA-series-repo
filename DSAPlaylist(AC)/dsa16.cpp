#include <iostream>
#include <vector>
using namespace std ;
// basic code to get store and get the value of pointer of a variable created and stored
int main() {
    int a = 10 ;
    int b = 10 ;
    int * rar = &a ;
    int * rar2 = &b ;
    cout << rar << endl ;
    cout << rar2 << endl ;
} 

// pass by reference 

void changeA(int* ptr){
    *ptr = 20 ;
}
int main() {
    int a = 10 ;
    changeA(&a) ;
    cout << "the value is changed now, a=" << a << endl ;
    return 0 ;
}