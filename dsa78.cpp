class LRUCache {
public:
    class Node{
        public:
            int k , v ;
            Node* prev ;
            Node* next ;
            Node(int key, int val){
                v = val ;
                k = key ;
                prev = next = NULL ;
            }
    };
    Node* head = new Node(-1,-1) ;
    Node* tail = new Node(-1,-1) ;
    unordered_map<int,Node*> m ;
    int limit ;
    LRUCache(int capacity) {
        limit = capacity ; 
        head->next=tail ;
        tail->prev=head ;
    }
    void delNode(Node* oldNode){
        Node* oldNext = oldNode->next ;
        Node* oldPrev = oldNode->prev ;
        oldPrev->next = oldNext ;
        oldNext->prev = oldPrev ;
    }
    void addNode(Node* newNode){
        Node* oldNode = head->next ;

        newNode->next = oldNode ;
        newNode->prev = head ;

        head->next=newNode ;
        oldNode->prev = newNode ;
    }
    int get(int key) {
        if(m.find(key)==m.end()){
            return -1 ;
        }
        int ans = m[key]->v ;
        Node* ansNode = m[key] ;
        delNode(ansNode);
        m.erase(key) ;
        addNode(ansNode);
        m[key] = ansNode ;
        return ans ;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            Node* oldNode = m[key] ;
            delNode(oldNode);
            m.erase(key) ;
        }
        if(m.size()==limit){
            m.erase(tail->prev->k) ;
            delNode(tail->prev);
        }
        Node* newNode = new Node(key,value) ;
        addNode(newNode) ;
        m[key] = newNode ;
    }
}; //a hard problem go through the logic of code again and again what is the way of writing it 