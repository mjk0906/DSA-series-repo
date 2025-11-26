#include <iostream>
using namespace std ;

int decTobin(int n ) 
{
    int ans = 0 ;
    int p = 1 ;
    while ( n > 0 )
    {
        int rem = n%2 ;
        n = n/2 ;
        ans = ans + rem*p ;
        p = p*10 ;
        
    }
    
    return ans ;

}

int main()
{
    for(int i = 1 ; i<=10 ; i++)
    {
        cout << decTobin(i) << endl;
        
    }
    return 0 ;
}

