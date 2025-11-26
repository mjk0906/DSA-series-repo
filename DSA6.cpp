#include <iostream>
using namespace std ;




int checkPrime(int n) {

    if ( n<=1 ) 
    {
        cout << "Not prime"<< endl ;
    }

    bool isPrime = true ;
    for ( int i = 2 ; i*i <= n ; i ++)
    {
        if ( n % i == 0 )
        {
            isPrime = false ;
            break ;
        }
    }
    if (isPrime) 
    {
        cout << "Prime "<< endl ;
    }
    else 
    {
        cout << "Not prime " << endl ;
    }



return 0 ;
}
    
 


int main()
{
    checkPrime(47) ;
    return 0 ;

}




    







