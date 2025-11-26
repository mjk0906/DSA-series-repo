#include <iostream> 
using namespace std ;

int main () 
{
    char ch = 'A' ;
    for (int i=1 ; i<=4 ; i++) 
    {
        for (int j=1 ; j<=4 ; j++ )
        {
            cout << ch << ' ' ;
            ch= ch + 1 ;
        
        }
        cout << endl ;
    }
    cout << "------------------------"<< endl ;
    for (int k = 1; k<=5 ; k+=1)
    {
        char chy = 'A' ;
        for (int l=1 ; l<=k ; l++ )
        {
            cout << chy << ' ' ;
            chy +=1 ;
        }
        cout << endl ;

    }
    cout << "------------------------"<< endl ;
    for (int m=0 ; m<=4 ; m++)
    {   
        char chx = 'A' + m ;
        for (int l=0 ; l<m+1 ; l++)
        {
            cout<< chx << ' ' ; 
        }
       
        cout<< endl ;
    }
    cout << "------------------------"<< endl ;

    

    return 0 ;
}


