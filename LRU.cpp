/*LRU Cache

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.*/

class LRUCache {
public:
    inline static int M[10001];
    inline static int16_t L[10002][2];
    int cap, size = 0;
    const int NONE = 10001;
    int head = NONE, tail = NONE;
    
    LRUCache(int capacity) : cap(capacity) {
        memset(M, 0xff, sizeof M);
    }
    
    inline void erase(int key) {
        const int pre = L[key][0];
        const int nxt = L[key][1];
        L[pre][1] = nxt;
        L[nxt][0] = pre;
        if (head == key) head = nxt;
        if (tail == key) tail = pre;
    }
    
    inline void push_front(int key) {
        L[key][0] = NONE;
        L[key][1] = head;
        L[head][0] = key;
        head = key;
        if (tail == NONE)
            tail = key;
    }
    
    inline int pop_back() {
        int ret = tail;
        tail = L[tail][0];
        L[tail][1] = NONE;
        if (tail == NONE)
            head = NONE;
        return ret;
    }
    
    int get(int key) {
        if (M[key] == -1) return -1;
        erase(key);
        push_front(key);
        return M[key];
    }
    
    void put(int key, int value) {
        if (M[key] != -1) {
            erase(key);
        } else {
            if (size == cap) {
                int poped = pop_back();
                M[poped] = -1;
                size -= 1;
            }
            size += 1;
        }
        push_front(key);
        M[key] = value;
    }
};