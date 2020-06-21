#include"head.h"

class LRUCache
{
public:
    LRUCache(int capacity) : _cap(capacity) {}

    int get(int key)
    {
        auto iter=_map.find(key);
        if(iter==_map.end()) return -1;
        int val=iter->second->second;
        _list.erase(iter->second);
        _list.push_front(make_pair(key,val));
        _map[key]=_list.begin();
        return val;
    }

    void put(int key, int value)
    {
        auto iter=_map.find(key);
        if(iter!=_map.end()) _list.erase(iter->second);
        _list.push_front(make_pair(key,value));
        _map[key]=_list.begin();
        if(_list.size()>_cap){
            int key=_list.back().first;
            _map.erase(key);
            _list.pop_back();
        }
    }

private:
    int _cap;
    unordered_map<int,list<pair<int,int>>::iterator> _map;
    list<pair<int,int>> _list;
};

/**5
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */