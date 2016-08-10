//TLE
class LRUCache{
public:
    vector<pair<int, int>> q;
    int cap;
    
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        for(int i = 0; i < q.size(); ++i) {
            if(q[i].first == key) {
                setOrder(q, i);
                return q.back().second;
            }
        }
        return -1;
    }
    
    void set(int key, int value) {
        for(int i = 0; i < q.size(); ++i) {
            if(q[i].first == key) {
                q[i].second = value;
                setOrder(q, i);
                return;
            }
        }
        if(q.size() == cap) q.erase(q.begin());
        q.push_back(make_pair(key, value));
    }
    
    void setOrder(vector<pair<int, int>>& q, int i) {
        q.push_back(q[i]);
        q.erase(q.begin()+i);        
    }
};


class LRUCache{
public:
    list<pair<int, int>> l;
    map<int, list<pair<int, int>>::iterator> m;
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(m.find(key) != m.end()) {
            l.splice(l.begin(), l, m[key]);
            return m[key]->second;
        }
        return -1;
    }
    
    void set(int key, int value) {
        if(m.find(key) != m.end()) l.erase(m[key]);
        l.push_front(make_pair(key, value));
        m[key] = l.begin();
        if(m.size() > cap) {
            m.erase(l.back().first);
            l.pop_back();
        }
    }
};