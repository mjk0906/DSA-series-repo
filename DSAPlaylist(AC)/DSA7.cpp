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



long binTodec(long n)
 {
    long ans = 0 ;
    long p = 1 ;
    while (n > 0) 
    {
        
        int rem = n%10 ;
        n = n/10 ;
        ans += rem*p ;
        p *= 2 ;
    }
    return ans ;
}

int main()
{
    //for(int i = 1 ; i<=10 ; i++)
    // {
    //     cout << decTobin(i) << endl;
    //}
    cout << binTodec (10110) << endl ;
    return 0 ;
}