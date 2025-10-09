//pre processor directive
#include <iostream>
using namespace std ;

//main function 
int main() {
cout << "Jayant\nMalka " << "\n" ;

// the code without cout line is called as BOILERPLATE CODE

//variables are also called as identifiers in cpp language 

int age = 20 ;
cout << sizeof(age)<< "\n" ;
    
//type casting

float new_age = (float) age ;
cout << typeid(new_age).name() << endl ;
//how to take input from the user and store it in a variable
double price ;
cout << "enter the price of the game:";
cin >> price ;
cout << "the price of the previous game is "<< price << endl ;

// the ++ is a unary operator and is used to do increment by 1 to the same number 
age++;
cout << "the updated age is :" << age << endl ;





return 0 ;


}










