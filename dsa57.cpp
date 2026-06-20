#include <iostream> 
#include <list> 
using namespace std;

class Node {
    public :
        int data;
        Node* next;

        Node(int val){
            data = val;
            next = NULL ; 
        }

};
 
class List{
    Node* head; 
    Node* tail;
    public:

        List() {
            head = tail = NULL ;
        }
    
        void push_front(int val) { //O(1)
            Node* newNode = new Node(val); //this is stored in heap memory to avoid vanishing of data after the function stack clears
            if(head==NULL){
                head=tail=newNode ;
                return ;
            }
            else{
                newNode->next = head ; //this stores the existing head before adding the value or the penultimate value of the newest added node ***
                head = newNode ; //now this is the latest added node in the list, updated head pointing towards it
                //note : only the head is updated everytime, therefore head always points to the latest added node but the tail always points to the first added node
            }
        }

        void push_back(int val){ //O(1)
            Node* newNode = new Node(val);
            if (head==NULL){
                head=tail=newNode ;
            }
            else{
                tail->next = newNode ; //this time value added at the back so the next pointer of the tail node updated to the newNode
                tail = newNode ; //after the updating the tail pointer is updated   
            }
        }
        void pop_front(){  //O(1)
            if (head==NULL){
                cout<<"linked list is empty"<<endl ;
                return ;
            }
            Node* temp = head ;
            head = head->next ;
            temp->next = NULL ;
            delete temp ;
        }
        void pop_back(){ //O(n) TC
            if(head==NULL){
                cout<<"LL is empty"<<endl;
                return ;
            }
            Node* temp = head ;
            while(temp->next!=tail){
                temp = temp->next ;
            }
            temp->next = NULL ;
            delete tail ;
            tail = temp ;
        }
        void insert(int val, int pos){ //O(n) TC
            if(pos<0){
                cout<<"Invalid pos"<<endl ;
                return ;
            }
            if(pos==0){
                push_front(val);
                return ;
            }
            Node* temp = head ;
            for(int i=0;i<pos-1;i++){
                temp=temp->next ;
            }
            if(temp==NULL){
                cout<<"invalid positon"<<endl;
                return ;
            }
            Node* newNode = new Node(val);
            newNode->next=temp->next ; //these are two key steps for the insert function 
            temp->next = newNode ;
            return ;
        }
        int search(int val){ //search function O(n)
            Node* temp = head ; 
            int idx = 0 ;
            while(temp!=NULL){
                if(temp->data==val){ //if data equal return
                    return idx ;
                }
                temp = temp->next ;
                idx++ ;
            }
            return -1 ; //if the given val is not found in the list
        }
        int middle(){
            Node* temp = head ;
            vector<Node*> pointers ;
            int size = 0;
            while(temp!=NULL){
                pointers.push_back(temp);
                temp = temp->next ;
                size++ ;
            }
            cout<< pointers[size/2]->data <<endl ;
            return pointers[size/2]->data;
        } //own written middle code is this 
        
        void printLL(){
            Node* temp = head ;
            while(temp!=NULL){
                cout<<temp->data << " " ; //function to print the whole linked list
                temp = temp->next ;
            }
            cout<<endl ;
            return;
        }
};

int main() {
    List ll ;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    cout<<ll.search(4)<<endl ;
    ll.middle() ;
    return 0;
} ;