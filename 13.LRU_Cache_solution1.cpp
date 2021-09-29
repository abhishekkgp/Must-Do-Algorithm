/*
PROBLEM:
-------
Design a data structure that works like a LRU Cache. 
Here cap denotes the capacity of the cache and Q denotes the number of queries. 
Query can be of two types:
SET x y : sets the value of the key x with value y
GET x : gets the key of x if present else returns -1.
The LRUCache class has two methods get() and set() which are defined as follows.
get(key)   : returns the value of the key if it already exists in the cache otherwise returns -1.
set(key, value) : if the key is already present, update its value. If not present, add the key-value pair to the cache. 
If the cache reaches its capacity it should invalidate the least recently used item before inserting the new item.
In the constructor of the clas the capacity of the cache should be intitialized.
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------  
SOLUTION-1:- USING LIST(Doubly linked list STL)
--------
 */

 #include <bits/stdc++.h>
using namespace std;

// design the class in the most optimal way
class LRUCache
{
    private:
        list<int> st;
        unordered_map<int, list<int>::iterator>  mp;
        unordered_map<int, int> values;
        int size;
    public:
    /* Constructor for initializing the cache capacity with the given value. */
    LRUCache(int cap){
        size = cap;
    }
    
    /* Function to return value corresponding to the key. */
    int get(int key){
        /* If we didn't get the element return -1 */
        if(mp.find(key)==mp.end()){
            return -1;
        }
        /* If the element is present :
            (i) Erase that from the map as well as from list
            (ii) Insert at the front and insert value to the map
            (iii) Return the value from the map
        */
        st.erase(mp[key]);
        mp.erase(key);
        st.push_front(key);
        mp[key] = st.begin();
        return values[key];
    }
    
    /* Function for storing key-value pair. */
    void set(int key, int value)
    {
        /* If the key is not present in the map :
            (i) Check whether the list size is full or not
            (ii) if full then remove the last element delete 
                 from the map as well delete the value of that
            (iii) Insert element at the beginning and update
                 the value.
                 
            If the key is present in the map:
            (i) delete key from the map as well delete the value of that
            (ii) Insert element at the beginning of list and update
                 the value.
        */
        if(mp.find(key) == mp.end()){
            if(st.size() == size){
                int x = st.back();
                st.pop_back();
                values.erase(x);
                mp.erase(x);
            }
        }
        else{
            st.erase(mp[key]);
            mp.erase(key);
            values.erase(key);
        }
        st.push_front(key);
        mp[key] = st.begin();
        values[key] = value;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends
