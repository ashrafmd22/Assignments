/*Insert Delete GetRandom O(1)

Implement the RandomizedSet class:

RandomizedSet() Initializes the RandomizedSet object.
bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.
You must implement the functions of the class such that each function works in average O(1) time complexity.*/

class RandomizedSet {
    private:
        vector<int> nums; //randomized set
        unordered_map<int,int> m; //hashmap to map key(index in nums) and value
    public:
        RandomizedSet() {
            
        }
        
        bool insert(int val) {
            if (m.find(val) != m.end()) {return false;}
            nums.emplace_back(val);
            m[val] = nums.size() -1;
            return true;
        }
        
        bool remove(int val) {
            if (m.find(val) == m.end()){return false;}
            int last = nums.back();
            m[last] = m[val]; //change the key(index) of last to old_key(index) of val in m(map)
            nums[m[val]] = last; //change value at index_of_val to 'last' in nums
            nums.pop_back();
            m.erase(val);
            return true;
        }
        
        int getRandom() {
            return nums[rand() % nums.size()];
        }
};