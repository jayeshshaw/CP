

class Node{
    public:
    unordered_map<char, Node*> links;
    bool isLastChar=false;

    bool isPresent(char c){
        return links.find(c)!=links.end();
    } 
    ~Node() {
        for(auto it : links)
            delete it.second;
    }
};

class Trie {
private: 
    Node* start;

public:
    Trie() {
        start= new Node();
    }
    
    void insert(string word) {
        Node* n= start;
        for(char c: word){
            if(!n->isPresent(c)){
                n->links[c] = new Node();
            }
            n= n->links[c];
        }
        n->isLastChar=true;
    }
    
    bool search(string word) {
        Node* n= start;
        for(char c: word){
            if(!n->isPresent(c))return false;
            n=n->links[c];
        }
        return n->isLastChar;
    }
    
    bool startsWith(string prefix) {
        Node* n= start;
        for(char c: prefix){
            if(!n->isPresent(c))return false;
            n=n->links[c];
        }
        return 1;
    }
};
