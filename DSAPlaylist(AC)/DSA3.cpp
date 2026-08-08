#include <iostream> 
using namespace std ;
int main() {

// the nested loop and pattern printing 
    int n = 5 ;
    for ( int i = 1 ; i<=n ; i++) 
    {
        for(int j = 1; j<=n ; j++)
        {
            cout <<  j ; 
        }
        cout << endl ;

    }
// the pattern where alphabes are printed instead of numbers 
    for (int i = 1 ; i<=n ; i++)
    {
        char ch = 'A' ;
        for( int l=1 ; l<=n ; l++)
        {
            cout << ch ;
            ch = ch + 1 ;

        }
        cout << endl ;
   }
   
   int num = 10 ;

   for(int m = 1; m < 4 ; m++)
   {
        for(int p=1 ; p<4 ; p++)
        {
            cout << num << ' ';
            num++ ;
        }
        cout << endl ;

   }

   
   cout << "the matrix has been printed" << endl ;
return 0 ;

    

}

