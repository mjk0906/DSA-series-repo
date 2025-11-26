#include <iostream>
using namespace std ;
int main() {
    int n = 20 ;

    for ( int i = 0 ; i< n ; i++) {
        for(int j = i+1 ; j>0 ; j--)
        {
            cout << j << ' ' ;
        }
        cout << endl ;
    }

    for ( int i = 0 ; i< n; i++)
    {
        for (int j = 0 ; j< n-i-1 ; j++)
        {
            cout << ' ' ;   
        }
        cout << '*' ;
        for ( int k = 0; k< 2*i-1 ; k++ )
        {
            cout << ' ' ;
        }
        if (i!=0)
        {
            cout << '*' ;
        }

        cout << endl ;
    }

    for ( int i = n-1 ; i>0 ; i--)
    {
        for ( int j = 0 ; j < n-i ; j++)
        {
            cout << ' ' ;
        }
        cout << '*' ;
        for ( int k = 0 ; k< 2*i-3 ; k++)
        {
            cout << ' ' ;
        }
        if (i!=1)
        {
            cout << '*' ;
        }
        cout << endl ;
    }


  





    


}