#include <iostream> 
#include <list>
using namespace std ;

class Node{
public:
    int data;
    Node* next ;
    Node* prev ;
    Node(int val){
        data = val ;
        next=prev=NULL ;
    }
};
class Circularlist{
public:
    Node* head ;
    Node* tail ;
    Circularlist(){
        head=tail=NULL ;
    }
    void insertathead(int val){
        Node* newNode = new Node(val);
        if(tail==NULL){
            tail=head=newNode ;
            tail->next = head;
        }else{
            newNode->next=head;
            head=newNode ;
            tail->next = head ;
        }
    }
    void print(){
        Node* temp = head->next ;
        cout<< head->data <<  " -> " ;
        while(temp!=head){
            cout<<temp->data<< " -> " ;
            temp=temp->next ;
        }
        cout<<temp->data<<endl;
    }
    void IAT(int val){
        Node* newNode = new Node(val);
        if (head==NULL){
            head=tail=newNode ;
            tail->next=head ;
        }else{
            newNode->next=head ;
            tail->next=newNode;
            tail=newNode ;
        }
    }
};

int main(){
    Circularlist cll ;
    cll.insertathead(1);
    cll.insertathead(2);
    cll.insertathead(3);
    cll.insertathead(4);
    cll.insertathead(5);
    cll.IAT(6);
    cll.print();
}