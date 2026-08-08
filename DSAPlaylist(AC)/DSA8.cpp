#include <iostream>
using namespace std ;

int check2power ()
{
    int n ;
    bool powerof2 = true ;
    cin >> n ;
    if ((n &(n-1)) == 0) {             //very logical, think and see ; 'this line holds a lot of meaning' 
        cout << "yes" << endl ;
        return powerof2 ;
    }
    else 
    {
        powerof2 = false ;
        cout << "no" << endl ;
        return powerof2 ;
    }
}

int main () {
    check2power() ;
}