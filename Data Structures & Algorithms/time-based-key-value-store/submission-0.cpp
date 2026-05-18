class TimeMap {
vector<map<string, string>> store;
public:
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        if (timestamp >= store.size()) {
            store.resize(timestamp + 1);
        }
        store[timestamp].insert({key,value});
    }
    
    string get(string key, int timestamp) {
        if (timestamp >= store.size()) {
            timestamp = store.size() - 1;
        }
        if(store[timestamp].find(key)!= store[timestamp].end()){
            return store[timestamp].find(key)->second;
        }
        for(int i = timestamp; i>=0; i--){
            if(store[i].find(key)!= store[i].end()){
            return store[i].find(key)->second;
        }
       
        }
         return "";
    }
};
