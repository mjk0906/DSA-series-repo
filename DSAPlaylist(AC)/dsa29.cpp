#include <iostream>
#include <vector>
using namespace std ;

int main () {
    char str[10000] ;
    cout << "enter the question :" ;
    cin.getline >> str ;

    cout << str << endl ;
    return 0 ;
}
// cin ignores all the characters present after a space in between a sentence so we have to use cin.getline
