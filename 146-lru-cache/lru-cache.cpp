class LRUCache {
public:
int cap;

    class Node{
        public:
            int key;
            int val;
            Node* next;
            Node* prev;
            Node(int key, int val){
                this->key = key;
                this->val = val;
            }

    };
    unordered_map<int, Node*> mp;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addNode(Node* node){
        
        node->prev=head;
        (head->next)->prev = node;
        node->next = head->next;
        head->next=node;
        
    }

    void delNode(Node* node){
        // Node* temp = node->prev;
        (node->prev)->next = node->next;
        (node->next)->prev = node->prev; 
    }
    int get(int key) {
        if(mp.count(key)){
            Node* node = mp[key];
            delNode(node);
            addNode(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            Node* node = mp[key];
            delNode(node);
            addNode(node);
            mp[key]->val = value;
            return;
        }
        if(mp.size()<cap){
            Node* node = new Node(key, value);
            addNode(node);
            mp[key] = node;
            return;
        }
        Node* temp = tail->prev;
        delNode(tail->prev);
        mp.erase(temp->key);
        Node* node = new Node(key, value);
        addNode(node);
        mp[key]=node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */