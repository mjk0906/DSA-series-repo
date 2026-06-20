#include <iostream>
#include <list> 
using namespace std ;


class Node{
public:
    int data ;
    Node* prev ;
    Node* next ;
    Node(int val){
        data = val ;
        prev = next = NULL ;
    }   
};
class DoublyList{
    Node* head ;
    Node* tail ;
public:
    DoublyList(){
        head=tail=NULL ;
    }
    void pushfront(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            newNode->next = head ;
            head->prev = newNode ;
            head=newNode ;
        }
    }
    void popfront(){
        Node* temp = head ;
        head=head->next ;
        if(head!=NULL){
            head->prev=NULL ;
            temp->next=NULL ;
        }
        delete temp ; //deleted the allocated memory of the pointer

    }
    void print(){
        Node* temp = head ;
        while(temp!=NULL){
            cout << temp->data << " <=> " ;
            temp = temp->next ;
        }
        cout<<"NULL\n";
    }
};
int main(){
    DoublyList dll ;
    dll.pushfront(1);
    dll.pushfront(2);
    dll.popfront() ;
    dll.print();   
    return 0 ;
}
