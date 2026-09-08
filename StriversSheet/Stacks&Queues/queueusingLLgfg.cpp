class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class myQueue {

  public:
    Node* front ;
    Node* rear ;
    int siize ;
    myQueue() {
        // Initialize your data members
        front = NULL ;
        rear = NULL ;
        siize = 0 ;
    }

    bool isEmpty() {
        // check if the queue is empty
        return siize==0 ;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue
        Node* newNode = new Node(x) ;
        if(siize==0){
            front = newNode ;
            rear=newNode ;
        }else{
            rear->next = newNode ;
            rear = newNode ;
        }
        siize++ ;
    }

    void dequeue() {
        // Removes the front element of the queue
        if(siize==0){
            return ;
        }
        Node* temp = front ;
        front = front->next ;
        delete temp ;
        siize--;
        if(siize==0){
            rear=NULL ;
        }
        
    }

    int getFront() {
        // Returns the front element of the queue
        // If queue is empty, return -1
        if(siize==0){
            return -1;
        }
        return front->data ;
    }

    int size() {
        // Returns the current size of the queue.
        return siize ;
    }
};

//easy, minute logics keep revising LL