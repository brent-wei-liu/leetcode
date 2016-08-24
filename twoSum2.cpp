class TwoSum {
private:
    unordered_map<int, int> hash;
public:
    // Add the number to an internal data structure.
    void add(int number) {
        hash[number]++;
    }

    // Find if there exists any pair of numbers which sum is equal to the value.
    bool find(int value) {
        for(auto &kv : hash) {
            kv.second --;
            if(hash.count(value - kv.first)>0 && hash[value - kv.first]>0) {
                kv.second ++;
                return true;
            }
            kv.second ++;
        }
        return false;
    }
};

