class Node{
    public:
    int key, value;
    Node* prev;
    Node* next;
    Node(int _key, int _value){
        key=_key;
        value=_value;
    }
};
class LRUCache {
    Node* start;
    Node* end;
    int remainingSpace;

    unordered_map<int, Node*> keyMap;

    void joinPrevNext(Node* keyNode){
        Node* prevNode = keyNode->prev;
        Node* nextNode = keyNode->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }
    void makeMRU(Node* keyNode){
        Node* prevMRU = start->next;
        start->next=keyNode;
        keyNode->prev=start;
        keyNode->next=prevMRU;
        prevMRU->prev=keyNode;
    }
    void removeLRU(){
        Node* lru=end->prev;
        keyMap.erase(lru->key);
        joinPrevNext(lru);
        delete(lru);
    }
public:
    LRUCache(int capacity) {
        remainingSpace = capacity;
        start = new Node(0,0);
        end = new Node(0,0);
        start->next=end;
        end->prev=start;
    }
    
    int get(int key) {
        if(keyMap.find(key)==keyMap.end())return -1;
        
        Node* keyNode = keyMap[key];
        joinPrevNext(keyNode);
        makeMRU(keyNode);

        return keyNode->value;
    }
    
    void put(int key, int value) {
        Node* keyNode;
        if(keyMap.find(key)==keyMap.end()){
            if(remainingSpace==0){
                removeLRU();
                remainingSpace++;
            }
            keyNode = new Node(key, value);
            keyMap[key]=keyNode;
            remainingSpace--;
        }
        else{
            keyNode=keyMap[key];
            keyNode->value=value;
            joinPrevNext(keyNode);
        }
        makeMRU(keyNode);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
