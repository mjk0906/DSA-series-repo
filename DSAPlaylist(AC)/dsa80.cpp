#include <iostream>
#include <vector> 
#include <queue>
#include <list>
using namespace std ;

class CircularQueue{
public:
    int f,r ;
    int currSize, cap ;
    int* arr ;

    CircularQueue(int size){
        cap = size ;
        f = 0 ;
        r = -1 ;
        currSize=0 ;
        arr = new int[cap] ;
    }

    void push(int val){
        if(currSize==cap){
            cout<<"FULL"<<endl ;
            return ;
        }
        r = (r+1)%cap ;
        arr[r] = val ;
        currSize++ ;
    }
    void pop(){
        if(empty()){
            cout<<"empty"<< endl ;
            return ;
        }
        f = (f+1)%cap;
        currSize-- ;
    }
    bool empty(){
        return currSize==0 ;
    }
    int front(){
        if(empty()){
            return -1 ;
        }
        return arr[f] ;
    }
};

int main(){
    CircularQueue cq(3) ;
    cq.push(1) ;
    cq.push(2) ;
    cq.push(3) ;
    cq.pop() ;
    //cq.push(4) ;
    while(!cq.empty()){
        cout<< cq.front() << " " ;
        cq.pop() ;
    }
    cout<<endl;
    return 0 ;
}

