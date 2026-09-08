/* Structure of linked list Node
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};*/

class myStack {
    
  public:
    Node* top ;
    int sizeofStack ;
    myStack() {
        // Initialize your data members
        sizeofStack = 0 ;
        top = NULL ;
    }

    bool isEmpty() {
        // check if the stack is empty
        if(top==NULL){
            return true ;
        }
        return false ;
    }

    void push(int x) {
        // Adds an element x at the top of the stack
        Node* newNode = new Node(x) ;
        newNode->next = top ;
        top = newNode ;
        sizeofStack++;
    }

    void pop() {
        // Removes the top element of the stack
        if(top==NULL){
            return ;
        }
        Node* temp = top ;
        top = top->next ;
        delete temp ;
        sizeofStack--;
        
    }

    int peek() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(top==NULL){
            return -1 ;
        }
        return top->data ;
    }

    int size() {
        // Returns the current size of the stack
        return sizeofStack ;
    }
};

//very easy, understand off