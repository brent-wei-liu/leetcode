#include <iostream>
#include <unordered_map>
using namespace std;
class LRUCache{
public:
    struct triple{
        int older;
        int younger;
        int value;
    };

    bool debug;
    int capacity;
    unordered_map<int, triple> cache;  //key, next younger key, next older key, value
    int o_key;//oldest key, valid only if cache is non-empty
    int y_key;//youngest key, valid only if cache is non-empty
    LRUCache(int capacity) { //assume capacity>0
        this->capacity=capacity;
        cache.clear();
        debug=1;
    }

    void print(){
        if (cache.empty()) cout<<"Empty!"<<endl;
        else{
            int current_key=y_key;
            while (true){
                cout<<current_key<<':'<<cache[current_key].value<<' ';
                if (current_key==o_key) break;
                current_key=cache[current_key].older;
            }
            cout<<endl;
        }
    }

    int get(int key) {
        if (cache.count(key)>0){

            if (key!=y_key){  //need to update the ordering 
                if (key==o_key){  //accessed key is the oldest one
                    o_key=cache[key].younger;
                    cache[key].older=y_key;
                    cache[y_key].younger=key;
                    y_key=key;
                }
                else{
                    cache[cache[key].younger].older=cache[key].older;
                    cache[cache[key].older].younger=cache[key].younger;
                    cache[key].older=y_key;
                    cache[y_key].younger=key;
                    y_key=key;
                }
            }
            if (debug) print();
            return cache[key].value;
        }
        if (debug) print();
        return -1;
    }

    void set(int key, int value) {
        if (cache.empty()){
            o_key=key;
            y_key=key;
            cache[key].value=value;
            if (debug) print();
            return;
        }
        if (cache.count(key)>0){ //already present
            cache[key].value=value;  //update value
            bool temp_debug=debug;
            debug=0;
            get(key);
            debug=temp_debug;
        }else{
            cache[key].value=value;  //insert entry
            cache[key].older=y_key;
            cache[y_key].younger=key;
            y_key=key;
            if (cache.size()>capacity){ //delete the oldest one
                o_key=cache[o_key].younger;
                cache.erase(cache[o_key].older);
            }
        }
        if (debug) print();
    }
};
int main()
{
    LRUCache cache(4);
    
    return 0;
}
